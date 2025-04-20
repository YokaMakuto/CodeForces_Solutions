#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t,n,k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        if(k<n){
            cout <<k << "\n";
            return 0;
        }
        while(k){
            int i = 0;
                if((n+i)%n!=0){
                    k--;
                    if (k== 0){
                        cout << n+i << "\n";
                        break;
                    }
                    
                }
                i++;
            }
        }
        return 0;
}