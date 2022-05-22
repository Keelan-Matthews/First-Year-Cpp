#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main() {
	double x, y;

	cout << "Enter a value of x: ";
	cin >> x;
	y = cos(pow(x,2)) / (5+2*cos(x)) + sin(pow(x,2)) / (5*M_PI) + tan(x) / (cos(x)+sin(x));
	cout << "The answer is: " << setprecision(5) << showpoint << fixed << y << endl;
	return 0;
}
