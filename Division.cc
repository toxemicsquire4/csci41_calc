#include <iostream>
using namespace std;
//deleted the old version

//This is the working code, or it should be
float division(Number& x, Number& y){ //changed from Normal to Number
    if (y.get_value() == 0) user_error();
    float result = x.get_value()/y.get_value();
    return result;
}
