#include <iostream>
#include <map>

using namespace std;
int main () {
    map<string, int> user;
    string req;
    int n;
    cin >> n;
    while(n--) {
        cin >> req;
        if (user.find(req) == user.end()) {
            cout << "OK";
            user[req] = 1;
        } else { 
            cout << req << user[req]++;
        } cout << '\n';
    }
}
