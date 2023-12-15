// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/description/?envType=daily-question&envId=2023-12-12


class Solution {
public:
    int maxProduct(vector<int>& v) {

        // Method 1 - TC = O(n log (n))

        // sort(v.begin(),v.end());
        // return ((v[v.size()-1] - 1) * (v[v.size()-2] - 1) );


        // method 2 - find 2 maximum elements

        int largest = 0 , secondLargest = 0;

        for(auto x : v){
            // largest become secondLargest if some number is biggest
            // else if it can be secondLargest also
            if(x >= largest){
                secondLargest = largest;
                largest = x;
            } 
            else if (x > secondLargest){
                secondLargest = x;
            }

        }
        return ((largest-1) * (secondLargest - 1));
    }
};