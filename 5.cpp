#include <iostream>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int cnt = 0;
	int ans = 0;
	int x;
	for (int i = 1; i <= n; ++i){
		cin >> x;
		if (x == 0) cnt++;
		else {
			cnt = 0;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve();
	return 0;
}