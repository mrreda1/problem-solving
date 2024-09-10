#include <iostream>
#include <map>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, q;
    map<string, string> servers;
    cin >> n >> q;
    string name, ip;
    while(n--) {
        cin >> name >> ip;
        ip += ';';
        servers[ip] = name;
    }
    while(q--) {
        cin >> name >> ip;
        cout << name << ' ' << ip << ' ' << '#' << servers[ip] << '\n';
    }
}
