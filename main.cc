//Elsie Cortez, Omar Radwan, Christian Vaughn, Alex Ku, Jese Hernandez, Kristian Erl
//Calculator function

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

int add( Number x, Number y ) {   //add function
	int num = x.get_value() + y.get_value();
	return num;
}

int subtract ( Number x, Number y ) { //subtract function
	int num = x.get_value() - y.get_value();
	return num;
}

int multiply ( Number num1, Number num2 ) {  //multiplication function
	return num1.get_value() * num2.get_value();
}

float division ( Number x, Number y ) {   //division function, checks for 0 later
	float result = x.get_value() / y.get_value();
	return result;
}

int modulate ( Number x, Number y ) { //modulus, checks for 0
	if ( !y.get_value() ) {
		cout << "INVALID INPUT!\n";
		exit(0);
	}
	else return x.get_value() % y.get_value();
}

float exponate ( Number x, Number y ) { //exponentiation
	return pow(x.get_value(), y.get_value());
}
	
void die() { 		// Die function
	cout << "INVALID INPUT!\n";
	exit(0);
}
	
int main() {		
  string str, command, check; //basic things needed for calculator
  map <char, int> var; //keeps track of variables
	char var_name, operation, equal;
	int a, b;
	Number x, y;	//objects we will pass to functions

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
				if ( search == var.end() ) die(); // If variable doesn't exist, run ERROR.
				else {
					b = var[var_name];
					y.set_value(b);
					var[var_name]+= 1; // Increments value
					if ( var[var_name] > 255 ) die();
				}
			}
			else if ( isdigit(input) ) {
				cin >> b; 
				if (!cin) die(); 
					y.set_value(b);
			}
			else die();
			if ( operation == '+' ) x.set_value(add(x, y));
			else if ( operation == '-' ) x.set_value(subtract(x, y));
			else if ( operation == '*' ) x.set_value(multiply(x, y));
			else if ( operation == '/' && y.get_value() != 0 ) x.set_value(division(x, y));
			else if ( operation == '%' ) x.set_value(modulate(x, y));
			else if ( operation == '^' ) {
				if ( x.get_value() == 0 && y.get_value() == 0 ) die();
				else x.set_value(exponate(x, y));
			}
			else die();  // No other operations possible
			input = cin.peek(); // Checks for end of input... if end, output answer
			if ( input == '\n' ) {
				cout << x.get_value() << endl;
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
			if ( equal != '=' ) die();
			auto search = var.find(var_name);
			if ( search != var.end() ) die();
			if ( a < 0 || a > 255 ) die();
			else var[var_name] = a;
		}
		else if ( str == "QUIT" ) exit(0); // QUIT
		else if ( str.size() == 1 ) {	// If variable, will set x.
			var_name = str.at(0);
			auto search = var.find(var_name);
			if ( search == var.end() ) die(); // If variable does not exist, ERROR
			else {
				a = var[var_name];
				x.set_value(a);
				var[var_name]++;
				if ( var[var_name] > 255 ) die();
				input = cin.peek(); // Checks for end of input... if end, output answer
				if ( input == '\n' ) {
					cout << x.get_value() << endl;
				}
			}
		}
		else die();
	}
	else if ( isdigit(input) ) { // If given a digit, will set x.
		cin >> a;
		x.set_value(a);
		input = cin.peek(); // Checks for end of input... if end, output answer
		if ( input == '\n' ) {
			cout << x.get_value() << endl;
		}
	}
	else exit(0);
}

}
