#include <iostream>
#include <string>
using namespace std;
int main() {
	///Declare your first set of variables here
	string st = "programming is fun";
	char x = 'X';
	int a = 75, b = 29;
	bool b1 = true, b2 = false;
	const double cnst = 1337.42;

	cout<<x<<" comes after W in the alphabet"<<endl;
	cout<<"The sum of sixty and fifteen: "<<a<<endl;
	cout<<"The multiplication of fourteen and a half and two: "<<b<<endl;
	cout<<"Learning "<<st<<endl;
	cout<<b1<<" is the value of True"<<endl;
	cout<<b2<<" is the value of False"<<endl;
	cout<<"The constant has a value of "<<cnst<<endl;

	//Declare your second set of variables here
	int A = 14, B, C, D = 31;

	B = A*D;
	C = D/A;
	A = A+1;
	D = D-2;

	cout<<A<<endl;
	cout<<B<<endl;
	cout<<C<<endl;
	cout<<D<<endl;
	cout<<B+C<<endl;

	return 0;
}
