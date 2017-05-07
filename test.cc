#include <ctype.h>
#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	string str;
	map <char, int> var;
	char var_name, operation, equal;
	int a, b, x, y;

while (true) {
	cin >> ws;
	char input = cin.peek();
	if ( input == '+' || input == '-' || operation == '=' ) {
		while (true) {	
			cin >> operation;
			if ( operation == '=' ) {
				cout << "The answer is: " <<  x << endl;
				break;
			}
			cin >> ws;
			input = cin.peek();
			if ( isalpha(input) ) {
				cin >> var_name;
				auto search = var.find(var_name);
				if ( search == var.end() ) exit(0);
				else y = var[var_name];
			}
			else if ( isdigit(input) ) {
				cin >> b;
				y = b;
				cout << "Made y = " << b << endl;
			}
			if ( operation == '+' ) x = x + y;
			else if ( operation == '-' ) x = x - y;
		}
	}
	else if ( isalpha(input) ) {
		cin >> str;
		if ( str == "LET" ) {
			cin >> var_name >> equal >> a;
			var[var_name] = a;
			cout << "Made " << var_name << " = " << a << endl;
		}
		else if ( str == "QUIT" ) exit(0);
		else if ( str.size() == 1 ) {
			var_name = str.at(0);
			auto search = var.find(var_name);
			if ( search == var.end() ) exit(0);
			else x = var[var_name];
			cout << var_name << " = " << a << endl;
		}
	}
	else if ( isdigit(input) ) {
		cin >> a;
		x = a;
		cout << "Made x = " << a << endl;
	}

}

	return 0;
}
// Yeah
