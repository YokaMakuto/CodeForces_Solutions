#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    vector<int> x(n);
    for(int i=0;i<n;i++) cin>>x[i];
    sort(x.begin(), x.end());
    int q;
    cin>>q;
    while(q--){
        long long m;
        cin>>m;
        cout<<upper_bound(x.begin(), x.end(), m)-x.begin()<<"\n";
    }
    return 0;
}