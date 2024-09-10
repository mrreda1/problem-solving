#include <iostream>

using namespace std;

int main () {
    int size, x;
    cin >> size;
    int person[size];
    for(int i = 1; i <= size; i++) {
        cin >> x;
        person[x - 1] = i;
    }
    for(int i = 0; i < size; i++)
        cout << person[i] << ' ';
}
