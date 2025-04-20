#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N; cin>>N;
    vector<long long> x(N+1), y(N+1), P(N+1), Q(N+1);
    for(int i=1;i<=N;i++){
        cin>>x[i];
        y[i]=x[i];
    }
    sort(y.begin()+1,y.end());
    for(int i=1;i<=N;i++){
        P[i]=P[i-1]+x[i];
        Q[i]=Q[i-1]+y[i];
    }
    int M,T,L,R; cin>>M;
    while(M--){
        cin>>T>>L>>R;
        cout<<(T==1?P[R]-P[L-1]:Q[R]-Q[L-1])<<"\n";
    }
    return 0;
}