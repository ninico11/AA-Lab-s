#include<bits/stdc++.h>
using namespace std;

double fib(int n)
{
	double a = 0, b = 1, c, i;
	if( n == 0)
		return a;
	for(i = 2; i <= n; i++)
	{
	c = a + b;
	a = b;
	b = c;
	}
	return b;
}


int main()
{	
	int n = 1000;
	for (int i = 1; i <= n; i++) {
		clock_t begin, end;
		begin = clock();
		cout<< i <<" ";
		cout<<fixed;
		end = clock();
		double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
		cout << setprecision(6) << time_taken << ",\n";
	}
	return 0;
}



