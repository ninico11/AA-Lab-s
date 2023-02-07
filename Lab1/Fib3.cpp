#include<bits/stdc++.h>
using namespace std;
void multiply(double F[2][2], double M[2][2]);
void power(double F[2][2], int n);

double fib(int n)
{
	double F[2][2] = { { 1, 1 }, { 1, 0 } };
	
	if (n == 0)
		return 0;
		
	power(F, n - 1);
	
	return F[0][0];
}

void multiply(double F[2][2], double M[2][2])
{
	double x = F[0][0] * M[0][0] +
			F[0][1] * M[1][0];
	double y = F[0][0] * M[0][1] +
			F[0][1] * M[1][1];
	double z = F[1][0] * M[0][0] +
			F[1][1] * M[1][0];
	double w = F[1][0] * M[0][1] +
			F[1][1] * M[1][1];
	
	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

void power(double F[2][2], int n)
{
	int i;
	double M[2][2] = { { 1, 1 }, { 1, 0 } };
	for(i = 2; i <= n; i++)
		multiply(F, M);
}
int main()
{	
	int n = 100;
	for (int i = 1; i <= n; i++) {
		clock_t begin, end;
		begin = clock();
		cout<< i << " " << setprecision(0) << fib(i) <<" ";
		cout<<fixed;
		end = clock();
		double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
		cout << setprecision(6) << time_taken << ",\n";
	}
	return 0;
}



