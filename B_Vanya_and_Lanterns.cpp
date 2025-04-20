#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long l;
    cin >> n >> l;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(),a.end());

    long long mxGap=0;
    for(int i=1;i<n;i++){
        mxGap=max(mxGap,a[i]-a[i-1]);
    }

    double ans = max( (double)a[0], (double)(l - a.back()) );
    ans = max(ans, mxGap/2.0);

    cout << fixed << setprecision(9) << ans << endl;
    return 0;
}