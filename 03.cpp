#include <iostream>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	ll x;
	cin >> n >> x;
	int cnt = 0;
	for (int i = 1; i <= n; ++i){
		char c;
		int d;
		cin >> c >> d;
		if (c == '+') x += d;
		else {
			if (x < d) cnt++;
			else x -= d;
		}
	}
	cout << x << " " << cnt;
}

int main()
{
	solve();
	return 0;
}
