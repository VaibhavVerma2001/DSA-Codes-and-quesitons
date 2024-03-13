// we can make out own header file.
// 1-> add .h at the end 
// 2-> define functions in that header file
// 3-> include it using " "
// Enclosing the header file name within double quotes signifies that the header file of C and C++ is located in the present folder you are working with. 
#include<iostream>
#include"myheader.h"
using namespace std ;

int main ()
{
    cout<<add(2,4)<<endl; // defined in myheader.h
    cout<<sub(5,4)<<endl; // defined in myheader.h
    cout<<product(2,4.2)<<endl; // defined in myheader.h
    cout<<divide(8.6,4)<<endl; // defined in myheader.h
    return 0 ;
}