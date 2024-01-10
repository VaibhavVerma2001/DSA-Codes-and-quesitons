#include <iostream>
#include <vector>

using namespace std;

int divide(int dividend, int divisor)
{
    // code here
    int ans = -1;
    int s = 0, e = abs(dividend);
    int mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (abs(mid * divisor) == abs(dividend))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * divisor) < abs(dividend))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }

    // check sign
    if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
    {
        return ans;
    }

    else
    {
        return -ans;
    }
}

double myPrecisionDivide(int dividend, int divisor,int precision)
{
    double quotient = divide(dividend, divisor);
    double step = 0.1;
    for (int i = 0; i < precision; ++i)
    {
        while (quotient * divisor <= dividend)
        {
            quotient += step;
        }
        // loop break when quotient*divisor > dividend
        quotient = quotient - step;
        step /= 10;
    }
    return quotient;
}

int main()
{
    int dividend = 29;
    int divisor = 7;
    int precision = 5;
    cout << myPrecisionDivide(dividend, divisor,precision) << endl;
    cout << myPrecisionDivide(10, 3,3) << endl;
    return 0;
}