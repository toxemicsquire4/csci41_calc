#include <iostream>
#include <map>
#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

class Normal {
	protected: 
		int value;
	public:
		int get_value() { return value; }
		void set_value( int new_value ) { 
			value = new_value; 
		}
};
		
/* class Variable::public Normal {
	private:
		int8_t var_val;
	public:
		int get_value() { 
			int fake_value = var_val;
			var_val+=1;
			return fake_value;
		}
		void set_value( int8_t new_var ) { var_val = new_var; }
}; */

void user_error() {				// Error function for user input
	cout << "BAD INPUT\n";
	exit(0);
}

int main() {
	char operation;
	int8_t a, b;
	
	map<char, int8_t> variable;
	string str;
	char var_name, equal;
	Normal x, y, z;
	
	while(true) {
		cin >> ws; // Eats whitespace

		char input = cin.peek();

		if ( input == '+' || input == '-' || input == '*' || input == '/' || input == '%' || input == '^' ) { // Continuation of algebra
			cin >> operation;
			cin >> ws;
			char input = cin.peek();
			if ( isalpha(input) ) {
				cin >> var_name;
				auto search = variable.find(var_name);		// Search map for char
				if ( search != variable.end() ) user_error();	// If char doesn't exist, run ERROR
				else  y.set_value( map[var_name] );		// Otherwise, set Number y to value of char
				
			else if ( isdigit(input) ) {	
				cin >> b;
				if ( b > 255 ) throw_runtime_error("BAD INPUT");	// If input is over 255, run ERROR
				y.set_value(b);
			}
			if ( operation == '+' ) { x.set_value(multiply(x, y)); }
			if ( cin.eof() ) cout << x.get_value();		// If end of user input, output answer
		}
		else if ( isalpha(input) ) { 		// If user inputs a letter
			cin >> str;					// Write to string
			if (!cin) user_error();		
			if ( str == "LET" ) {	 	// Case 1:  Writing a variable
				cin >> var_name >> equal >> a;
				if ( a > 255 ) throw_runtime_error("BAD INPUT");
				if (!cin) user_error();
				if ( equal != '=' ) user_error(); // If no '=', run ERROR
				variable[var_name] = a;
			}
			else if ( str == "QUIT" ) exit(0); 	// Case 3:  User enters QUIT

			else if ( str.size() == 1 && isalpha(str.at(0)) ) { 	// Case 2:  Writing algebraic expression, starting with a variable
				char var = str.at(0);		// Set char to single char of str
				auto search = variable.find(var);	// Search map for char
				if ( search != variable.end() ) user_error();	// If char doesn't exist, run ERROR
				else  x.set_value( map[var] );		// Otherwise, set Number x to value of char
			}
			else user_error();
		}
		
		else if ( isdigit(input.at(0) ) { 		// Case 2:  Writing algebraic expression, starting with a number
				cin >> a;
				if ( a > 255 ) throw_runtime_error("BAD INPUT");
				x.set_value(a);
		}
		
		else user_error(); 
		
	}

	return 0;
}

# csci41_calc
