// write a program to find minimum number in an array

#include<bits/stdc++.h>
using namespace std ;


// Method 1 - Using global variable
int mini = INT_MAX;
int solve1(int *a, int n, int i){
    // BC
    if(i == n){
        return mini;
    }

    // Processing
    mini = min(a[i],mini);

    // RC
    int ans = solve1(a,n,i+1);
    return ans;
}



// Method 2 - passing variable to store ans
// pass by reference otherwise in function, its copy will be created
void solve2(int *a, int n, int i, int &mini2){
    // BC
    if(i == n){
        return;
    }

    // Processing
    mini2 = min(a[i],mini2);

    // RC
    solve2(a,n,i+1,mini2);
}


// Question 2 - make a function even that takes int array of size n and an empty vector<int> ans -> Push all all even integers in array arr to vector ans

// pass by reference or create global vector
void evenElements(int *a , int n, int i, vector <int> &ans){
    // Base Case
    if(i == n){
        return ;
    }

    // Processing
    if(a[i] % 2 == 0){
        ans.push_back(a[i]);
    }

    // RC
    evenElements(a,n,i+1,ans);

}


// Question 3 - Take an int array as input and double(Num x 2) its all values

void solve3(int *a , int n , int i){
    // BC
    if(i == n){
        return ;
    }

    // processing
    a[i]*=2;

    // RC
    solve3(a,n,i+1);
}


// Ques 4 - Given a digit, return vector containing all it's digits
void digits(int num, vector<int> &ans){
    
    // BC
    if(num == 0){
        return ;
    }

    // RC -> first call, otherwise it will be in reverse order
    digits(num/10, ans);

    // Processing
    int rem = num % 10;
    ans.push_back(rem);
}


// Ques 5 - given a vector containing digits of number, find number made by it
// eg - v = {4,2,1,7}, op = 4217
void number(vector<int> v,int n, int &num){
    // BC 
    if(n == 0){
        return ;
    }

    // RC -> reach 0th index 1st then do processing
    number(v,n-1,num);

    // Processing
    num = num*10 +  v[n-1];

}


int main ()
{
    // Method 1 - using global variable 
    int a[5] = {20,50,10,5,30};
    cout<<solve1(a,5,0)<<endl;

    // Method 2 - passing variable to store ans
    // pass by reference otherwise in function, its copy will be created
    int mini2 = INT_MAX;
    solve2(a,5,0,mini2);
    cout<<"mini2 is : "<<mini2<<endl;
    


    // Question 2 - store even elements of array to vector
    int arr[10] = {10,23,21,30,40,45,50,55,8,10};
    vector<int> ans;
    evenElements(arr,10,0,ans);

    cout<<"Even elements are : ";
    for(auto x : ans){
        cout<<x<<" ";
    }
    cout<<endl;


    // Question 3 - double each value of array
    int arr2[] = {10,20,30,40};
    solve3(arr2,4,0);
    cout<<"after doubling elements are : ";
    for(int i = 0 ; i < 4; i++){
        cout<<arr2[i]<<" ";
    }
    cout<<endl;


    // Ques 4 - find digits of number
    vector<int> dig;
    int num = 54123;
    digits(num,dig); 

    cout<<"For ques 4" <<endl;
    for(auto &x : dig){
        cout<<x<<" ";
    } 
    cout<<endl;

    // Ques 5 - find number formed by elements of vector
    vector<int> v = {4,2,1,7};
    int num2 = 0;
    number(v,4,num2);
    cout<<"Number made is : "<<num2<<endl;

    return 0 ;
}