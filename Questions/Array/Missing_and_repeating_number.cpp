// Question - https://www.codingninjas.com/studio/problems/missing-and-repeating-numbers_873366?leftPanelTabValue=PROBLEM

// Method 1 - Using map TC = O(N), SC = O(N)


// Method 2 - TC = O(N), SC = O(1)
// visited node - multiply with -1

#include<bits/stdc++.h>
using namespace std;

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// // Write your code here 
	// int tsum = (n*(n+1))/2;
	// int arrsum = accumulate(arr.begin(),arr.end(),0);

	int dup;
	for(int i = 0 ; i < n ;i++){
		int index = abs(arr[i]) - 1;
		if(arr[index] < 0 ){
			// cout<<"duplicate is : "<<abs(arr[i])<<endl;
			dup = abs(arr[i]);
			break;
		}
		else{
			arr[index]*= -1;
		}
	}


	// To find missing, but array is changed now

	int mis;
    	for(int i = 0 ; i < n ;i++){
    		int index = abs(arr[i]) - 1;
    		if(arr[index] < 0 ){
    			continue;
    		}
    		else{
    			arr[index]*= -1;
    		}
    	}
    
    	for(int i = 0 ; i < n; i++){
    		if(arr[i] > 0){
    		    mis = i+1;
				break;
    		}
    	}
    	
	


	// int mis = tsum + dup - arrsum;
	return {mis , dup};
	
}
