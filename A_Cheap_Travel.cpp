#include<bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    vector<int> vec(n+1,0);
    for(int i=0;i<n+1;i++){
       vec[i]=i*a+ceil((n-i)/(double)m)*b;
    }
    cout << *min_element(vec.begin(), vec.end()) << "\n";
}