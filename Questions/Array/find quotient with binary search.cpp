// https://www.geeksforgeeks.org/problems/division-without-using-multiplication-division-and-mod-operator/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=bottom_sticky_on_article

long long divide(long long a, long long b)
{
    // code here
    long long ans = -1;
    long long s = 0, e = abs(a);
    long long mid;

    while (s <= e)
    {
        mid = s + (e - s) / 2;

        if (abs(mid * b) == abs(a))
        {
            ans = mid;
            break;
        }
        else if (abs(mid * b) < abs(a))
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
    if ((a > 0 && b > 0) || (a < 0 && b < 0))
    {
        return ans;
    }

    else
    {
        return -ans;
    }
}