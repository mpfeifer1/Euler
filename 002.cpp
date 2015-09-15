#include <iostream>

using namespace std;

int main() {
	const int max = 4000000;
	int a = 0;
	int b = 1;
	int sum = 0;

	cout << "Fibonacci: " << a << endl;

	while(a < max) {
		a += b;
		swap(a, b);
		if(a%2 == 0) {
			sum += a;
			cout << "Sum:       " << sum << endl;
		}
		cout << "Fibonacci: " << a << endl;
	}
}
