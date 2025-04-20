#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, t;
    cin >> n >> t;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0, ans = 0;
    int l = 0;
    for (int r = 0; r < n; ++r) {
        sum += a[r];
        while (sum > t) {
            sum -= a[l++];
        }
        ans = max(ans, (long long)(r - l + 1));
    }

    cout << ans << "\n";
    return 0;
}