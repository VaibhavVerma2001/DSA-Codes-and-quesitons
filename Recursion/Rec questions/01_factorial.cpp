#include <iostream>
using namespace std;

int factorial(int n)
{
    // Base case
    if (n == 1 || n == 0)
    {
        return 1;
    }

    // Recursive call
    int ans = n * factorial(n - 1);
    return ans;
}

int main()
{

    int n = 7;
    cout << factorial(n);
}