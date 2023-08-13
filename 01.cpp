#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
typedef long long ll;

void solve()
{
	int n;
	cin >> n;
	int a[n], b[n];
	for (int i = 0; i < n; ++i) cin >> a[i];
	ll dot_product = 0;
	double norm_1 = 0, norm_2 = 0;
	for (int i = 0; i < n; ++i){
		cin >> b[i];
		dot_product += (a[i]*b[i]);
		norm_1 += (a[i]*a[i]);
		norm_2 += (b[i]*b[i]);
	}
	norm_1 = sqrt(norm_1);
	norm_2 = sqrt(norm_2);
	double ans = (double)dot_product/(norm_1*norm_2);
	cout << fixed << setprecision(4) << ans;
}

int main()
{
	solve();
	return 0;
}
