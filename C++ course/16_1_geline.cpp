// if we use getline after >> operators then it will not take string and
// our program terminates , as it reads \n character .
/*
#include <iostream>
using namespace std;

int main() {
    int x , y;
    cout<<"enter 2 numbers \n";
    cin>>x>>y;
    string str;
    cout<<"enter string \n";
    getline(cin,str); // will not take string 
    cout <<x<<" "<<y<<" "<<str;
    return 0;
}
*/

// therefore to solve above problem use cin.ignore()
// cin leaves the newline character in the stream. Adding cin.ignore() to the next line clears/ignores the newline from the stream.
//This is used mainly with combinations of cin and getline.

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "enter 2 numbers \n";
    cin >> x >> y;
    string str;
    cout << "enter string \n";
    cin.ignore();      //
    getline(cin, str); // it will take string now
    cout << x << " " << y << " " << str;
    return 0;
}