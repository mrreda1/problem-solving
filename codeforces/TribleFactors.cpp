#include <iostream>
#include <unistd.h>

using namespace std;
bool checknum(long long num) {
	if (!num)
		return true;
	if (num % 10)
		return false;
	num /= 10;

	long long r[2] = {num % 10, (num % 100) / 10};
	if ((r[0] & 3 || r[1] & 1) && !(!(r[0] & 1) && r[0] & 3 && r[1] & 1)) {
		return false;
	}

	long sum = 0;
	while (num) {
		sum += num % 10;
		num /= 10;
	}

	if (sum % 9)
		return false;
	return true;
}
int main() {
	for (long i = 0; i < 1e8; i++) {
		if (!(i % 360)) {
			if (!checknum(i)) {
				cout << "oops";
				return 0;
			}
			continue;
		}
		if (checknum(i)) {
			cout << "oops";
			return 0;
		}
	}
	cout << "nice!";
}
