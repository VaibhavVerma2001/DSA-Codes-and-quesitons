//1- at() returns the value in the array at the given range
/*
#include <iostream>
#include <array> // array header included 
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55};
    cout << obj1.at(2) << endl; // value at i = 2 
    cout << obj1.at(5) << endl; // i= 5 is out of range so program will terminate
    cout << obj1.at(3); // program terminated so it will not printed also
    return 0;
}
*/
//2- [] operator - use is same as it was for normal arrays
/*
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55};
    cout << obj1[2] << endl; // value at i = 2
    cout << obj1[4] << endl; // value at i = 4
    cout << obj1[5];         // garbage value (i=5 is out of range)
    return 0;
}
*/
//3- front () and back ()
// front () element returns the first element in the array
// back () element returns the last element in the array
/*
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55};
    cout << obj1.front() << endl; // value of first element 
    cout << obj1.back() << endl; //  value of last element 
    array<int, 8> obj2 = {1, 2, 3, 4, 5};//initialised only 5 elements instead of 8
    cout << obj2.front() << endl; // value of first element 
    cout << obj2.back() << endl; //  value of last element i.e i = 7  
    return 0;
}
*/
// 4- fill() ->assigns the given value to every element of the array
/*
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55};
    for ( int i = 0; i < 5; i++)
    {
        cout<<obj1[i] << "  "; // or obj1.at(i)
    }
    cout<<endl;
    obj1.fill(10); //now it overwrites obj1 elements with 10 at each element
    for ( int i = 0; i < 5; i++)
    {
        cout<<obj1[i] << "  "; // or obj1.at(i)
    }
    return 0;
}
*/
//5- swap()-> swaps content of 2 arrays of same data type and same size

#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55};
    array<int, 5> obj2 = {1, 2, 3, 4, 5};
    obj1.swap(obj2); //swaps obj1 and obj2
    for (int i = 0; i < 5; i++)
    {
        cout<< obj1[i]<< "  ";  
    }
    cout<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<< obj2[i]<< "  ";
    }
    return 0;
}

// 6- size() ->returns no. of element present in the array
/*
#include <iostream>
#include <array>
using namespace std;
int main()
{
    array<int, 5> obj1 = {11, 22, 33, 44, 55}; // size is 5
    cout<<"size is : "<<obj1.size()<<endl;
    array<int, 8> obj2 = {1, 2, 3, 4, 5}; //size is 8
    cout<<"size is : "<<obj2.size()<<endl;
    return 0;
}
*/