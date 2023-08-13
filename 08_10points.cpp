#include <iostream>
using namespace std;
typedef long long ll;

ll f(int a, int n){
	ll x_next = a;
	ll y_next = 2*a + 1;
	int i = 2;
	while (i <= n){
		ll x = x_next + 2*y_next;
		ll y = 2*x_next + y_next;
		x_next = x;
		y_next = y;
		i++;
	}
	return x_next + y_next;
}

int main()
{
	// Khử đệ quy bằng vòng lặp
	int n, a;
	cin >> n >> a;
	cout << f(a, n);
	return 0;
}
