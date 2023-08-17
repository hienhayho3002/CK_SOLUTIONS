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

void solve(){
    int n;
    cin >> n;
    ll a[n + 1];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    ll l[n + 1], r[n + 1]; //l[i] = max(a[1],...,a[l]), r[i] = max(a[i + 1], a[n])
    l[1] = a[1];
    r[n] = 0;
    for (int i = 2; i < n; ++i){
        l[i] = max(l[i - 1], a[i]);
    }
    for (int i = n - 1; i >= 1; --i){
        r[i] = max(r[i + 1], a[i + 1]);
    }
    ll MAX = 0;
    int k = 0;
    for (int i = 1; i <= n - 1; ++i){
        if (MAX < l[i]*r[i]){
            MAX = l[i]*r[i];
            k = i;
        }
    }
    cout << MAX << " " << k;
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
