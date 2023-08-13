#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//Đệ quy
double calc(int n){
	if (n == 1) return 1;
	return sqrt(n + calc(n - 1));
}

//Vòng lặp
double calc_2(int n){
	int i = 1;
	double s = 0;
	while (i <= n)
	{
		s = sqrt(s + i);
		i++;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	cout << fixed << setprecision(2) << calc(n);
	return 0;
}
