#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

int main(){
	clock_t begin, end;
	int n;
	cin>> n;
	bool c[n];
	for(int i = 0; i<=n; i++){
		c[i]= true;
	}
	c[1] = false;
	int i = 2;
	begin = clock();
	while (i <= n){
		if (c[i] == true){
			int j=i+1;
			while (j<=n){
		    	if (j % i == 0) {
		    		c[j] = false;
		    	}
		    	j=j+1;
			}
		}
	  i=i+1;
	}
	end = clock();
	cout << "\n";
	double time_taken = double(end - begin) / double(CLOCKS_PER_SEC);
	cout << setprecision(6) << time_taken << "sec" << "\n";
	return 0;
}
