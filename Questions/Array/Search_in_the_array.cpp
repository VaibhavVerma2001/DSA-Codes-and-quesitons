// https://www.codingninjas.com/studio/problems/search-in-the-array_1116099?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&leftPanelTabValue=PROBLEM


#include <bits/stdc++.h> 

int search(vector<int>& arr , int key){
	int s = 0, e = arr.size()-1, mid, pos = -1;


	while(s<=e){
		mid = s + (e-s)/2;

		if(arr[mid] == key){
			s = mid + 1;
		}
		else if(arr[mid] < key){
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}
	// return insert position - 1 index, till here find prefix sum  
	return s-1;
}

vector<int> searchInTheArray(vector<int>& arr, vector<int>& queries, int n, int q)
{
	// Write Your code here
	int psum = 0;
	vector<int> parray;

	for(auto &x : arr){
		psum+=x;
		parray.push_back(psum);
	}

	vector<int> ans;

	// for queries[i] find it's right most position and get prefix sum till that index
	for(auto &q : queries){
		int index = search(arr, q);
		ans.push_back(parray[index]);

	} 


	return ans;
}

