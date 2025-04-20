#include <bits/stdc++.h>
using namespace std;

struct Node {
    int matched;
    int open;   
    int close;  
    Node(): matched(0), open(0), close(0) {}
};

Node combine(const Node &a, const Node &b) {
    Node c;
    int t = min(a.open, b.close);
    c.matched = a.matched + b.matched + t;
    c.open    = a.open + b.open - t;
    c.close   = a.close + b.close - t;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int N = 1;
    while (N < n) N <<= 1;

    vector<Node> seg(2 * N);


    for (int i = 0; i < n; i++) {
        if (s[i] == '(') seg[N + i].open = 1;
        else              seg[N + i].close = 1;
    }
  
    for (int i = N - 1; i >= 1; i--) {
        seg[i] = combine(seg[2*i], seg[2*i + 1]);
    }

    int m;
    cin >> m;
    while (m--) {
        int l, r;
        cin >> l >> r;

        int left = l - 1 + N;
        int right = r - 1 + N;
        Node resL, resR;

        while (left <= right) {
            if (left & 1) resL = combine(resL, seg[left++]);
            if (!(right & 1)) resR = combine(seg[right--], resR);
            left >>= 1;
            right >>= 1;
        }
        Node ans = combine(resL, resR);
        cout << ans.matched * 2 << "\n";
    }

    return 0;
}