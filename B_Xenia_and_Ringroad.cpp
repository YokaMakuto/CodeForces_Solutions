#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    long long current = 1, time = 0;
    for (long long i = 0; i < m; i++) {
        long long a;
        cin >> a;
        if (a >= current) {
            time += a - current;
        } else {
            time += n - (current - a);
        }
        current = a;
    }
    cout << time << "\n";
    return 0;
}