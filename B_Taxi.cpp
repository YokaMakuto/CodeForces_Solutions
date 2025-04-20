#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cnt(5, 0);
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        cnt[s]++;
    }

    int taxis = 0;
   
    taxis += cnt[4];


    taxis += cnt[3];
    cnt[1] = max(0, cnt[1] - cnt[3]);

    taxis += cnt[2] / 2;
    cnt[2] %= 2;

    if (cnt[2] == 1) {
        taxis += 1;
        cnt[1] = max(0, cnt[1] - 2);
    }

    if (cnt[1] > 0) {
        taxis += (cnt[1] + 3) / 4;
    }

    cout << taxis << "\n";
    return 0;
}