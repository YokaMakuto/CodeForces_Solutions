#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Seg {
    struct Node { 
        int mn, cnt, lazy; 
    };
    int n;
    vector<Node> st;
    Seg(int _n): n(_n), st(4*n+4) {
            build(1,1,n);
    }
    void build(int p, int l, int r) {
        st[p].lazy = 0;
        if(l == r) {
            st[p].mn = 0;
            st[p].cnt = 1;
            return;
        }
        int m = (l+r)>>1;
        build(p<<1, l, m);
    build(p<<1|1, m+1, r);
        pull(p);
          }
         void apply(int p, int v) {
        st[p].mn += v;
        st[p].lazy += v;
       }
       void push(int p) {
          int v = st[p].lazy;
            if(v) {
            apply(p<<1, v);
                   apply(p<<1|1, v);
            st[p].lazy = 0;
                }
                 }
      void pull(int p) {
          int l = p<<1, r = p<<1|1;
                 st[p].mn = min(st[l].mn, st[r].mn);
           st[p].cnt = 0;
        if(st[p].mn == st[l].mn) st[p].cnt += st[l].cnt;
        if(st[p].mn == st[r].mn) st[p].cnt += st[r].cnt;
    }
    void upd(int p, int l, int r, int i, int j, int v) {
        if(i > r || j < l) return;
        if(i <= l && r <= j) {
             apply(p, v);
               return;
                                            }
         push(p);
         int m = (l+r)>>1;
          upd(p<<1, l, m, i, j, v);
         upd(p<<1|1, m+1, r, i, j, v);
         pull(p);
    }  
  void update(int i, int j, int v) {
    if(i>j) return;
        upd(1,1,n,i,j,v);
    }
    pair<int,int> query(int p, int l, int r, int i, int j) {
        if(i>r || j<l) return {INT_MAX, 0};
        if(i<=l && r<=j) return { st[p].mn, st[p].cnt };
        push(p);
          int m = (l+r)>>1;
           auto L = query(p<<1, l, m, i, j);
             auto R = query(p<<1|1, m+1, r, i, j);
        pair<int,int> res;
        res.first = min(L.first, R.first);
             res.second = 0;
         if(res.first == L.first) res.second += L.second;
         if(res.first == R.first) res.second += R.second;
        return res;
    }
    pair<int,int> query(int i, int j) {
        if(i>j) return {INT_MAX,0};
        return query(1,1,n,i,j);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if(!(cin>>n))return 0;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        int r,c;
        cin>>r>>c;
        a[r] = c;
    }
    Seg st(n);
    ll ans = 0;
    vector<pair<int,int>> st_max, st_min;
    st_max.reserve(n+2);
    st_min.reserve(n+2);
    st_max.push_back({n+1, 1});
    st_min.push_back({0, 1});

    for(int r=1; r<=n; r++){
        st.update(1, r, -1);
        st.update(r, r, +1);
        int last = r;
        while(!st_max.empty() && st_max.back().first < a[r]){
            auto [val, start] = st_max.back();
            st_max.pop_back();
            int L = start, R = last-1;
            st.update(L, R, (a[r] - val));
            last = start;
        }
        st_max.push_back({a[r], last});

        int last2 = r;
        while(!st_min.empty() && st_min.back().first > a[r]){
            auto [val, start] = st_min.back();
            st_min.pop_back();
            int L = start, R = last2-1;
            st.update(L, R, (val - a[r]));
            last2 = start;
        }
        st_min.push_back({a[r], last2});

        auto qr = st.query(1, r);
        if(qr.first == 0) ans += qr.second;
    }

    cout<<ans<<"\n";
    return 0;
}