#include <bits/stdc++.h> 
using namespace std;

int intPart(long long n){
	long long s = 0, e = n, mid, ans = -1;

	while(s<=e){
		mid = s + (e-s)/2;

		if(mid*mid <= n){
			ans = mid;
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	return ans;
}

double squareRoot(long long n, int d) 
{	
	// Write your code here.

	// T.C for this loop = O(log n)
	double ans = intPart(n);


	// T.C for this = O(10*d) = O(d)
	// For computing the fractional part
    // of square root upto given precision
    double increment = 0.1;
    for (int i = 0; i < d; i++) {
        while (ans * ans <= n) {
            ans += increment;
        }
 
        // loop terminates when ans * ans > number
        ans = ans - increment;
        increment = increment / 10;
    }
    return ans;
}

int main(){
    // int n;
    // int d;
    // cin>>n;
    // cin>>d;
    cout<<squareRoot(6,3)<<endl;
}