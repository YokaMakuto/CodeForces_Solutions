#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n; cin >> n;
    vector<long long> a(n);
    for(long long i = 0; i < n; i++) cin >> a[i];

    long long total = accumulate(a.begin(), a.end(), 0LL);
    if(total % 3 != 0){
        cout << 0 << "\n";
        return 0;
    }
    long long part = total / 3, countPart = 0, ans = 0, prefix = 0;
    for(int i = 0; i < n - 1; i++){
        prefix += a[i];
        if(prefix == 2*part) ans += countPart;
        if(prefix == part) countPart++;
    }
    cout << ans << "\n";
    return 0;
}