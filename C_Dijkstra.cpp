#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = LLONG_MAX;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    vector<ll> dist(n + 1, INF);
    vector<int> prv(n + 1, -1);
    dist[1] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
    pq.emplace(0, 1);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        if (u == n) break;
        for (auto &e : adj[u]) {
            int v = e.first, w = e.second;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                prv[v] = u;
                pq.emplace(dist[v], v);
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << "\n";
        return 0;
    }

    vector<int> tri9;
 for (int v = n; v != -1; v = prv[v])
      tri9.push_back(v);
    reverse(tri9.begin(), tri9.end());
  for (int x : tri9)
      cout << x << " ";
 cout << "\n";

    return 0;
}