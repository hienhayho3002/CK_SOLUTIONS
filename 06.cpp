#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b){
	return (a*b)/gcd(a, b);
}

struct PS{
	ll ts, ms;
	PS(){
		ts = 0;
		ms = 1;
	}
	friend istream& operator >> (istream& in, PS &a){
		cin >> a.ts >> a.ms;
		if (a.ms < 0) {
			a.ts = -a.ts;
			a.ms = -a.ms;
		}
		ll t = gcd(abs(a.ts), abs(a.ms));
		a.ts /= t;
		a.ms /= t;
		return in;
	}
	friend ostream& operator << (ostream& os, PS &a){
		if (a.ms < 0) {
			a.ts = -a.ts;
			a.ms = -a.ms;
		}
		ll t = gcd(abs(a.ts), abs(a.ms));
		a.ts /= t;
		a.ms /= t;
		if (abs(a.ts) % abs(a.ms) == 0) os << a.ts / a.ms;
		else os << a.ts << "/" << a.ms;
		return os;
	}
	PS operator+(const PS &a){
		PS t;
		ll LCM = lcm(abs(ms), abs(a.ms));
		t.ts = ts*(LCM/ms) + a.ts*(LCM/a.ms);
		t.ms = LCM;
		ll GCD = gcd(abs(t.ts), abs(t.ms));
		t.ts /= GCD;
		t.ms /= GCD;
		return t;
	}
	bool operator < (const PS &a){
		return ts*a.ms < a.ts * ms;
	}
	bool operator > (const PS &a){
		return ts*a.ms > a.ts * ms;
	}
};


void solve(){
    int n;
    cin >> n;
    PS a[101];
    PS t;
    for (int i = 0; i < n; ++i){
    	cin >> a[i];
    	t = t + a[i];
    }
    PS MAX = a[0];
    PS MIN = a[0];
    for (int i = 1; i < n; ++i){
    	if (MAX < a[i]) MAX = a[i];
    	else if (MIN > a[i]) MIN = a[i];
    }
    PS tong = MAX + MIN;
    cout << t << " " << tong;
}


int main()
{
    solve();
    return 0;
}
