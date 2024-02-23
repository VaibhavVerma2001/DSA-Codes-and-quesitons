//list class -
//1- list class supports a biderectional , linear list
//2- we cant access list randomly like array and vector , i.e; can be accessed onlyfront to back or back to front
//3- include <list> header file
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10, 20, 30, 40, 50};
    //cout<<l1[0];//error : list does not support [] operator ,can be accessed only front to back or back to front
    list<int>::iterator p = l1.begin();//iterator is a pointer(pointing 1st value)
    // while (p!=l1.end())
    // {
    //     cout<<*p<<" ";
    //     p++;
    // }
    // OR
    for (p = l1.begin(); p != l1.end(); p++)
    {
        cout << *p << " ";
    }
    return 0;
}
*/
// 1 - size() - tells no. of values in a list
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10, 20, 30, 40, 50};
    list<string> l2 = {"vaibhav", "amit", "ayush"};
    cout << "size of list 1 is :" << l1.size() << endl;
    cout << "size of list 2 is :" << l2.size() << endl;
    return 0;
}
*/
// 2 - push_back() and push_front() - adds value at end and start of list respectively
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10, 20, 30, 40, 50};
    cout << "size of list 1 is :" << l1.size() << endl;
    l1.push_front(100);
    l1.push_back(200);
    cout << "size of list 1 is :" << l1.size() << endl;
    list <int> :: iterator p = l1.begin();
    while (p!=l1.end())
    {
        cout<<*p <<" ";
        p++;
    }
    return 0;
}
*/
// 3 - pop_back() and pop_front() -> adds value at end and start of list respectively
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10, 20, 30, 40, 50};
    cout << "size of list 1 is :" << l1.size() << endl;
    l1.pop_front();
    l1.pop_back();
    cout << "size of list 1 is :" << l1.size() << endl;
    list <int> :: iterator p = l1.begin();
    while (p!=l1.end())
    {
        cout<<*p <<" ";
        p++;
    }
    return 0;
}
*/
// 4 - sort() -> sorts the elements of the list in ascending order. The order of equal elements is preserved. It uses operator< for comparison
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {20,30,50,10,40};
    cout << "elements before sorting are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    cout<<endl;
    l1.sort();
     cout << "elements after sorting are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    return 0;
}
*/
// 5 - remove() -> it removes the given value from list 
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10,20,30,40,50,60};
    cout << "elements before removing are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    cout<<endl;
    l1.remove(40); // 40 will be removed
    l1.remove(100);// there is no 100 in list, so nothing will be removed
     cout << "elements after removing are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    return 0;
}
*/
// 6 - clear() -> it clear the all  value from list 
/*
#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10,20,30,40,50,60};
    cout << "elements before clear are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    cout<<endl;
    l1.clear(); // all elements will be removed 
     cout << "elements after clear are :" << endl;
    for(auto it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    return 0;
}
*/
// 7 - reverse() -> it reverse the value of list 

#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> l1 = {10,20,30,40,50,60};
    cout << "elements before reverse are :" << endl;
    list <int> :: iterator it;
    for( it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    cout<<endl;
    l1.reverse(); 
     cout << "elements after reverse are :" << endl;
    for(it = l1.begin() ; it != l1.end() ; it++)
    {
        cout<<*it <<" ";
    }
    return 0;
}