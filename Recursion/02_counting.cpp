#include <iostream>
using namespace std;

// Count n-> 1
void reverseCount(int n)
{
    // base case
    if (n == 0)
    {
        return;
    }

    // print first -- processing
    cout << n << " ";

    // recursive call
    // Tail rec bec fun ends with rec
    reverseCount(n - 1);
}

// Count 1 -> n
void count(int n)
{
    if (n == 0)
    {
        return;
    }

    // recursive call
    // head rec bec rec came before processing
    count(n - 1);

    // print later - processing
    cout << n << " ";
}

int main()
{

    reverseCount(10);
    cout << endl
         << endl;

    count(10);
    cout << endl
         << endl;
}