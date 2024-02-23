//1-> tellg()-
//-defined in istream class
//-returns the position of current character in the input stream

//2-> tellp()-
//-defined in ostream class
//-returns the position of current character in the output stream

// use of tellg() - in reading from a file 
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("my_file6.txt");
    int pos;
    char ch;
    pos = fin.tellg(); // initially pointing i =0
    cout << pos << endl;
    fin >> ch;
    pos = fin.tellg(); // now it points next character i.e; i =1
    cout << pos << endl;
    fin >> ch;
    pos = fin.tellg(); // now it points next character i.e; i =2
    cout << pos << endl;
    fin.close();
    return 0;
}
*/

// use of tellp() - in writting a file 

#include<iostream>
#include<fstream>
using namespace std ;

int main ()
{
    ofstream fout ;
    fout.open("my_file7.txt" , ios :: app);
    int pos ;
    pos = fout.tellp(); // initially it points position = 0 
    cout<<pos<<endl;
    fout<< "vaibhav" ;
    pos = fout.tellp(); // not it points position = 7 
    cout<<pos<<endl;
    fout.close();
    return 0;
}
