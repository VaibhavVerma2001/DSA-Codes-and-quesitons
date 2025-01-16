#include<iostream>
#include<vector>
using namespace std ;


void print(vector<int> &arr){
    for(auto &x: arr){
        cout<<x<<" ";
    }
    cout<<endl<<endl;
}


// To sort vector of string in descending order - leetcode 1985
//in leetcode we write static bec so that it become global(because it is written inside class) and we dont need to use like obj.comp, because comp is signature function
static bool comp (string s1, string s2){
    // if the length is same then return true for bigger string
    if(s1.length()== s2.length()){
        return s1>s2;
    }
    // if size is not same then return string with bigger size
    else{
        return s1.length() > s2.length();
    }
}


void printvv(vector<vector<int>> &v){
    for(int i = 0 ; i < v.size(); i++){
        cout<<v[i][0] <<" "<<v[i][1]<<endl;
    }
    cout<<endl<<endl;
}


void printMap(unordered_map<int,int> &m){
    for(auto &x : m){
        cout<<x.first<<" "<<x.second<<endl;
    }
    cout<<endl<<endl;
}


// return type of comparator is bool
static bool myComp(int a,int b){
    // return a < b; // will sort in asc. order // means when a < b , then it is true -> no need to sort
    return a > b; // will sort in dec. order // means when a > b , then it is true -> no need to sort
}


bool myCompFor1stIndex(vector<int> a, vector<int> b){
    return a[1] < b[1] ; // increasing order
    // return a[1] > b[1] ; // decreasing order
}




int main (){
    
    vector<int> arr = {10,30,50,40,30};

    // sort increasing order 
    // sort(arr.begin(),arr.end());
    // print(arr);


    // sort decreasing order
    // 1 - using STL 
    // sort(arr.begin(),arr.end(), greater<int> ());
    // print(arr);


    // 2 - using comparator

    sort(arr.begin(),arr.end(),myComp);
    print(arr);



    // B) Sorting vector of vector
    // vector<vector<int>> v = {{0,12}, {3,21}, {1,42}, {2,38}};
    
    // it will sort based on 0th index value
    // sort(v.begin(),v.end());
    // printvv(v);

    // to sort on the basis of 1st index
    // sort(v.begin(), v.end(), myCompFor1stIndex);
    // printvv(v);


    return 0 ;
}