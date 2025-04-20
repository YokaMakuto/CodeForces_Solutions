#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a, tre;

void build(int nd, int l, int r, int lvl) {
    if (l == r) {
        tre[nd] = a[l];
    } else {
        int mid = (l + r) >> 1;
        build(nd<<1,     l,    mid, lvl-1);
        build(nd<<1|1, mid+1,   r,   lvl-1);
        if (lvl & 1)
            tre[nd] = tre[nd<<1] | tre[nd<<1|1];
        else
            tre[nd] = tre[nd<<1] ^ tre[nd<<1|1];
    }
}

void updt(int nd, int l, int r, int pos, int val, int lvl) {
    if (l == r) {
        tre[nd] = val;
    } else {
        int mid = (l + r) >> 1;
        if (pos <= mid)
            updt(nd<<1, l, mid, pos, val, lvl-1);
        else
            updt(nd<<1|1, mid+1, r, pos, val, lvl-1);
        if (lvl & 1)
            tre[nd] = tre[nd<<1] | tre[nd<<1|1];
        else
            tre[nd] = tre[nd<<1] ^ tre[nd<<1|1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    int N = 1 << n;
    a.resize(N);
    for (int i = 0; i < N; i++) 
        cin >> a[i];

    tre.assign(4*N, 0);
    build(1, 0, N-1, n);

    while (m--) {
        int p, x;
        cin >> p >> x;
        --p;
        updt(1, 0, N-1, p, x, n);
         cout << tre[1] << "\n";
    }

    return 0;
}
