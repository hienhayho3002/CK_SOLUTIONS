#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double calc(int n){
	if (n == 1) return 1;
	return sqrt(n + calc(n - 1));
}

int main()
{
	int n;
	cin >> n;
	cout << fixed << setprecision(2) << calc(n);
	return 0;
}