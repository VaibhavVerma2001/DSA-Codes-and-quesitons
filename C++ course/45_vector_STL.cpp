// vector classes in STL
//1-> it supports dynamic array
//2-> we must include <vector> header file to use this

// some important member functions in vector class
// 1-> [] subscript operator - same use as normal array
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {10, 20, 30};
    cout << v1.capacity() << endl;
    cout << v1[0] << endl;
    cout << v1[1] << endl;
    cout << v1[2] << endl;
    return 0;
}
*/
// 2-> push_back() - used to add value to the end of vector
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {10, 20, 30};
    cout <<"current capacity is : "<< v1.capacity() << endl;
    v1.push_back(40);
    cout <<"current capacity is : "<< v1.capacity() << endl;
    v1.push_back(50);
    cout <<"current capacity is : "<< v1.capacity() << endl;
    
    for (int i = 0; i < 5; i++)
    {
        cout<<v1[i]<<" ";
    }
    
    return 0;
}
*/
// 3 - pop_back() -> it removes the last element
// but it does not reduces capacity
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {10, 20, 30};
    cout << "current capacity is : " << v1.capacity() << endl;
    v1.push_back(40);
    cout << "current capacity is : " << v1.capacity() << endl;
    v1.push_back(50);
    cout << "current capacity is : " << v1.capacity() << endl;
    v1.pop_back();
    v1.pop_back();
    v1.pop_back();
    cout << "current capacity is : " << v1.capacity() << endl; //capacity will not
    return 0;                                                  //reduce
}
*/
// 4 - size() -> it returns no. of element stored in a vector
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {10, 20, 30};
    cout <<"current capacity is : " << v1.capacity() << endl;
    cout<<"current size is : "<<v1.size()<<endl;
    v1.push_back(40); // now 4 elements
    cout <<"current capacity is : " << v1.capacity() << endl;
    cout<<"current size is : "<<v1.size()<<endl;
    v1.pop_back(); // now 3 elements
    v1.pop_back(); // now 2 elements
    cout <<"current capacity is : " << v1.capacity() << endl;
    cout<<"current size is : "<<v1.size()<<endl;
    return 0;                                                  
}
*/
// 5- clear () ->it removes all elements from vector
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> v1 = {10, 20, 30};
    cout <<"capacity is : "<< v1.capacity() << endl;
    cout <<"size is : "<< v1.size() << endl;
    v1.push_back(40);
    cout <<"capacity is : "<< v1.capacity() << endl;
    cout <<"size is : "<< v1.size() << endl;
    v1.clear(); // it will clear all elements 
    cout <<"capacity is : "<< v1.capacity() << endl;//capacity will not be 0
    cout <<"size is : "<< v1.size() << endl; // size will be 0 now
    return 0;
}
*/
// 6-> at() - this method is same as it was in array class
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1 = {10, 20, 30};
    cout << v1.capacity() << endl;
    cout << v1.at(0) << endl;
    cout << v1.at(1) << endl;
    cout << v1.at(2) << endl;
    return 0;
}
*/
// 7-> front() and back() returns first and last element of vector 
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1 = {10, 20, 30};
    cout << v1.capacity() << endl;
    cout << v1.front() << endl;
    cout << v1.back() << endl;
    return 0;
}
*/
// 8-> insert()
// std::vector::insert() is a built-in function in C++ STL which inserts new  before the element at the specified position, effectively increasing  the container size by the number of elements inserted.
// Syntax:
// vector_name.insert (position, val)
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1 = {10, 20, 30,40 ,50};
    vector <int > :: iterator it =  v1.begin();
    v1.insert(it+3,100);
    //v1.insert(it,50);// this means it add 60 to i = 0.
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    return 0;
}
*/
// 9-> swap() - this swaps 2 vector of same data type. but size may differ.
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1 = {10, 20, 30,40,50};
    vector <int> v2 = {1, 2, 3,4,5,6,7,8};
    v1.swap(v2);
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
    for (int i = 0; i < v2.size(); i++)
    {
        cout<<v2[i]<<" ";
    }
    return 0;
}
*/
// wap to take and display values from user using vectors
/*
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n ;
    cout<<"enter the values of n \n"; 
    cin>>n;
    vector<int> v1 (n);
    cout<<"enter the values \n";
    for (int i = 0; i < v1.size(); i++) // or n instead of v1.size()
    {
        cin>>v1[i];
    }
    for (int i = 0; i < v1.size(); i++) // or n instead of v1.size() 
    {
        cout<<v1[i]<<" ";
    }
    return 0;
}
*/
// 10-> erase() - erases the value at given ith position
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> v1= {10, 20, 30,40 ,50,60,70,80};
    vector <int > :: iterator it =  v1.begin();
    //v1.erase(it);
    // v1.erase(it+1);//removes i= 1 element
    v1.erase(it+1,it+3);//erases from i = 1 to i =3(not included)
    for (int i = 0; i < v1.size(); i++)
    {
        cout<<v1[i]<<" ";
    }
    return 0;
}
