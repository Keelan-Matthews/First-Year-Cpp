#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int main() {
	string name;

	for (int i = 0; i < 3; i++) {
		cout << "Enter your name: ";
		getline(cin, name);
		cout << "Howdy: " << setfill('*') << setw(7) << name << endl; 
	}
	return 0;
}
