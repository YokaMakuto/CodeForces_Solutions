#include <bits/stdc++.h>
using namespace std;
int main(){
    long double A, B, C;
    cin >> A >> B >> C;
    if (A == 0) {
        if (B == 0) {
            if (C == 0)
                cout << -1 << endl;
            else
                cout << 0 << endl;
        } else {
            cout << 1 << endl;
            cout << fixed << setprecision(10) << -C / B << endl;
        }
        return 0;
    }
    long double D = B * B - 4 * A * C;
    if (D < 0) {
        cout << 0 << endl;
    } else if (D == 0) {
        cout << 1 << endl;
        cout << fixed << setprecision(10) << -B / (2 * A) << endl;
    } else {
        cout << 2 << endl;
        long double root1 = (-B - sqrtl(D)) / (2 * A);
        long double root2 = (-B + sqrtl(D)) / (2 * A);
        cout << fixed << setprecision(10) << min(root1, root2) << endl;
        cout << fixed << setprecision(10) << max(root1, root2) << endl;
    }
}