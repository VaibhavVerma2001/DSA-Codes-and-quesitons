/* QUIZ 1 ->Given an array of integers, calculate the ratios of its elements
 that are positive, negative, and zero. Print the decimal value of each fraction
  on a new line with  places after the decimal.
  Sample Input

  6
  -4 3 -9 0 4 1
  Sample Output

  0.500000
  0.333333
  0.166667
  Explanation

  There are 3 positive numbers, 2 negative numbers, and 1 zero in the array.
  The proportions of occurrence are positive:3/6=.5 , negative: 2/6 =.333333
  and zeros:1/6 = .166667 .
*/ 
// program ->
/*
#include <iostream>
using namespace std;
int main()
{
  int n;
  cout << "enter value of n" << endl;
  cin >> n;
  int arr[n];
  cout << "enter the elements" << endl;
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int positive = 0, negative = 0, zero = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      zero++;
    }
    if (arr[i] > 0)
    {
      positive++;
    }
    if (arr[i] < 0)
    {
      negative++;
    }
  }
  cout << "positive fraction is : " << (float)positive / n << endl;
  cout << "negative fraction is : " << (float)negative / n << endl;
  cout << "zero fraction is : " << (float)zero / n;
  return 0;
}*/
// size of empty class is always 1 ,bec compi. assigns its address 
/*
#include <iostream>
using namespace std;
class A
{

};
int main ()
{
  cout<<sizeof(A);
}
*/

/*
Given a square matrix, calculate the absolute difference between the sums of its diagonals.
Output Format

Return the absolute difference between the sums of the matrix's two diagonals as a single integer.

Sample Input

3
11 2 4
4 5 6
10 8 -12
Sample Output

15
Explanation

The primary diagonal is:

11
   5
     -12
Sum across the primary diagonal: 11 + 5 - 12 = 4

The secondary diagonal is:

     4
   5
10
Sum across the secondary diagonal: 4 + 5 + 10 = 19
Difference: |4 - 19| = 15
*/
/*
#include<iostream>
#include<cmath>
using namespace std ;

int main ()
{
    int n ;
    cin>>n;
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum1 = 0 , sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i==j)
            {
                sum1 = sum1 + arr[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == n-i-1)
            {
                sum2 = sum2 + arr[i][j];
            }
        }
    }
    int difference = (sum1-sum2);
    cout<<abs(difference);
    return 0 ; 
}
*/


/*Output Format
Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.

Sample Input

6
1 4 6 2 8 9
2
2 4
Sample Output

3
1 8 9
Explanation

The first query is to erase the 2nd element in the vector, which is 4. Then, modifed vector is {1 6 2 8 9}, we want to remove the range of 2~4, which means the 2nd and 3rd elements should be removed. Then 6 and 2 in the modified vector are removed and we finally get {1 8 9}
*/
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n , pos1 , pos2 , pos3 ;
    cin>>n;
    vector <int > v(n) ;
    for (int i =0 ; i< v.size() ; i++)
    {
        cin>>v[i]; //1 4 6 2 8 9 
    } 
    cin>>pos1; //2
    vector <int > :: iterator it = v.begin();
    v.erase(it+ (pos1-1)); // 1 6 2 8 9
    cin>>pos2>>pos3; //2 4 
    v.erase(it + (pos2-1), it + (pos3-1)); // 1 8 9 
    cout<<v.size()<<endl;
    for(int i = 0 ; i <v.size() ; i++)
    {
        cout<<v[i]<<" ";
    }
    return 0;
}
*/


