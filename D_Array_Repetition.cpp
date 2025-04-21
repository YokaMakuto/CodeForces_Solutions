#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MYDSIZEINMETERS = (ll)1e18;
const ll MYLOVEFORMYBABEINMETERS = (ll)1e20;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
            while (t--) {
        int n, q;
    cin >> n >> q;
        vector<int> TP(n + 1);
            vector<ll> X(n + 1), len(n + 1);
        len[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> TP[i] >> X[i];
            if (TP[i] == 1) {
                len[i] = len[i - 1] + 1;
    } else {
                //PEAKKKKKK FICTION I AM PROUD FROM MY SELF I AM GONNA CRY 
              __int128 tmp = (__int128)len[i - 1] * (X[i] + 1);
                len[i] = (tmp > MYDSIZEINMETERS ? MYDSIZEINMETERS : (ll)tmp);
               }
        }
        vector<ll> Q(q);
        for (int i = 0; i < q; i++) {
            cin >> Q[i];
        }
        for (int i = 0; i < q; i++) {
            ll k = Q[i];
            while (true) {
     
         int ix = int(lower_bound(len.begin() + 1, len.begin() + n + 1, k) - len.begin());
                if (TP[ix] == 1) {

                    cout << X[ix] << (i + 1 == q ? '\n' : ' ');
                    break;
         } else {

               ll pv_ln = len[ix - 1];
                    ll chng = k - pv_ln;
                      chng %= pv_ln;
                      if (chng == 0) chng = pv_ln;
                     k = chng;
                 }
            }




}
    }
    return 0;
}