#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> diffs(n);
        for (int i = 0; i < n; i++) {
            ll a;
            cin >> a;
            diffs[i] = a - (i + 1);
        }
        sort(diffs.begin(), diffs.end());

        ll ans = 0;
        ll cnt = 1;
        for (int i = 1; i < n; i++) {
            if (diffs[i] == diffs[i-1]) {
                cnt++;
            } else {
                ans += cnt * (cnt - 1) / 2;
                cnt = 1;
            }
        }
        ans += cnt * (cnt - 1) / 2;
        cout << ans << "\n";
    }

    return 0;
}