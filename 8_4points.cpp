#include <iostream>
using namespace std;
typedef long long ll;

ll y(int a, int n);

ll x(int a, int n){
	if (n == 1) return (ll)a;
	return x(a, n - 1) + 2*y(a, n - 1);
}
 
ll y(int a, int n){
	if (n == 1) return (ll)2*a + 1;
	return 2*x(a, n - 1) + y(a, n - 1);
}

int main()
{
	//ĐỆ QUY
	int n, a;
	cin >> n >> a;
	cout << x(a, n) + y(a, n);
	return 0;
}
