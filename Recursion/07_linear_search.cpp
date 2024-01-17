//Ques 1 - given an array, and target. Find first index where that target is present, else -1;

#include<iostream>
#include<vector>
using namespace std ;

int search(int *a, int n,int i, int target){
    // base case
    if(i == n){
        return -1;
    }

    // if found
    if(a[i] == target){
        return i;
    }

    // recusrive call
    int ans = search(a,n,i+1,target);
    return ans;

}


//Ques 2 - given an array, and target. Print all indexes where that target is present, else -1;
void search2(int *a, int n,int i, int target){
    // base case
    if(i == n){
        cout<<endl;
        return ;
    }

    // if found
    if(a[i] == target){
        cout<<i<<" ";
    }

    // recusrive call
    search2(a,n,i+1,target);

}


//Ques 3 - given an array, and target. Print all indexes where that target is present, else -1;
// Case 2 - when we have to return vector
vector<int> search3(int *a, int n,int i, int target){
    // this will be created for all function calls
    vector<int> ans;
    
    // base case
    if(i == n){
        return ans;
    }

    // if found
    if(a[i] == target){
        ans.push_back(i);
    }

    // recusrive call
    // it will also return vector
    vector<int> v = search3(a,n,i+1,target);
    //combine ans and v , otherwise ans remains empty bec it is created for each function
    for(auto x : v){
        ans.push_back(x);
    }
    return ans;
}

// Or best way is that make void funtion and pass vector by reference



int main ()
{
    // Ques 1 - 
    int arr[] = {10,20,25,30,40,50,25};
    cout<<search(arr,7,0,25)<<endl;
    cout<<search(arr,7,0,40)<<endl;
    cout<<search(arr,7,0,60)<<endl;

    cout<<"For question 2 "<<endl;

    // Ques 2 - 
    int arr1[] = {25,10,20,25,30,40,50,25};
    search2(arr,7,0,25);
    search2(arr,7,0,40);
    // search2(arr,7,0,60);// if not found, will not print anything

    // Ques 3 - when we have to store in vector
    int arr2[] = {25,10,20,25,30,40,50,25};
    vector<int> ans = search3(arr,7,0,25);
    cout<<"For question 3 "<<endl;

    for(auto &x: ans){
        cout<<x<<" ";
    }

    return 0 ;
}