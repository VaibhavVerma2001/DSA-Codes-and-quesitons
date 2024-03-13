// One of the advantages of C++ over C is Exception Handling. Exceptions are run-time anomalies or abnormal conditions that a program encounters during its execution. There are two types of exceptions: a)Synchronous, b)Asynchronous(Ex:which are beyond the program’s control, Disc failure etc). C++ provides following specialized keywords for this purpose.
// try: represents a block of code that can throw an exception.
// catch: represents a block of code that is executed when a particular exception is thrown.
// throw: Used to throw an exception. Also used to list the exceptions that a function throws, but doesn’t handle itself.

//example 1
/*
#include<iostream>
using namespace std ;

int main ()
{
    int a , b;
    cin>>a>>b;
    int x = (a-b);
    try 
    {
        if ( x!= 0 )
        {
            cout<<"result = "<<a/x;
        }
        else
        {
            throw 0;
            // or
            // throw  ; // not always aompulsary to throw a value , we can write only throw
        }
    } 
    catch ( int a) // not compulsary to write a if we are not using throw value later
    {
        cout<<"exception";
    }
    return 0 ;
}
*/

//example 2
/*
#include <iostream>
using namespace std;

int main()
{
    int x = -1;
    // Some code
    cout << "Before try \n";
    try
    {
        cout << "Inside try \n";
        if (x < 0)
        {
            throw x;
            cout << "After throw (Never executed) \n";
        }
    }
    catch (int x)
    {
        cout << "Exception Caught \n";
    }
    cout << "After catch (Will be executed) \n";
    return 0;
}
*/

// 2) There is a special catch block called ‘catch all’ catch(…) that can be used to catch all types of exceptions. For example, in the following program, an int is thrown as an exception, but there is no catch block for int, so catch(…) block will be executed.
//this should be written at last , otherwise we get error
//example 3

/*
#include<iostream>
using namespace std ;

int main()
{
    try
    {
        throw 10;
    }
    catch (char a) 
    {
        cout<<"exception caught \n";
    }
    catch(...)
    {
        cout<<"default exception \n";
    }
    return 0 ;
}
*/

// 3) If an exception is thrown and not caught anywhere, the program terminates abnormally. For example, in the following program, an int is thrown, but there is no catch block to catch an int .
/*
#include <iostream>
using namespace std;

int main()
{
    try
    {
        throw 10 ;
    }
    catch (char x)
    {
        cout << "Caught ";
    }
    catch (double x)
    {
        cout << "Caught ";
    }
    return 0;
}
*/

// 4) When an exception is thrown, all objects created inside the enclosing try block are destructed before the control is transferred to catch block.
/*
#include <iostream>
using namespace std;

class Test
{
public:
    Test() { cout << "Constructor of Test " << endl; }
    ~Test() { cout << "Destructor of Test " << endl; }
};
int main()
{
    try
    {
        Test t1;
        throw 10;
    }
    catch (int i)
    {
        cout << "Caught " << i << endl;
    }
}
*/


//example to manage error in finding factorial
/*
#include <iostream>
using namespace std;

void factorial(int n)
{
    try
    {
        if (n > 0)
        {
            int fact = 1;
            for (int i = n; i >= 1; i--)
            {
                fact = fact * i;
            }
            cout << "factorial of number is : " << fact;
        }
        else if (n < 0)
        {
            string x = "can't find fact of -ve number ";
            throw x;
        }

        else if (n == 0)
        {
            throw 1;
        }
    }
    catch (int a )
    {
        cout<<"factorial is "<<a;
    }
    catch (string s)
    {
        cout<<s;
    }
}
int main()
{
    int n ;
    cin>>n;
    factorial(n);
    return 0;
}
*/

//example 2  Write a program to create an array of 5 integers. Access this array using index variable. Handle the condition where programmer accidentally accesses any index of array which is out of bound using exception handling.

#include<iostream>
using namespace std ;

int main ()
{
    cout<<"enter no. of elements \n";
    int n ;
    cin>>n;
    int arr[n];
    cout<<"enter values \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"enter ith u want to search \n";
    int i ;
    cin>>i;
    try
    {
        if(i < n)
        cout<<"value at "<<i <<" is : "<<arr[i];
        else
        throw "out of range ";

    }
    catch(const char *e)
    {
        cout<<e;
    }
    
    return 0 ;
}