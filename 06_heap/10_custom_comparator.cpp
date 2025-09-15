// For priority_queue (Custom Comparator)

#include <bits/stdc++.h>
using namespace std;

// Min-heap using comparator struct
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // smaller element has higher priority
    }
};

int main() {
    priority_queue<int, vector<int>, Compare> pq;

    pq.push(5); pq.push(1); pq.push(7);

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
}



/*

// Comparator as a normal function
bool cmp(int a, int b) {
    return a > b; // descending order
}

int main() {
    vector<int> arr = {5, 2, 8, 1, 7};
    sort(arr.begin(), arr.end(), cmp);

    for (int x : arr) cout << x << " ";
    return 0;
}


why a > b but working different
Both use a > b, but the behavior is different because:
👉 std::sort and std::priority_queue interpret the comparator differently.

1. In std::sort
The comparator is interpreted as:
"cmp(a, b) returns true if a should come before b."
bool cmp(int a, int b) {
    return a > b; // "a should come before b if a is bigger"
}
That makes bigger numbers come earlier → descending order.
Example: [8, 7, 5, 2, 1].


2. In std::priority_queue
The comparator is interpreted as:
"Compare(a, b) returns true if a has lower priority than b."
struct Compare {
    bool operator()(int a, int b) {
        return a > b; // return true if a has LOWER priority
    }
};
If a > b, then a is considered lower priority than b.
That makes the smallest element bubble up (because bigger ones are treated as lower priority).
Hence → min-heap behavior (1 5 7).
*/