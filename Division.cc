#include <iostream> //Do NOT USE, LEGACY, please use main.cc
using namespace std;

//This is the working code, or it should be
float division(Number& x, Number& y){ //changed from Normal to Number
    float result = x.get_value()/y.get_value(); //divides the Number&x value by the Number&y value
    return result; //just like it says, it returns the resulting number of the equation
}
// notes
