#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;


double f[MAX] = {0};

double fib(int n)
{

	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return (f[n] = 1);
	if (f[n])
		return f[n];
		
	int k ;
	if(n % 2 == 0){
		k=n/2;
	}
	else{
		k=(n+1)/2;
	}
	if(n % 2 == 0) {
		f[n] = (2*fib(k-1) + fib(k))*fib(k);
	}
	else{
		f[n] = (fib(k)*fib(k) + fib(k-1)*fib(k-1));
	}
	return f[n];
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
		cout << setprecision(6) << time_taken << "\n";
	}
	return 0;
}

