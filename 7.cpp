#include <iostream>
using namespace std;

void solve()
{
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	int MIN = min(a[0], a[1]);
	int MAX = a[1] - a[0];
	for (int i = 2; i < n; ++i){
		MAX = max(MAX, a[i] - MIN);
		MIN = min(MIN, a[i]);
	}
	cout << MAX;
}

int main()
{
	solve();
	return 0;
}