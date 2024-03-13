// templates are made when in overriding of function -
// 1-> no. of arguments are same.
// 2-> code in the fun are same 
// means if only dataype is diiferent in function then we use template ,so that we dont 
//need to make func for each datatype.
/*
//type -1 function templates 
//ex-1 without using template we had to make fun for each datatype
#include<iostream>
using namespace std;
int big(int a , int b)
{
    if (a>b)
    {
        return a;
    }
    else 
    {
    return b;
    }
}
double big(double a , double b)
{
    if (a>b)
    {
        return a;
    }
    else 
    {
    return b;
    }
}

int main ()
{
    cout<<big(5,6)<<endl;
    cout<<big(7.2,8.3);
}
*/
//ex->2 we dont need to make func for each data type while using template
/* 
#include<iostream>
using namespace std;

template <class X> // now X is a template i.e; in place of int float or any other
                   // datatype we will use X now 
X big (X a, X b)
{
    if (a>b)
    {
        return a;
    }
    else 
    {
    return b;
    }
}
int main ()
{
    cout<<big(5,6)<<endl;
    cout<<big(7.2,8.3);
    return 0;
}
*/
//ex->3 we dont need to make func for each data type while using template 
#include<iostream>
using namespace std;

template <class X, class Y> // now X and Y are 2 place holders
X big (X a, Y b)
{
    if (a>b)
    {
        return a;
    }
    else 
    {
    return b;
    }
}
int main ()
{
    cout<<big(5,6)<<endl;
    cout<<big(7.2,8.3)<<endl;
    cout<<big(8.3,5);
    return 0;
}