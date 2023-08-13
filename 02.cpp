#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n, thredhold;
	cin >> n >> thredhold;
	int a[n][n], b[n][n], c[n][n];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cin >> b[i][j];
			c[i][j] = abs(b[i][j] - a[i][j]);
			if (c[i][j] > thredhold) c[i][j] = 255;
			else c[i][j] = 0;
		}
	}
	for(int i = 0; i < n; ++i){
		for (int j = 0; j < n; ++j){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	solve();
	return 0;
}
