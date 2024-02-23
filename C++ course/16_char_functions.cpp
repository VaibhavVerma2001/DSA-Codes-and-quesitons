//char functions
/*
#include <iostream>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[]) {
    char c ='a',d='A';
    //converting characters
    cout<<tolower(d)<<endl;
    cout<<toupper(c)<<endl;
    //testing characters
    cout<<isalpha(c)<<endl;
    cout<<isalnum(c)<<endl;
    cout<<islower(c)<<endl;
    cout<<isprint(c)<<endl;
    cout<<ispunct(c)<<endl;
    cout<<isupper(c)<<endl;
    cout<<isspace(c)<<endl;
    return 0;
}
*/
// string declaration
#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char const *argv[]) {
    char a[]="franz";
    a[5]='a';//problem bec last space is for null character
    cout<<a<<endl;
    char b[8]="franz";
    b[5]='y';//ok, bec 3 spaces are free here
    cout<<b<<endl;
    char c[8];
    //c="franz"; // error
    cout<<strcpy(c,"franz")<<endl;//ok
    //string functions
    char x[]="vaibhav" , y[]="verma";
    //cout<<strcpy(x,y)<<endl;//copies y to x
    //cout<<strcat(x,y)<<endl;//combines y to x
    //cout<<strcmp(x,y)<<endl;//compares x and y
    //cout<<strlen(x)<<endl;//counts letter
    //cout<<strrev(x)<<endl;//reverses string
    cout<<strupr(x)<<endl;//coverts into upper case
    cout<<strlwr(x)<<endl;//again coverts to lower case
    return 0;
}
