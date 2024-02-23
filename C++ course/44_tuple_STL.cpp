// tuple in STL -> similar to pair but we can pair multiple object 
//1- <tuple> header file must be included
//2- make_tuple () is used to initialize value
//3- get<>() is used to display value
#include<iostream>
#include<tuple>
using namespace std;
int main ()
{
    tuple < string , int , float> T1;
    T1 = make_tuple("Vaibhav verma" , 21 , 200.20);
    cout<<get<0>(T1)<<"  ";
    cout<<get<1>(T1)<<"  ";
    cout<<get<2>(T1);
    return 0 ;
}