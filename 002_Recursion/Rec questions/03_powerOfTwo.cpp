#include<iostream>
using namespace std ;

// Find 2^n
int powerOfTwo(int n){
    if(n == 0){
        return 1;
    }
    
    int ans = 2 * powerOfTwo(n-1);
    return ans;
}

int main() {
    cout<<powerOfTwo(2)<<endl;
    cout<<powerOfTwo(4)<<endl;
    cout<<powerOfTwo(8)<<endl;
    cout<<powerOfTwo(10)<<endl;
}