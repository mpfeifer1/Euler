#include <iostream>

using namespace std;

int main() {
	long int num = 600851475143;
	long int maxFactor = 1;
	for(int i = 2; i <= num; ++i) {
		if(num % i == 0) {
			if (i > maxFactor) {
				maxFactor = i;
			}
			cout << "Factor:     " << i << endl;
			num /= i;
			i--;
		}
	}
	cout << "Max Factor: " << maxFactor << endl;
}
