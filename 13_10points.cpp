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

// Quy hoạch động - Dynamic Programming -> ĐPT O(N)
void solve(){
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll f[n + 1];
    f[0] = 0;
    f[1] = a[1];
    for (int i = 2; i <= n; ++i){
        f[i] = max(f[i - 1], f[i - 2] + a[i]);
    }
    cout << f[n] << endl;
}


int main()
{
    //srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    // int t; cin >> t; for (int i = 1; i <= t; ++i)
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "Time executed: " << TIME << "s.\n";
    #endif
    return 0;
}
