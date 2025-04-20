#include <bits/stdc++.h>
using namespace std;

struct Node {
    int g, mn, cnt;
};

inline Node combine(const Node &a, const Node &b) {
    Node r;
    r.g   = gcd(a.g, b.g);
    r.mn  = min(a.mn, b.mn);
    r.cnt = (a.mn==r.mn ? a.cnt : 0) + (b.mn==r.mn ? b.cnt : 0);
    return r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    int base = 1;
    while(base < n) base <<= 1;
    vector<Node> seg(2*base, {0, INT_MAX, 0});

    for(int i = 0; i < n; i++){
        int x; 
        cin >> x;
        seg[base + i] = {x, x, 1};
    }
    for(int i = base - 1; i > 0; --i){
        seg[i] = combine(seg[2*i], seg[2*i+1]);
    }

    int q; 
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int L = l + base - 1, R = r + base - 1;
        Node leftRes = {0, INT_MAX, 0}, rightRes = {0, INT_MAX, 0};

        while(L <= R){
            if(L & 1) leftRes  = combine(leftRes, seg[L++]);
            if(!(R & 1)) rightRes = combine(seg[R--], rightRes);
            L >>= 1; R >>= 1;
        }
        Node ans = combine(leftRes, rightRes);
        int len = r - l + 1;
        cout << (ans.g == ans.mn ? len - ans.cnt : len) << "\n";
    }
    return 0;
}
