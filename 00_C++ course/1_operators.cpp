#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cout   <<"enter the value 1 :";
    cin>>a;
    cout<< "\n enter the value 2 :";
    cin>>b;
    cout<<"\n sum of no. is :"<<a+b;
    cout<<"\n diff. of no. is :"<<a-b;
    cout<<"\n product of no. is :"<<a*b;
    cout<<"\n divi. of no. is :"<<a/b;
    cout<<"\n remainder of no. is :"<<a%b;
//increment,decrement  operator
    cout<<"\n value of a++ is :"<<a++;
    cout<<"\n value of ++a is :"<<++a;
    cout<<"\n value of --a is :"<<--a;
    cout<<"\n value of a-- is :"<<a--;
//  comparison operator
    cout<<"\n value of a==b is :"<<(a==b);
    cout<<"\n value of a>b is :"<<(a>b);
    cout<<"\n value of a>=b is :"<<(a>=b);
    cout<<"\n value of a<b is :"<<(a<b);
    cout<<"\n value of a<=b is :"<<(a<=b);
//  logical operator
    cout<<"\n value of a&&b is :"<<(a&&b);
    cout<<"\n value of a||b is :"<<(a||b);
    cout<<"\n value of a!=b is :"<<(a!=b);
    return 0;
}
