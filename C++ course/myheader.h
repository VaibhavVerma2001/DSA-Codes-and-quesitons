// defining functions
//1 - if we dont want to use cout then ->
// float add(float a, float b)
// {
//     return (a+b);
// }
// float sub(float a, float b)
// {
//     return (a-b);
// }
// float product(float a, float b)
// {
//     return (a*b);
// }
// float divide(float a, float b)
// {
//     return (a/b);
// }

//2- if we want to use cout then include iostream 
#include<iostream>
using namespace std;
float add(float a , float b)
{
    cout<<"using own header file sum is : ";
    return a+b;
}
float sub(float a , float b)
{
    cout<<"using own header file substraction is : ";
    return a-b;
}
float product(float a , float b)
{
    cout<<"using own header file product is : ";
    return a*b;
}
float divide(float a , float b)
{
    cout<<"using own header file division is : ";
    return a/b;
}