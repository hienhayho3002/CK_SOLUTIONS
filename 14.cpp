#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
using namespace std;

#define arr array
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
typedef long long ll;
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
#define all(v) (v).begin(), (v).end()
#define it(v, x) std::iota(all(v), (x))
#define acc(v, x) std::accumulate(all(v), (x))
#define eb emplace_back
#define endl '\n'

ll a[10005];

// Kỹ thuật hai con trỏ - Two pointers -> ĐPT O(N)
void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int l = 1, r = n;
    ll an = 0, d = 0;
    int i = 1;
    while(l <= r){
        if (i & 1){ // i%2 == 1
            if(a[l] >= a[r]){
                an += a[l];
                l++;
            }
            else {
                an += a[r];
                r--;
            }
        }
        else{
            if(a[l] >= a[r]){
                d += a[l];
                l++;
            }
            else {
                d += a[r];
                r--;
            }
        }
        i++;
    }
    cout << an << " " << d << endl;
    if (d == an) cout << "Draw";
    else if (d > an) cout << "Danh";
    else cout << "An";
}


int main()
{
    //srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    //int t; cin >> t; for (int i = 1; i <= t; ++i)
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "Time executed: " << TIME << "s.\n";
    #endif
    return 0;
}
