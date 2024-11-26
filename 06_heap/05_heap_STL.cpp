#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // by default max-heap
    priority_queue<int> pq1;

    vector<int> arr = {10, 2, 4, 8, 6, 9};
    for (int i = 0; i < 6; i++)
    {
        pq1.push(arr[i]);
    };

    cout << "Size of pq is : " << pq1.size() << endl;

    // Printing pq elements
    cout << "Priority queue : " << endl;
    while (!pq1.empty())
    {
        cout << pq1.top() << " ";
        pq1.pop();
    }
    cout << endl;

    cout << "Size of pq is : " << pq1.size() << endl;

    // Min-heap
    cout << "Min heap implementation " << endl;
    priority_queue<int, vector<int>, greater<int>> pq2;

    for (int i = 0; i < 6; i++)
    {
        pq2.push(arr[i]);
    };

    cout << "Size of pq is : " << pq2.size() << endl;

    // Printing pq elements
    cout << "Priority queue : " << endl;
    while (!pq2.empty())
    {
        cout << pq2.top() << " ";
        pq2.pop();
    }
    cout << endl;
    cout << "Size of pq is : " << pq2.size() << endl;

    return 0;
}