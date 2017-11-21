// Calculator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <cctype>
using namespace std;
enum Token_value
{
	NAME, NUMBER, END, KEYWORD,
	PLUS = '+', MINUS = '-', MUL = '*', DIV = '/',
	PRINT = ';', ASSIGN = '=', LP = '(', RP = ')',
};



Token_value curr_tok = PRINT;
map<string, double> table;
map<string, string> tableOfFunc;
double numer_value;
string string_value;
istream* input;
int no_of_errors;
double error(const string s) {
	no_of_errors++;
	cerr << "error: " << s << '\n';
	return 1;
}

double expr(bool get);
Token_value get_token();

double prim(bool get)
{
	if (get) get_token();

	switch (curr_tok)
	{
	case NUMBER:
	{
		double v = numer_value;
		get_token();
		return v;
	}
	case NAME:
	{
		if (tableOfFunc.count(string_value))
		{
			cout << "find func with name " << string_value;
			istream* buf = input;
			input = new istringstream(tableOfFunc[string_value]);
			double v = expr(true);
			input = buf;
			get_token();
			return v;
		}
		double& v = table[string_value];
		if (get_token() == ASSIGN) v = expr(true);
		return v;
	}
	case KEYWORD:
	{
		if (string_value._Equal("func"))
		{
			if (get_token() != NAME)
				return error("wrong func name");
			string& v = tableOfFunc[string_value];
			char ch;
			while ((*input).get(ch) && (ch != '\n' && ch != ';'))
			{
				v.push_back(ch);
			}
			cout << "Func " << string_value << " created with body '" << v << "'\n";
			return 0;
		}
		return error("unknown KEYWORD");
	}
	case MINUS:
		return -prim(true);
	case LP:
	{
		double e = expr(true);
		if (curr_tok != RP) return error("')' expected");
		get_token();
		return e;
	}

	default:
		return error("primary expected");
	}
}


double term(bool get)
{
	double left = prim(get);

	for(;;)
		switch (curr_tok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true)) {
				left /= d;
				break;
			}
			return error( "divide by 0" );
		default:
			return left;
		}
}

double expr(bool get)
{
	double left = term(get);

	for (;;)
	{
		switch (curr_tok)
		{
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}

Token_value get_token()
{
	char ch;

	do
	{
		if (!(*input).get(ch)) return curr_tok = END;
	} while (ch != '\n' && isspace(ch));
	cout << "get_token of " << ch << "\n";
	switch (ch) {
	case 0:
		return curr_tok = END;
	case ';':
	case '\n':
		return curr_tok = PRINT;
	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return curr_tok = Token_value(ch);
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		(*input).putback(ch);
		(*input) >> numer_value;
		return curr_tok = NUMBER;
	default:
		if (isalpha(ch))
		{
			string_value = ch;
			while ((*input).get(ch) && isalnum(ch))
				string_value.push_back(ch);
			(*input).putback(ch);
			if (string_value._Equal("func"))
				return curr_tok = KEYWORD;
			return curr_tok = NAME;
		}
		error("bad token");
			return curr_tok = PRINT;
	}
}


int main(int argc, char* argv[])
{
	switch (argc)
	{
	case 1:
		input = &cin;
		break;
	case 2:
		input = new istringstream(argv[1]);
		break;
	default: 
		error("too many arguments");
		return 1;
	}

	table["pi"] = 3.1415926535897932385;
	table["e"] = 2.7182818284590452354;

	while (*input)
	{
		get_token();
		if (curr_tok == END) break;
		if (curr_tok == PRINT) continue;
		cout << expr(false) << '\n';
	}
	if (input != &cin) delete input;

	system("Pause");
    return no_of_errors;
}

