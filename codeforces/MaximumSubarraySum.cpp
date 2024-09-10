#include <climits>
#include <iostream>

int main() {
	unsigned n, i;
	std::cin >> n;
	long long a[n + 1] = {0}, x, t_max = LLONG_MIN, max = LLONG_MIN, mmax = 0,
					min = 0;
	for (i = 1; i <= n; i++) {
		std::cin >> x;
		if (t_max < x)
			t_max = x;
		a[i] = x + a[i - 1];
	}
	if (t_max <= 0) {
		std::cout << t_max;
		return 0;
	}
	for (long long j = 1; j <= n; j++) {
		if (a[j] < min) {
			if (mmax < max - min)
				mmax = max - min;
			min = a[j];
			max = LLONG_MIN;
		} else if (max < a[j])
			max = a[j];
	}
	if (mmax < max - min)
		mmax = max - min;
	std::cout << mmax;
}
