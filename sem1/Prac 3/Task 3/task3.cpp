#include <iostream>
#include<cstdlib>
using namespace std;
int main() {
	unsigned int studentnum, seed = 14;
	const int MIN_VALUE = 10, MAX_VALUE = 99;
	srand(seed);

	for (int i = 0; i < 2; i++){
		cout << "Enter your student number: ";
		cin >> studentnum;

		if (studentnum % 2 > 0) {
			cout << studentnum << " is really excited for COS 132!" << endl;
		}
		else {
			cout << (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE << " is ready to take on COS 132!" << endl;
		}
	}

	return 0;
}
