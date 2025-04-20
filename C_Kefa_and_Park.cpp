#include <bits/stdc++.h>
using namespace std;
using piiii = pair<int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >>  n >> m;
    vector<int> kitty(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> kitty[i];
    }

    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> donee(n+1, false);
    queue<piiii> q;
    // i love my kitty i wish she sees this solution one day
    if (kitty[1] <= m) {
        q.push({1, kitty[1]});
        donee[1] = true;
    }

    int result = 0;
    while (!q.empty()) {
        auto [u, cns] = q.front(); q.pop();
        bool lf = (u != 1 && adj[u].size() == 1);
        if (lf) {
            result++;
            continue;
        }
        for (int v : adj[u]) {
    if (donee[v]) continue;
            int nxt = kitty[v] ? cns + 1 : 0;
         if (nxt > m) continue;
             donee[v] = true;
            q.push({v, nxt});
        }
    }

    cout << result <<endl;
    return 0;
}