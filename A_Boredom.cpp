#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<long long> freq(100001,0);
    int mx=0;
    for(int i=0;i<n;i++){
        int x;cin>>x;freq[x]++;mx=max(mx,x);
    }
    vector<long long> dp(mx+1,0);
    dp[1]=freq[1];
    for(int i=2;i<=mx;i++){
        dp[i]=max(dp[i-1],dp[i-2]+freq[i]*i);
    }
    cout<<dp[mx]<<endl;
    return 0;
}