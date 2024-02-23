// we can define namespace in other file and then include them in out program and use them

//method 1 -> without 'using' keyword
// #include<iostream>
// #include"namespace.h"
// using namespace std ;

// int main ()
// {
//     cout<<first::add(5,2)<<endl; //defined in our namespace.h header file
//     cout<<second::mul(5,2)<<endl; //defined in our namespace.h header file
//     return 0 ;
// }

//method 2 -> with 'using' keyword -> then no need to write namespace_name :: function name

#include<iostream>
#include"namespace.h"
using namespace std ;
using namespace first;
using namespace second;
int main ()
{
    cout<<sub(5,2)<<endl; //defined in our namespace.h header file
    cout<<divide(5,2)<<endl; //defined in our namespace.h header file
    return 0;
}