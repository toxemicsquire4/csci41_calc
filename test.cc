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
	bool solve = true;

while (true) {
	cin >> ws;
	char input = cin.peek();
	if ( input == '+' || input == '-' ) {
		while (true) {	
			cin >> operation;
			if ( operation == '=' ) {
				cout << x << endl;
				break;
			}
			cin >> ws;
			input = cin.peek();
			if ( isalpha(input) ) {
				cin >> var_name;
				auto search = var.find(var_name);
				if ( search == var.end() ) exit(0);
				else {
					y = var[var_name];
					var[var_name]+= 1;
				}
			}
			else if ( isdigit(input) ) {
				cin >> b;
				y = b;
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
		}
		else if ( str == "QUIT" ) exit(0);
		else if ( str.size() == 1 ) {
			var_name = str.at(0);
			auto search = var.find(var_name);
			if ( search == var.end() ) exit(0);
			else { 
				x = var[var_name];
				var[var_name]++;
			}
		}
	}
	else if ( isdigit(input) ) {
		cin >> a;
		x = a;
	}

}

	return 0;
}
