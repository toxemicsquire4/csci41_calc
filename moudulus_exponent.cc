#include <iostream>
#include <cmath>
using namespace std;

int modulate(Normal& x, Normal& y){
	if(!y.get_value()) { //If the second number is 0, input is invalid
		cout << "Invalid Input!\n";
		return 0; //Replace this with a die function, or whatever will be used for error handling
	}
	else return x.value()%y.get_value();
}

float exponate(Normal& x, Normal& y){
		//No errors to check for
		return pow(x.get_value(),y.get_value());	
}
