#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
              long long x;
          cin >> x;
         if (x >= 1110) {
            cout << "YES\n";
            continue;
                                 }
           bool ok = false;
        for (int b = 0; b * 111LL <= x && b < 11; b++) {
            if ((x - b * 111LL) % 11 == 0) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}