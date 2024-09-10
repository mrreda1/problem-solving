#include <iostream>
#include <map>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	std::string un;
	std::cin >> n;
	std::map<std::string, unsigned> users;
	while (n--) {
		std::cin >> un;
		if (users.find(un) == users.end()) {
			users[un] = 1;
			std::cout << "OK\n";
		} else {
			std::cout << un << users[un]++ << '\n';
		}
	}
}
