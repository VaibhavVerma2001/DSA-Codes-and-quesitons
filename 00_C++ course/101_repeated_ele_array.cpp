// repeated elements
/*
#include<iostream>
using namespace std ;
int main ()
{
    int n ;
    cout<<"enter n \n";
    cin>>n;
    int arr[n];
    cout<<"enter elements \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"repeated elements are \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(arr[i]==arr[j])
            {
                cout<<arr[j]<<" ";
            }
        }
    }
    return 0 ;
}
*/

//find first repeated element

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main ()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    vector <int > v(n);
    cout<<"enter values \n";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    cout<<"first repeated element is : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i]==v[j])
            {
                cout<<v[i]<<" ";
            }
           
        }  
        break; //breaks loops after first repeating element found
    }
    return 0 ;
}


// smallest number which is repeated
// approach - 1 -> first sort in ascending order 
// 2-> then break loop if any element is repeated 
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std ;

int main ()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    vector <int > v(n);
    cout<<"enter values \n";
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }
    sort(v.begin() , v.end()); // sorted in ascending order
    cout<<"first repeated element is : \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(v[i]==v[j])
            {
                cout<<v[i]<<" ";
            }
           
        }  
        break; //breaks loops after first repeating element found
    }
    return 0 ;
}
*/