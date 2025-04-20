#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n;
    cin >> n;
    int d = to_string(n).length();
    long long ans = 0;
    long long p = 1;
    for (int i = 1; i < d; ++i) {
        ans += 9LL * p * i;
        p *= 10;
    }
    ans += (n - p + 1) * d;
    cout << ans << "\n";
    return 0;
}