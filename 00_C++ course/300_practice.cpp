// -> Write a C++ program to check if the value of each element is equal or greater than the value of previous element of a given array of integers. Go to the editor
// Sample Input:
// { 5, 5, 1, 5, 5 }
// { 1, 2, 3, 4 }
// { 3, 3, 5, 5, 5, 5}
// { 1, 5, 5, 7, 8, 10}
// Sample Output:
// 0
// 1
// 1
// 1
/*
#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= arr[i + 1])
        {
            count++;
        }
    }
    cout<<count<<endl;
    if (count == (n - 1) )
    {
        cout << "1\n";
    }
    else
    {
        cout << "0 \n";
    }
    return 0;
} //giving wrong output
*/

// -> Write a C++ program to check a given array of integers and return true if the array contains three increasing adjacent numbers. Go to the editor
// Sample Input:
// { 1, 2, 3, 5, 3, 7 }
// { 3, 7, 5, 5, 3, 7 }
// { 3, 7, 5, 5, 6, 7, 5 }
// Sample Output:
// 1
// 0
// 1
/*
#include<iostream>
using namespace std ;

void check (int a[] , int n)
{
    int count =0;
    for (int i = 0; i < n; i++)
    {
        if (a[i]<a[i+1] && a[i+1]<a[i+2])
        {
           count++;
        }
    }
    cout<<count<<endl;
    if (count == n-1)
    {
        cout<<"1 \n";
    }
    else 
    {
        cout<<"0 \n";
    }
}
int main ()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    check(arr , n);
    return 0 ;
} //wrong output 
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
        {
            if (arr[i] <= arr[i + 1])
            {
                count++;
            }

            else
            {
                break;
            }
        }
        else
        {
            count++;
        }
    }
    cout << count << endl;
    if (count == (n - 1))
    {
        cout << "1\n";
    }
    else
    {
        cout << "0 \n";
    }
    return 0;
}