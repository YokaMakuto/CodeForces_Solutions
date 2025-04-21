// I love my kitty 'NI' and my n <3 <3 <3

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long r, g, b;
    cin >> r >> g >> b;
    long long sum = r + g + b;
    long long mx = max({r, g, b});
    long long ans = min(sum / 3, sum - mx);
    cout << ans << "\n";

    return 0;
}