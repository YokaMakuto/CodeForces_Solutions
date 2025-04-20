#include<bits/stdc++.h>
using namespace std;    
long long int tobinary(int n) { 
    long long int ans = 0; 
    int i = 1; 
    while (n > 0) { 
        int lastdigit = n % 2; 
        n /= 2; 
        ans += lastdigit * i; 
        i *= 10; 
    } 
    return ans; 
}
int main() { 

    ios::sync_with_stdio(0); cin.tie(0);
    long long int n;
    cin >> n;
    long long int a = tobinary(n);
    long long int ans = 0;
    for(int i = 0; i < 32; i++) {
        if ((a %10) == 1) {
            a = a / 10;
            ans++;
        }
        else {
            a = a / 10;
        }
    }
    cout << ans << endl;
}