// https://www.geeksforgeeks.org/sum-minimum-maximum-elements-subarrays-size-k/

// https://www.codingninjas.com/studio/problems/sum-of-minimum-and-maximum-elements-of-all-subarrays-of-size-k_1171047?leftPanelTabValue=PROBLEM


#include<bits/stdc++.h> 
using namespace std;
long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
	// Write your code here.
	deque<int> maxi, mini;
	long long ans = 0;

	int i = 0 , j = 0;

	while(j < n){
		// place max and min element on front
		while(!maxi.empty() && maxi.back() < arr[j]){
			maxi.pop_back();
		}

		while(!mini.empty() && mini.back() > arr[j]){
			mini.pop_back();
		}

		maxi.push_back(arr[j]);
		mini.push_back(arr[j]);

		if( (j-i+1) < k) {
			j++;
		}

		else{
			ans = ans + maxi.front() + mini.front();

			if(maxi.front() == arr[i]){
				maxi.pop_front();
			}

			if(mini.front() == arr[i]){
				mini.pop_front();
			}

			i++;
			j++;
		}
	}
	return ans;
}
