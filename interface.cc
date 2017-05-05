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
		void set_value( int new_value ) { i
			if ( new_value > 255 ) throw_runtime_error("BAD INPUT");
			value = new_value; }
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
	Normal x, y;
	
	while(true) {

		// Case 1:  Set Variables
		// Will require a data structure to keep track of variables + values
		char input = cin.peek();

		if ( isalpha(input) ) { 		// If user inputs a letter
			cin >> str;					// Write to string
			if (!cin) user_error();		
			if ( str == "LET" ) {	 	// Case 1:  Writing a variable
				cin >> var_name >> equal >> a;
				if (!cin) user_error();
				if ( equal != '=' ) user_error(); // If no '=', run ERROR
				variable[var_name] = a;
			}
			else if ( str == "QUIT" ) exit(0); 	// Case 3:  User enters QUIT

			else if ( str.size() == 1 && isalpha(str.at(0)) ) { 	// Case 2:  Writing algebraic expression, starting with a variable
				// First, set a char to str.at(0) 
				// Then, search the map for the char
				// If the char doesn't exit, run user_error();
				// Set Number x.set_value( map[char] );
			}
		}
		
		else if ( isdigit(input.at(0) ) { 		// Case 2:  Writing algebraic expression, starting with a number
				cin >> a;
				if ( a > 255 ) user_error();  // If value entered is above 255, run ERROR
				// Number x.set_value(a);
		}
			else user_error(); // If none of the above, run ERROR
		
	}

	return 0;
}

# csci41_calc
