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
		
class Variable::public Normal {
	private:
		int8_t var_val;
	public:
		int get_value() { 
			int fake_value = var_val;
			var_val+=1;
			return fake_value;
		}
		void set_value( int8_t new_var ) { var_val = new_var; }
};

void user_error() {				// Error function for user input
	cout << "BAD INPUT\n";
	exit(0);
}

int main() {
	char operation;
	int8_t x, y;
	map<char, int8_t> variable;
	string str;
	char var_name, equal;
	Normal a, b;
	
	while(true) {

		// Case 1:  Set Variables
		// Will require a data structure to keep track of variables + values
		char input = cin.peek();

		if ( isalpha(input) ) { 		// If user inputs a letter
			cin >> str;					// Write to string
			if (!cin) user_error();		
			if ( str == "LET" ) {	 	// Case 1:  Writing a variable
				cin >> var_name >> equal >> x;
				if (!cin) user_error();
				if ( equal != '=' ) user_error(); // If no '=', run ERROR
				variable[var_name] = x;
			}
			else if ( str.size() == 1 && isalpha(str.at(0)) ) { 	// Case 2:  Writing algebraic expression, starting with a variable
				// First, set a char to str.at(0) 
				// Then, search the map for the char
				// Set Number x.set_value( map[char] );
			}
		}
		else if ( isdigit(input.at(0) ) {
			cin >> x;
		}
		// Case 3:  Quit
		
/*		cin >> x >> operation >> y;
		if ( x > 255 || y >> 255 ) user_error();			// If Normal x or Normal y are given to be greater than 255, run ERROR
		if (!cin) user_error();								// If invalid input, run ERROR
		if (!isdigit(x) || !isdigit(y)) user_error(); 		// If digit for x or y is not given, run ERROR 
		if ( cin == EOF ) user_error();  					// If file ends early, run ERROR	
		if ( operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%' ) 
				user_error(); 								// If no operation given, run ERROR
		
		if ( x == 'q' ) break; 								// If quit command given, break out of loop
		
		else{												// This is me, guessing about how the operations work :S		
			if ( operation == '+' ) z = add(x, y);
			else if ( operation == '-' ) z = subtract(x, y);
			else if ( operation == '*' ) z = multiply(x, y);
			else if ( operation == '/' ) z = divide(x, y);
			else if ( operation == '%' ) z = modulus(x, y);
			cout << z << endl;
		}
	}
*/
	return 0;
}

