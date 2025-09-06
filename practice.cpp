#include <bits/stdc++.h>
using namespace std;

string retrieveData(string firstInfo, string secondInfo) {
    // Step 1: Sort to get lexicographically smallest permutation
    sort(firstInfo.begin(), firstInfo.end());

    // Step 2: If even the smallest permutation > secondInfo, return it
    if (firstInfo > secondInfo) return firstInfo;

    // Step 3: Keep generating next permutations until we find valid
    while (next_permutation(firstInfo.begin(), firstInfo.end())) {
        if (firstInfo > secondInfo) return firstInfo;
    }

    // Step 4: No valid permutation found
    return "-1";
}

int main() {
    string firstInfo, secondInfo;
    cin >> firstInfo >> secondInfo;

    cout << retrieveData(firstInfo, secondInfo) << endl;
    return 0;
}
