#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        unordered_map<long long, long long> cnt;
        cnt.reserve(n * 2);
        cnt[0] = 1;

        long long curr = 0, ans = 0;
        for (char c : s) {
            curr += (c - '0' - 1);
            ans  += cnt[curr];
            cnt[curr]++;
        }

        cout << ans << "\n";
    }

    return 0;
}