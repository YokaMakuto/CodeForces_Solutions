#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int n;
    cin >> n;
    long long int k;
    cin >> k;
    long long half = (n + 1) / 2;
    if (k <= half) {
        cout << 2 * k - 1 << "\n";
    } else {
        cout << 2 * (k - half) << "\n";
    }

    return 0;
}