/*Output Format
The code provided in the code editor will use your class template to add/append elements and give the output.

Sample Input

3
string John Doe
int 1 2
float 4.0 1.5
Sample Output

JohnDoe
3
5.5
Explanation

"Doe" when appended with "John" gives "JohnDoe". 2 added to 1 gives 3, and 1.5 added to 4.0 gives 5.5.
*/
/*
#include <iostream>
#include<string>
using namespace std;
template <class X>
class AddElements
{
    X a ,  b;
    public :
    X add(X x , X y )
    {
        a=x , b =y;
        return (a+b);
    }  
};
int main()
{
    int n;
    cout<<"enter test cases : \n";
    cin>>n;
    for (int i = 0; i <n; i++)
    {
        string type ;
        cout<<"enter type for test case "<<i+1<<endl;
        cin>>type;
        if (type == "float")
        {
            double element1 , element2;
            cin>>element1>>element2;
            AddElements <float> a1;
            cout<<a1.add(element1, element2)<<endl;
        }
        else if (type == "int")
        {
            int element1 , element2;
            cin>>element1>>element2;
            AddElements <int> a1;
            cout<<a1.add(element1, element2)<<endl;
        }
        else if (type == "string")
        {
            string element1 , element2;
            cin>>element1>>element2;
            AddElements <string> a1;
            cout<<a1.add(element1, element2)<<endl;
        }

    }
    
    return 0;
}
*/
// Write a C++ program to which replace all the words "dog" with "cat" Go to the editor
// Sample Text: The quick brown fox jumps over the lazy dog. You can assume that the number of characters in a text is less than or equal to 1000.
/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cin.getline(str, 100);
    cout << "you entered \n";
    cout << str << endl;
    for (int i = 0; i < strlen(str); i++)
    {
        for (int j = i + 1; j < strlen(str); j++)
        {
            for (int k = i + 2; k < strlen(str); k++)
            {

                if (str[i] == 'd' && str[j] == 'o' && str[k] == 'g')
                {
                    str[i] = 'c';
                    str[j] = 'a';
                    str[k] = 't';
                }
            }
        }
    }
    cout << "new string is : \n";
    cout << str;

    return 0;
}
*/
/*
#include<iostream>
#include<cstring>
using namespace std ;

int main ()
{
    char str[100];
    cout<<"enter string \n";
    cin>>str;
    for (int  i = 0; i !='\0'; i++)
    {
        cout<<str[i];
    }
    

    return 0 ;
}
*/
/*
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[100];
    cin.getline( str , 100);
    cout << "you entered \n";
    cout << str << endl;
    for (int i = 0; str[i] != '\0' ; i++)
    {
        for (int j = i + 1; str[j] != '\0' ; j++)
        {
            for (int k = i + 2; str[k]  != '\0'; k++)
            {

                if (str[i] == 'd' && str[j] == 'o' && str[k] == 'g')
                {
                    str[i] = 'c';
                    str[j] = 'a';
                    str[k] = 't';
                }
            }
        }
    }
    cout << "new string is : \n";
    cout << str;

    return 0;
}
*/

//arithematic series 
/*
#include<iostream>
using namespace std ;

int main ()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    int arr[n];
    cout<<"enter series \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int d = arr[1] - arr[0]; //common difference
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
           if( (arr[j]-arr[i]) == d )
           {
               count++; //counts common difference 
           }
        }
    }
    if (count == n-1) //common difference should be n-1 times
    {
        cout<<"arithematic series \n";
    }
    else 
    {
        cout<<"not an arithematic series \n";
    }
    
    
    return 0 ;
}
*/

//geometric series
/*
#include<iostream>
using namespace std ;

int main ()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    int arr[n];
    cout<<"enter series \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int r = arr[1]/arr[0]; //common ratio
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
           if( (arr[j]/arr[i]) == r )
           {
               count++; //counts common ratio 
           }
        }
    }
    if (count == n-1) //common ratio should be n-1 times
    {
        cout<<"geometric series \n";
    }
    else 
    {
        cout<<"not an geometric series \n";
    }
    
    
    return 0 ;
}
*/


/*
//to find in ap or gp
#include<iostream>
using namespace std ;

int main ()
{
    int n;
    cout<<"enter n \n";
    cin>>n;
    int arr[n];
    cout<<"enter series \n";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int d = arr[1] - arr[0]; //common difference
    int r = arr[1]/arr[0]; //common ratio
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
           if( (arr[j]-arr[i]) == d )
           {
               count1++; //counts common difference 
           }
           if( (arr[j]/arr[i]) == r )
           {
               count2++; //counts common ratio
           }

        }
    }
    if (count1 == n-1) //common difference should be n-1 times
    {
        cout<<"arithematic series \n";
    }
    else if (count2 == n-1) //common ratio should be n-1 times
    {
        cout<<"geometric series \n";
    }  
    else 
    {
        cout<<"nor arithematic neither geometric series \n";
    }
    
    
    return 0 ;
}
*/

// Write a program in C++ to find the last prime number occur before the entered number. Go to the editor
// Sample Output:
// Input a number to find the last prime number occurs before the number: 50
// 47 is the last prime number before 50
/*
#include<iostream>
using namespace std ;

int main ()
{
    int n ;
    cout<<"input a number \n";
    cin>>n;
    for (int i = n; i >0 ; i--)
    {
        int count =0;
        for (int j = n; j>0; j--)
        {
            if(i%j==0)
            {
                count++;
            }
        }
        if (count==2)
        {
            cout<<i<<" ";
            break;
        }
        
    }
    
    return 0 ;
}
*/

// . Write a C++ program to check if the first appearance of "a" in a given string is immediately followed by another "a". Go to the editor
// Sample Input:
// "caabb"
// "babaaba"
// "aaaaa"
// Sample Output:
// 1
// 0
// 1

#include<iostream>
using namespace std ;
int check(string s)
{
    int count ;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'a')
        {
           count = i;
           break;
        }
    }
    return (s[count+1] == 'a' ) ?  1 : 0;
}
int main ()
{
    for (int  i = 0; i < 3; i++)
    {
        string str;
        cin>>str;
        cout << check(str)<<endl;
    }
    
    return 0 ;
}