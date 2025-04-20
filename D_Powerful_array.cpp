#include <bits/stdc++.h>
using namespace std;
using ll = long long;
struct Query {
    int l, r, idx, block;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t;
    cin >> n >> t;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int block_size = max(1, (int)(sqrt(n)));
    vector<Query> qs(t);
    for (int i = 0; i < t; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].idx = i;
        qs[i].block = qs[i].l / block_size;
    }

    sort(qs.begin(), qs.end(), [&](const Query &A, const Query &B) {
        if (A.block != B.block)
            return A.block < B.block;
        if (A.block & 1)
            return A.r > B.r;
        else
            return A.r < B.r;
    });

    const int A_MAX = 1000000;
    vector<int> cnt(A_MAX + 1, 0);
    vector<ll> ans(t);
    ll curPower = 0;

    auto add = [&](int pos) {
        int x = a[pos];
        ll c = cnt[x];
        curPower += (2 * c + 1) * (ll)x;
        cnt[x]++;
    };

    auto remove = [&](int pos) {
        int x = a[pos];
        ll c = cnt[x];
        curPower += (-2 * c + 1) * (ll)x;
        cnt[x]--;
    };

    int curL = 1, curR = 0;
    for (auto &q : qs) {
        int L = q.l, R = q.r;
        while (curL > L) add(--curL);
        while (curR < R) add(++curR);
        while (curL < L) remove(curL++);
        while (curR > R) remove(curR--);
        ans[q.idx] = curPower;
    }

    for (int i = 0; i < t; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}