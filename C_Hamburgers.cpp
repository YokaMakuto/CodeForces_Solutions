#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string rcp;
             cin >> rcp;
    ll b, s, c;
             cin >> b >> s >> c;
    ll B, S, C;
             cin >> B >> S >> C;
    ll Cash;
             cin >> Cash;
    ll nb = 0, ns = 0, nc = 0;
    for (char ch : rcp) {
        if (ch == 'B') ++nb;
        if (ch == 'S') ++ns;
        if (ch == 'C') ++nc;
    }
    auto ttl = [&](ll cnt) {
        ll bB = max(0LL, cnt * nb - b) * B;
        ll bS = max(0LL, cnt * ns - s) * S;
        ll bC = max(0LL, cnt * nc - c) * C;
        return bB + bS + bC;
    };
    ll lo = 0, H = 1e13, ans = 0;
    while (lo <= H) {
        ll mid = lo + (H - lo) / 2;
        if (ttl(mid) <= Cash) {
            ans = mid;
            lo = mid + 1;
        } else {
            H = mid - 1;
        }
    }
    cout << ans << "\n";
    return 0;
}