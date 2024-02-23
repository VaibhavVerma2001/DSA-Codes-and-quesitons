// string class
//1- push_back() and pop_back()
/*
#include<iostream>
#include<cstring> // or <string>
using namespace std;
int main ()
{
    string name ="vaibhav" ;
    cout<<"initial string is : "<<name<<endl;
	name.push_back('@'); // push a char to end of string 
	cout<<"after push_back() string is : "<<name<<endl;
    name.pop_back(); // removes last char from string 
	cout<<"after pop_back() string is : "<<name<<endl;
	return 0;
}
*/
//2- append() - it concatenete string , like strcat() function
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello ";
	// s1.append("world");// adds world at the end of s1
	// cout<<s1;

	 string s2 = "world";
	// s1.append(s2);// adds s2 at the end of s1
	// cout<<s1;

	s1 = s1+s2; // adds s1 and s2
	cout<<s1;
	return 0 ;
}
*/
//3- insert() - it inserts string at given index
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello ";
	s1.insert(2,"world"); // inserts world or any other string at i =2
	cout<<s1;
	return 0 ;
}
*/
//4- replace() - first it deletes the value from staring index to given length
//then then inserts new string
/*
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	string s1 = "hello ";
	s1.replace(2, 2, "a"); //from i=2 to lenght deletes value then inserts a
	cout << s1 << endl;
	string s2 = "world";
	s2.replace(1, 3, "b"); //from i=1 to lenght 3 deletes value then inserts b
	cout << s2 << endl;
	string s3 = "world";
	s3.replace(1, 3, "how are you"); //from i=1 to lenght 3 deletes value then inserts how are you
	cout << s3;
	return 0;
}
*/
//5- erase() - erases complete string
//note -> or we can pass position also which part we want to erase 
//ex -> str.erase(1,3); means it erases 3 characters from i =1 
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello";
	cout<<s1<<endl;
	s1.erase(); // erases complete string
	cout<<s1;
	return 0 ;
}
*/
//6- find() - returns the first i th value where the given string is found
// and return -1 if string is not found
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello y how are you";
	cout<<s1.find("are")<<endl;//return i where are is found first time
	cout<<s1.find("o")<<endl;//return i where o is found first time
	cout<<s1.find("you")<<endl;//return i you are is found first time
	return 0 ;
}
*/
//7- rfind() - work is same as find() , but it finds from reverse of string
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello you how are you";
	cout<<s1.rfind("are")<<endl;//return i where are is found first time from end 
	cout<<s1.rfind("o")<<endl;//return i where o is found first time from end 
	cout<<s1.rfind("you")<<endl;//return i you are is found first time from end 
	return 0 ;
}
*/
//8- compare() - compares ascii values of 2 strings 
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello";
	string s2 = "world";
	string s3 = "how are you";
    cout<<s1.compare(s2)<<endl;//-1 pronted
    cout<<s1.compare(s3)<<endl;//-1 pronted
    cout<<s2.compare(s1)<<endl;//1 pronted
    cout<<s2.compare(s3)<<endl;//1 pronted
    cout<<s3.compare(s1)<<endl;//1 pronted
    cout<<s3.compare(s2)<<endl;//-1 pronted
	return 0 ;
}
*/
//9- c_str() - converts string to char array
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello";
	char s2[20];
	strcpy(s2,s1.c_str()); // coverts string into char array and copies to s2
	cout<<s2;
	return 0 ;
}
*/
//10- size() - returns the size of string (no. of letters )
/*
#include<iostream>
#include<cstring>
using namespace std;
int main ()
{
	string s1 = "hello";
	string s2 = "how are you";
	cout<<s1.size()<<endl;
	cout<<s2.size()<<endl;
	return 0 ;
}
*/

//10- In C++, std::substr() is a predefined function used for string handling. string.h is the header file required for string functions.

// This function takes two values pos and len as an argument and returns a newly constructed string object with its value initialized to a copy of a sub-string of this object. Copying of string start from pos and done till pos+len means [pos, pos+len).

// Syntax:

// string substr (size_t pos, size_t len) const;
// Parameters:
// pos: Position of the first character to be copied.
// len: Length of the sub-string.
// size_t: It is an unsigned integral type.

// Return value: It returns a string object.
/*
#include <cstring>
#include <iostream>
using namespace std;
  
int main()
{
    // Take any string
    string s1 = "Geeks";
  
    // Copy three characters of s1 (starting 
    // from position 1)
    string r = s1.substr(1, 3);
  
    // prints the result
    cout << "String is: " << r;
  
    return 0;
}
*/

// Applications :

// How to get sub-string after a character?
// In this a string and a character is given and you have to print the sub-string followed by the given character.
// Extract everything after the “:” in the string “dog:cat”.
/*
#include <string.h>
#include <iostream>
using namespace std;
  
int main()
{
    // Take any string
    string s = "dog:cat";
  
    // Find position of ':' using find()
    int pos = s.find(":");
    cout<<pos<<endl;
    // Copy substring after pos
    string sub = s.substr(pos + 1);
  
    // prints the result
    cout << "String is: " << sub;
  
    return 0;
}
*/
// 62. Write a C++ program to create a new string without the first and last character of a given string of length atleast two. Go to the editor
// Sample Input:
// "Hello"
// "Hi"
// "Python"
// Sample Output:
// ell
// ytho
// Click me to see the sample solution
/*
#include<iostream>
using namespace std ;

int main ()
{
    cout<<"enter string \n";
    string str;
    getline(cin,str);
    cout<<str.substr(1,str.length() - 2 );
    return 0 ;
}
*/

// 63. Write a C++ program to create a new string from two given string one is shorter and another is longer. The format of the new string will be long string + short string + long string. Go to the editor
// Sample Input:
// "Hello", "Hi"
// "JS", "Python"
// Sample Output:
// HelloHiHello
// PythonJSPython
// Click me to see the sample solution
/*
#include <iostream>
using namespace std;
string get(string a, string b)
{
   if (a.length() > b.length())
   {
     return a + b + a;
   }
   else
   {
     return b + a + b;
   }
}
int main()
{
    string s1, s2;
    cout<<"enter fisrt string \n";
    getline(cin,s1);
    cout<<"enter second string \n";
    getline(cin,s2);
    cout<<get(s1,s2);
    return 0;
}
*/

// Write a C++ program to create a new string of the first half of a given string of even length. Go to the editor
// Sample Input:
// "Hello"
// "Hi"
// Sample Output:
// He
// H

#include<iostream>
using namespace std ;


int main ()
{
    string str;
    getline(cin,str);
    int size = str.length() / 2;
    cout<<str.substr(0,size);

    return 0 ;
}