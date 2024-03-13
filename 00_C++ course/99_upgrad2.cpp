// wap to take and print array elements using pointers
/*
#include <iostream>
using namespace std;
int main ()
{
    int n ;
    cout<<"enter the value of n \n";
    cin>>n;
    int arr[n],*p;
    p=arr;
    cout<<"enter the elements \n";
    for (int i = 0; i < n; i++)
    {
        cin>>*(p+i);
    }
    cout<<"your array is \n";
    for (int i = 0; i < n; i++)
    {
        cout<<*(p+i)<<" ";
    }
    return 0 ;
}
*/
// #include <iostream>
// using namespace std;
// int main ()
// {
//     char a[20];
//     int i ;
//     for ( i = 0; i < 10; i++)
//     *(a+i) = 65 + i;
//     //*(a+i) = '\0';
//     cout<< a;
//     return 0 ;
// }
// #include <iostream>
// using namespace std;
// void sum(int a, int b)
// {
//     cout << "sum is " << (a + b) << endl;
// }
// void sum(float a, float b)
// {
//     cout << "sum is " << (a + b) << endl;
// }
// int main()
// {
//     sum(2, 3);
//     sum(5.5f, 2.3f);
//     return 0;
// }
