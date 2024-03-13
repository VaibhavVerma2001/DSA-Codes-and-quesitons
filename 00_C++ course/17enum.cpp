/* Enumerated type (enumeration) is a user-defined data type which can be assigned some limited values. These values are defined by the programmer at the time of declaring the enumerated type.
 When we assign a float value in a character value then compiler generates an error in the same way if we try to assign any other value to the enumerated data types the compiler generates an error. Enumerator types of values are also known as enumerators. It is also assigned by zero the same as the array. It can also be used with switch statements.
*/
#include<iostream>
using namespace std;
enum direction {east , west , north ,south  }; //by defeault it will assign 
                                               //value from 0 
int main ()
{
    direction dir1,dir2,dir3,dir4;
    dir1 = east;
    dir2 = west;
    dir3 = north;
    dir4 = south;
    cout<<dir1<<endl; // 0 printed
    cout<<dir2<<endl; // 1 printed
    cout<<dir3<<endl; // 2 printed
    cout<<dir4;       // 3 printed
    return 0 ;
}