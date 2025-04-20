#include <bits/stdc++.h>
using namespace std;
using piiii = pair<int,int>;
const int mx = 100000;
const int wow = 1e9;

int n, m;
vector<int> adj[mx+1];
bool done[mx+1];
int subs[mx+1];
int cenParent[mx+1];
vector<piiii> centDist[mx+1]; 
int best[mx+1];

void dfs_size(int u, int p) {
           subs[u] = 1;
                for (int v: adj[u]) if (v != p && !done[v]) {
        dfs_size(v, u);
                  subs[u] += subs[v];
    }
 }

int      cento(int u, int p, int total) {
    for (int v: adj[u]) if (v != p && !done[v]) {
                if (subs[v] > total/2)
            return cento(v, u, total);
    }
    return u;
 }

    void record(int u, int p, int depth, int c) {
            centDist[u].emplace_back(c, depth);
      for (int v: adj[u]) if (v != p && !done[v]) {
        record(v, u, depth+1, c);
     }
  }

void build(int u, int p) {
    dfs_size(u, -1);
    int c = cento(u, -1, subs[u]);
        done[c] = true;
    cenParent[c] = p;
    // idk what i am doing here
    // but it works so i am not touching it
             record(c, -1, 0, c);
     for (int v: adj[c]) if (!done[v]) {
                 build(v, c);
    }
}

void updating(int u) {
    for (auto &pr: centDist[u]) {
        int c = pr.first, d = pr.second;
        best[c] = min(best[c], d);
    }
}

int queries(int u) {
    int res = wow
;
    for (auto &pr: centDist[u]) {
        int c = pr.first, d = pr.second;
        res = min(res, best[c] + d);
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i < n; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // building itttttttt
    build(1, 0);

        for (int i = 1; i <= n; i++) best[i] = wow;

    updating(1);

    while (m--) {
        int t, v;
    cin >> t >> v;
          if (t == 1) {
             updating(v);
        } else {
            cout << queries
          (v) << "\n";
        }
    }
    return 0;
}