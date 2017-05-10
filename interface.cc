#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <exception>
#include <cmath>

using namespace std;


class Number {		// Class to hold 8 bit numbers
	private:
		int value;
	public:
		int get_value() { return value; }
		void set_value( int new_value ) { value = new_value; }
};

int add( Number x, Number y ) {
	return x.get_value() + y.get_value();
}

int subtract ( Number x, Number y ) {
	return x.get_value() - y.get_value();
}

void user_error() { 		// Die function
	cout << "INVALID INPUT!\n";
	exit(0);
}
	
int main() {		
	string str, command, check;
	map <char, int> var;
	char var_name, operation, equal;
	int a, b;
	Number x, y;	

while (true) {
	cin >> ws;
	char input = cin.peek();  // Checks the next char
	if ( input == '+' || input == '-' || input == '*' || input == '/' || input == '%' || input == '^' ) { // If char is an operation, enters solution loop
		while (true) {	
			cin >> operation;
			cin >> ws;
			input = cin.peek();
			if ( isalpha(input) ) {	 // If variable, will set y.
				cin >> var_name;
				if (!cin) user_error();
				auto search = var.find(var_name);
				if ( search == var.end() ) user_error(); // If variable doesn't exist, run ERROR.
				else {
					b = var[var_name];
					y.set_value(b);
					var[var_name]+= 1; // Increments value
				}
			}
			else if ( isdigit(input) ) {
				cin >> b; 
				if (!cin) user_error(); 
					y.set_value(b);
			}
			else user_error();
			if ( operation == '+' ) add(x, y);
			else if ( operation == '-' ) subtract(x, y);
			else if ( operation == '*' ) multiply(x, y);
			else if ( operation == '/' && y.get_value() != 0 ) division(x, y);
			else if ( operation == '%' ) modulate(x, y);
			else if ( operation == '^' ) {
				if ( x.get_value == 0 && y.get_value == 0 ) user_error();
				else exponate(x, y);
			}
			else user_error();  // No other operations possible
			input = cin.peek(); // Checks for end of input... if end, output answer
			if ( input == '\n' ) {
				cout << x.get_value() << endl;
				break;
			}
		}
	}
	else if ( isalpha(input) ) { // If given a letter, will check for either setting variable or starting equation
		cin >> str;
		if ( !cin ) user_error();
		if ( str == "LET" ) { // If LET, set variable
			cin >> var_name >> equal >> a;
			if ( !cin ) user_error();
			if ( equal != '=' ) user_error();
			auto search = var.find(var_name);
			if ( search != var.end() ) user_error();
			if ( a < 0 || a > 255 ) user_error();
			else var[var_name] = a;
		}
		else if ( str == "QUIT" ) exit(0); // QUIT
		else if ( str.size() == 1 ) {	// If variable, will set x.
			var_name = str.at(0);
			auto search = var.find(var_name);
			if ( search == var.end() ) user_error(); // If variable does not exist, ERROR
			else {
				a = var[var_name];
				x.set_value(a);
				var[var_name]++;
				input = cin.peek(); // Checks for end of input... if end, output answer
				if ( input == '\n' ) {
					cout << x.get_value() << endl;
				}
			}
		}
		else user_error();
	}
	else if ( isdigit(input) ) { // If given a digit, will set x.
		cin >> a;
		x.set_value(a);
	}
	else exit(0);
}

}
