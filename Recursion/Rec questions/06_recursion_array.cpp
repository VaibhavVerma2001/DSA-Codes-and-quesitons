#include<iostream>
using namespace std ;

// let arr = [10,20,30,40,50]


// 1 - print array -> 10 ,20,30 ,40 ,50 from given index i to end

void print(int *a, int n, int i){

    if(i == n){
        return ;
    }

    // cout<<*(a+i)<<" ";
    cout<<a[i]<<" ";
    print(a,n,i+1);
}


int main(){
    int arr[] = {10,20,30,40,50};
    print(arr,5,0);
    cout<<endl;
    print(arr,5,2);
    cout<<endl;
}
