// pointers
/*
#include <iostream>
using namespace std;
int main ()
{
   int a =5;
   int *p=&a;
   cout<<a<<endl//value of a
   <<&a<<endl //address of a
   <<*p<<endl // value at address stored by pointer p
   <<&p<<endl; // address of pointer p
   // overwriting
   *p=10;// now a become 10 as *p == a
   cout<<a<<endl
   <<*p;
   return 0;
}
*/
/* new and delete keyword-->
* The main difference between new and delete operator in C++ is that
new is used to allocate memory for an object or an array while,
delete is used to deallocate the memory allocated using the new operator.
There are two types of memory as static and dynamic memory.
* Delete is an operator that is used to destroy array and non-array(pointer)
  objects which are created by new expression.
1- Delete can be used by either using Delete operator or Delete [ ] operator.
2- New operator is used for dynamic memory allocation which puts variables on
 heap memory.
*/
/*
#include <iostream>
using namespace std;
int main ()
{
   int *p = new int (5);
   cout<<*p<<endl;
   float *q = new float(50.72);
   cout<<*q<<endl;
   int *arr = new int[3]; // allocated memory for array
   arr[0]=10;
   arr[1]=20;
   arr[2]=30;
   cout<<arr[0]<<endl
   <<arr[1]<<endl
   <<arr[2]<<endl;
   //delete
   delete arr ; //or delete[] arr ;// deletes allocated memory
   cout<<arr[0]<<endl//garbage value
   <<arr[1]<<endl//garbage value
   <<arr[2]<<endl;//garbage value
};
*/
// program to take and print array using DMA
#include <iostream>
using namespace std;
int main ()
{
    int n;
    cout<<"enter no. of elements"<<endl;
    cin>>n;
    int *p = new int [n];
    cout<<"enter the elements"<<endl;
    for(int i=0; i<n; i++)
    {
      cin>>*(p+i);//or p[i],name of array is pointer means pointer name is array
    }
    cout<<"you entered the elements"<<endl;
    for(int i=0; i<n; i++)
    {
      cout<<*(p+i)<<endl;// name of array is pointer means pointer name is array
// or cout<< p[i];
    }
    delete p; // or delete [] p ;
    return 0;
}
