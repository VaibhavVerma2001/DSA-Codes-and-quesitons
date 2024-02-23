// passing array in function
// method 1 -> if size is known
/*
#include <iostream>
using namespace std;

void array(int a[])  // or int a[5] 
{
    for (int i = 0; i < 5; i++)
    {
       cout<<a[i]<<" ";
    }
    
}
int main()
{
    int arr[5] = {10,20,30,40,50};
    array(arr); // name of array acts as pointer, if we pass a[2] -> it means add of a[2] will pass in function 
    return 0;
}
*/

//method 2 -> taking size from user 


#include <iostream>
using namespace std;
void array(int a[], int size)  // or int a[5] 
{
    for (int i = 0; i < size; i++)
    {
       cin>>a[i];
    }
    for (int i = 0; i < size; i++)
    {
       cout<<a[i]<<" ";
    }
    
}
int main()
{
    int n ;
    cout<<"enter size of array \n";
    cin>>n;
    int arr[n] ;
    cout<<"enter elements of array \n";
    array(arr , n); // name of array acts as pointer and size of array
    return 0;
}


// passing array as function in class 
/*
#include<iostream>
using namespace std ;

class sum 
{
   int arr[6];
   public :
   void getarray()
   {
       for (int i = 0; i < 6; i++)
       {
           cin>>arr[i];
       }  
   }
   void printarray()
   {
       for (int i = 0; i < 6; i++)
       {
           cout<<arr[i]<<" ";
       }      
   }
 
};
int main ()
{
    sum s1;
    s1.getarray();
    s1.printarray();
    return 0 ;
}
*/