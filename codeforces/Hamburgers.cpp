#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int main() {
	string ham;
	long long freq[3] = {0}, mn, ratio, sum;
	long long n[3], p[3], money, burgers = 0;
	vector<pair<long long, long long>> specs;

	// input
	cin >> ham;
	cin >> n[0] >> n[1] >> n[2];
	cin >> p[0] >> p[1] >> p[2];
	cin >> money;

	// count number of specs
	for (char c : ham) {
		switch (c) {
			case 'B':
				freq[0]++;
				break;
			case 'S':
				freq[1]++;
				break;
			case 'C':
				freq[2]++;
		}
	}

	// push specs spec_money and spec_cost
	for (int i = 0; i < 3; i++) {
		if (freq[i]) {
			specs.push_back({n[i] * p[i], freq[i] * p[i]});
		}
	}

	while (true) {
		sum = mn = 0;
		for (auto spec = specs.begin(); spec != specs.end(); spec++) {
			ratio = spec->first / spec->second;
			if (ratio) {
				mn = (mn) ? (min(mn, ratio)) : (ratio);
			} else {
				money += spec->first;
				spec->first = 0;
			}
		}
		for (auto spec = specs.begin(); spec != specs.end(); spec++) {
			if (spec->first) {
				spec->first -= mn * spec->second;
			} else {
				sum += spec->second;
			}
		}
		if (sum * mn > money || !mn) {
			break;
		}
		burgers += mn;
        money -= mn * sum;
	}
	burgers += money / sum;
	cout << burgers;
}
