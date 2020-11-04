#include <iostream>
#include <cmath>
using namespace std;

double f(const double x);

int main()
{
	double tp, tk, z;
	int N;

	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> N;

	double dt = (tk - tp) / N;
	double t = tp;

	while (t <= tk)
	{
		z = f(1 + 2 * t) + f(f(1) + 2. * f(2 * t)) * f(f(1) + 2. * f(2 * t));
		cout << t << " " << z << endl;
		t += dt;
	}
	system("pause");
	return 0;
}
double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(x) * sin(x) + sin(x * x)) / (1. + cos(x) * cos(x));
	else
	{
		double S = 0;
		int n = 0;
		double a = x;
		S = a;
		do
		{
			n++;
			double R = pow(x, 4) / ((4. * n + 1) * (4. * n) * (4. * n - 1) * (4. * n - 2));
			a *= R;
			S += a;
		} while (n < 6);
		return (1 / (1 + x * x)) * S;
	}
}