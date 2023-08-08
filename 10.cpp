#include <bits/stdc++.h>
using namespace std;

int minPrime[1000005], a[100];


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 1000000;
    for (int i = 2; i * i <= n; ++i) {
        if (minPrime[i] == 0) { //if i is prime
            for (int j = i * i; j <= n; j += i) {
                if (minPrime[j] == 0) {
                    minPrime[j] = i;
                }
            }
        }
    }
    for (int i = 2; i <= n; ++i) {
        //check[i] = 2;
        if (minPrime[i] == 0) {
            minPrime[i] = i;
        }
    }
    long long t, x, temp;
    cin >> t;
    while(t--){
        cin >> x;
        if(x == 1){
            cout << "1\n";
            continue;
        }
        
        temp = x;
        
        int nA = 0;
        while (x != 1) {
            
            a[nA++] = minPrime[x];
            x /= minPrime[x];
        }
        long long res = 1;
        if(nA == 1){
            res += a[0];
        }
        else{
            long long num = a[0];
            long long sum = 1 + num;
            for(int i = 1; i < nA; ++i){
                if(a[i] == a[i - 1]){
                    num *= a[i];
                    sum += num;
                }
                else{
                    res *= sum;
                    num = a[i];
                    sum = 1 + num;
                }
            }
            res *= sum;
        }
        
        cout << (2 * temp <= res) << '\n';
    }
    return 0;
}
