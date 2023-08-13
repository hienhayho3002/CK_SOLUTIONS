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

const int N = 1e6 + 11;
int min_p[N + 1];

void sieve()
{
    for (int i = 2; i <= sqrt(N); ++i){
        if (min_p[i] == 0){
            for (int j = i*i; j <= N; j += i){
                if (min_p[j] == 0) min_p[j] = i;
            }
        }
    }
    for (int i = 2; i <= N; ++i){
        if (min_p[i] == 0) min_p[i] = i;
    }
}

ll SUM(int n){
    vector<int> res;
    while(n != 1){
        res.eb(min_p[n]);
        int cnt = 0;
        int t = min_p[n];
        while(n % t == 0 && n > 1){
            n /= t;
            cnt++;
        }
        res.eb(cnt);
    }
    int s = (int)res.size();
    ll r = 1;
    for (int i = 0; i < s; i += 2){
        ll S = 0;
        for (int j = 0; j <= res[i + 1]; ++j){
            S += pow(res[i], j);
        }
        r *= S;
    }
    return r;
}


void solve(){
    sieve();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int x;
        cin >> x;
        if (x == 1){
            cout << 1 << endl;
            continue;
        }
        if (2*ll(x) <= SUM(x)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}


int main()
{
    //srand(time(NULL));
    //#ifndef ONLINE_JUDGE
    //#endif
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    //int t; cin >> t; for (int i = 1; i <= t; ++i)
    solve();
    
    #ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << TIME << "s.\n";
    #endif
    return 0;
}
