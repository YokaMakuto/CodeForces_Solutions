#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'A' && s[i+1] == 'B') {
            for (int j = i + 2; j + 1 < n; ++j) {
                if (s[j] == 'B' && s[j+1] == 'A') {
                    cout << "YES\n";
                    return 0;
                }
            }
            break;
        }
    }
    for (int i = 0; i + 1 < n; ++i) {
        if (s[i] == 'B' && s[i+1] == 'A') {
            for (int j = i + 2; j + 1 < n; ++j) {
                if (s[j] == 'A' && s[j+1] == 'B') {
                    cout << "YES\n";
                    return 0;
                }
            }
            break;
        }
    }

    cout << "NO\n";
    return 0;
}