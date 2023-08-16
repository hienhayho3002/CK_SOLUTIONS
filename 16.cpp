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

const int maxN = 105;
const int maxX = 1e6 + 5;
int dp[maxX];
int n, x;
int a[105];

//Dynamic Programming
void solve(){
    fill(&dp[0], &dp[maxX], 1e9);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[a[i]] = 1;
    }
    for (int i = 1; i <= n; ++i){
        for (int s = 0; s <= x; ++s){
            if (s >= a[i]) 
                dp[s] = min(dp[s], dp[s - a[i]] + 1);
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << endl;
}


int main()
{
    //srand(time(NULL));
    #ifndef ONLINE_JUDGE
    freopen("TASK.inp", "r", stdin);
    freopen("TASK.out", "w", stdout);
    #endif
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    //int t; cin >> t; for (int i = 1; i <= t; ++i)
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "Time executed: " << TIME << "s.\n";
    #endif
    return 0;
}
