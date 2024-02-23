//-> function objects or functors 
// A function object, or functor, is any type that implements operator(). This operator is referred to as the call operator or sometimes the application operator. The C++ Standard Library uses function objects primarily as sorting criteria for containers and in algorithms.
//-> <algorithm> library-STL has an ocean of algorithms, for all < algorithm > library functions Some of the most used algorithms on vectors and most useful one’s in Competitive Programming are mentioned as follows :
//1- sort(first_iterator, last_iterator) – To sort the given vector.
//2- reverse(first_iterator, last_iterator) – To reverse a vector.
//3- *max_element (first_iterator, last_iterator) – To find the maximum element of a vector.
//4- *min_element (first_iterator, last_iterator) – To find the minimum element of a vector.
//5- accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements

/*
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric> // this is used for accumulate

using namespace std;
int main ()
{
    int n;
    cout<<"enter the value] of n"<<endl;
    cin>>n;
    vector <int> v(n);
    cout<<"enter the values "<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<"initial  values are : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;

    // sorting in ascending order 
    sort(v.begin(),v.end());
    cout<<"values after sorting : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;   

    //reversing vector
    reverse(v.begin(),v.end());
    cout<<"values after reversing : "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    
    // max , min  of elements
    cout<<"maximum element is : " <<*max_element(v.begin(),v.end())<<endl;
    cout<<"minimum element is : " <<*min_element(v.begin(),v.end())<<endl;
    
    // to find sum of elements  (accumulate () included in <numeric> header file)
    cout<<"sum of elements  is : "<< accumulate(v.begin(), v.end(),0);
    return 0;
}
*/

// 6.count(first_iterator, last_iterator,x) – To count the occurrences of x in vector.
// 7. find(first_iterator, last_iterator, x) – Returns an iterator to the first occurence of x in vector and points to last address of vector ((name_of_vector).end()) if element is not present in vector.
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main ()
{
    vector <int> v = {10,20,30,20,50,60};
    
    //to count how many times a given value is repeated 
    cout<<"20 is repeated for times : "<<count(v.begin(),v.end(),20)<<endl;

    // find() returns iterator to last address if
    // element not present
    find(v.begin(), v.end(),20) != v.end()?cout << "\nElement found":cout << "\nElement not found";
    find(v.begin(), v.end(),5) != v.end()?cout << "\nElement found":cout << "\nElement not found";
    return 0;
}
*/
//8- arr.erase(position to be deleted) – This erases selected element in vector and shifts and resizes the vector elements accordingly.
//9- arr.erase(unique(arr.begin(),arr.end()),arr.end()) – This erases the duplicate occurrences in sorted vector in a single line.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    vector <int> v = {10,20,30,40,20,50,40,60,20};
    vector <int> :: iterator it = v.begin();
    v.erase(it+2); // deletes element at i = 2
    cout<<"vector after performing operation is :"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end());// we must sort vector first for using this
    v.erase(unique(v.begin(),v.end()),v.end());//deletes repeated element 
    cout<<"vector after performing operation is :"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}