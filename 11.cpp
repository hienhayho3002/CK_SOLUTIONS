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

bool check(int n){
    for (int i = 2; i <= sqrt(n); ++i){
        if (n % i == 0) return 0;
    }
    return n > 1;
}

int SUM(int n){
    int res = 0;
    while(n){
        res += n%10;
        n /= 10;
    }
    return res;
}

void solve(){
    int n, h;
    cin >> n >> h;
    int cnt = 0;
    for (int i = 2; i <= n; ++i){
        if(check(i) && SUM(i) == h){
            cout << i << endl;
            cnt++;
        }
    }
    cout << cnt;
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
    cerr << "Time elapsed: " << TIME << "s.\n";
    #endif
    return 0;
}
