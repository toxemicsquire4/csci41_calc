#include <iostream>
using namespace std;

//old wrong version, ignore this
/*int main() {
    double x, y, result;
    cout << "Enter a number: " << endl;
    cin >> x;
    cout << "Enter the number you'll divide the first number by: " << endl;
    cin >> y;

    result = x/y;
    cout << x << " divided by " << y << " equals " << result << endl;
    return 0;
}*/

//This is the working code, or it should be
float division(Normal& x, Normal& y){
    if (y.get_value() == 0) user_error();
    float result = x.get_value()/y.get_value();
    return result;
}
