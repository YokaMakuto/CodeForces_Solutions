#include <iostream>
#include <cmath>
using namespace std; 
static bool p[1000001];
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    for(int i=2;i<=1000001;++i)p[i]=true;
    for(int i=2;i*i<=1000001;++i)if(p[i])for(int j=i*i;j<=1000001;j+=i)p[j]=false;
    int n;cin>>n;
    while(n--){
        long long int x;cin>>x;
        long long int r=(long long int)sqrt(x);
        if(1LL*r*r==x&&p[r])cout<<"YES\n";else cout<<"NO\n";
       
    }
   
    return 0;
}
