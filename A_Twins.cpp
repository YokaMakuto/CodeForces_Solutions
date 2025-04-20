#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vi a(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int total_sum = accumulate(a.begin(), a.end(), 0);
    int taken_sum = 0;
    int count = 0;

    for (int i = n - 1; i >= 0; --i) {
        taken_sum += a[i];
        count++;
        if (taken_sum > total_sum - taken_sum) {
            cout << count << "\n";
            break;
        }
    }

    return 0;
}
