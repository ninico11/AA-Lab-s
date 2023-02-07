#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

double fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
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



