#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int ops = 0;
    while (m > n) {
        if (m % 2 == 0) {
            m /= 2;
        } else {
            m++;
        }
        ops++;
    }
    ops += (n - m);
    cout << ops << "\n";
    return 0;
}