#include <ctype.h>
#include <iostream>
#include <string>
#include <map>
#include <stdexcept>
#include <exception>

using namespace std;


class Number {		// Class to hold 8 bit numbers
	private:
		int value;
	public:
		int get_value() { return value; }
		void set_value( int new_value ) { value = new_value; }
};


void die() { 		// Die function
	cout << "BAD INPUT\n";
	exit(0);
}
	
int main() {		
	string str, command, check;
	map <char, int> var;
	char var_name, operation, equal;
	int a, b;
//	Number x, y;
	int x, y;	

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
				if (!cin) die();
				auto search = var.find(var_name);
				if ( search == var.end() ) cout << die(); // If variable doesn't exist, run ERROR.
				else {
				//	y.set_value(var[var_name]);
					y = var[var_name];
					var[var_name]+= 1; // Increments value
				}
			}
			else if ( isdigit(input) ) {
				cin >> b; 
				if (!cin) die();
				if ( b < 0 || b > 255 ) die();
				else 
					y = b;
					//y.set_value(b);
			}
			if ( operation == '+' ) x = x + y;
				//x.set_value( x.get_value() + y.get_value() );
			else if ( operation == '-' ) 
				x = x - y;
				//x.set_value( x.get_value() - y.get_value() );
			else if ( operation == '*' );
			else if ( operation == '/' );
			else if ( operation == '%' );
			else if ( operation == '^' );
			else die();  // No other operations possible
			input = cin.peek(); // Checks for end of input... if end, output answer
			if ( input == '\n' ) {
				cout << x << endl;
				//cout << x.get_value() << endl;
				break;
			}
		}
	}
	else if ( isalpha(input) ) { // If given a letter, will check for either setting variable or starting equation
		cin >> str;
		if ( !cin ) die();
		if ( str == "LET" ) { // If LET, set variable
			cin >> var_name >> equal >> a;
			if ( !cin ) die();
			auto search = var.find(var_name);
			if ( search != var.end() ) die();  // If variable already exists, run ERROR
			if ( a < 0 || a > 255 ) die();
			else var[var_name] = a;
		}
		else if ( str == "QUIT" ) die(); // QUIT
		else if ( str.size() == 1 ) {	// If variable, will set x.
			var_name = str.at(0);
			auto search = var.find(var_name);
			if ( search == var.end() ) die(); // If variable does not exist, ERROR
			else { 
				x = var[var_name];
				//x.set_value(var[var_name]);
				var[var_name]++;
			}
		}
		else die();
	}
	else if ( isdigit(input) ) { // If given a digit, will set x.
		cin >> a;
		if ( a < 0 || a > 255 ) die();
		else 
			x = a;
			//x.set_value(a);
	}
	else die();
}

}
