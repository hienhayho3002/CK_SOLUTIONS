#include <iostream>
using namespace std;

void solve(){
	int n, x;
	cin >> n >> x;
	int a[n + 1];
	bool check[n + 1] = {0};
	for (int i = 1; i <= n; ++i) cin >> a[i];
	int k = x;
	while(k){
		check[k] = 1;
		k = a[k];
	}
	for (int i = 1; i <= n; ++i){
		if (!check[i]){
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}

int main()
{
	solve();
	return 0;
}
