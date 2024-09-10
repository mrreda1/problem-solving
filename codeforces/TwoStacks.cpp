#include <iostream>
#include <vector>

using namespace std;

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int sum = 0, cnt = 0, i = 0, j = 0, a_size = a.size(), b_size = b.size(), size;
    vector<int>* r;
    while(sum <= maxSum && i < a_size && j < b_size) {
        if(a[i] >= b[j]) sum += a[i++];
        else sum += b[j++];
    }
    if(sum <= maxSum) {
        if(i < a_size) r = &a;
        else r = &b, i = j;
        size = (*r).size();
    }
    return cnt;
}
