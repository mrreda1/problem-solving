#include <iostream>
#include <map>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    map<string, bool> chk;
    int i, n;
    cin >> n;
    string chats[n];
    for (i = 0; i < n; i++)
        cin >> chats[i];
    while (n--) {
        if(chk.find(chats[n]) == chk.end()) {
            cout << chats[n] << '\n';
            chk[chats[n]] = true;
        }
    }
}
