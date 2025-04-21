#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000;

int cnt2_[1005][1005], cnt5_[1005][1005];
int dp2[1005][1005], dp5[1005][1005];
char par2[1005][1005], par5[1005][1005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int zero_i = -1, zero_j = -1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            long long x;
            cin >> x;
            if (x == 0) {
                zero_i = i;
                zero_j = j;
                cnt2_[i][j] = cnt5_[i][j] = INF;
            } else {
                int c2 = 0, c5 = 0;
                long long t = x;
                while ((t & 1) == 0) { c2++; t >>= 1; }
                while (t % 5 == 0) { c5++; t /= 5; }
                cnt2_[i][j] = c2;
                cnt5_[i][j] = c5;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp2[i][j] = dp5[i][j] = INF;
        }
    }
    dp2[1][1] = cnt2_[1][1];
    dp5[1][1] = cnt5_[1][1];


    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            if (i > 1 && dp2[i-1][j] + cnt2_[i][j] < dp2[i][j]) {
                dp2[i][j] = dp2[i-1][j] + cnt2_[i][j];
                par2[i][j] = 'D';
            }
            if (j > 1 && dp2[i][j-1] + cnt2_[i][j] < dp2[i][j]) {
                dp2[i][j] = dp2[i][j-1] + cnt2_[i][j];
                par2[i][j] = 'R';
            }
            if (i > 1 && dp5[i-1][j] + cnt5_[i][j] < dp5[i][j]) {
                dp5[i][j] = dp5[i-1][j] + cnt5_[i][j];
                par5[i][j] = 'D';
            }
            if (j > 1 && dp5[i][j-1] + cnt5_[i][j] < dp5[i][j]) {
                dp5[i][j] = dp5[i][j-1] + cnt5_[i][j];
                par5[i][j] = 'R';
            }
        }
    }

    int best2 = dp2[n][n];
    int best5 = dp5[n][n];
    int ans = min(best2, best5);
    if (zero_i != -1 && ans > 1) {
        cout << 1 << "\n";
        string path;
        path.append(zero_i - 1, 'D');
        path.append(zero_j - 1, 'R');
        path.append(n - zero_i, 'D');
        path.append(n - zero_j, 'R');
        cout << path << "\n";
    } else {
        cout << ans << "\n";
        string path;
        int i = n, j = n;
        bool use2 = (best2 < best5);
        while (i > 1 || j > 1) {
            char c = use2 ? par2[i][j] : par5[i][j];
            path.push_back(c);
            if (c == 'D') i--;
            else j--;
        }
        reverse(path.begin(), path.end());
        cout << path << "\n";
    }
    return 0;
}