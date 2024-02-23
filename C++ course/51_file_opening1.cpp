// method 1 -> opening a file using constructor

// i) - opening file using constructor and writing to it
/*
#include<iostream>
#include<fstream>
using namespace std;

int main ()
{
    ofstream out("my_file1.txt"); // out is constructor of ofstream class 
                      // in place of out we can write any name of object
    
    // writing directly 
    out<<"hi we are writing in a file "<<endl; // out is object now for file 
     
    // writing using string  
    string str1 = "writing in a file using string ";
    out<<str1<<endl; // writes str1 in a file 

    // taking info. from user and writing in a file 
    cout<<"enter what u want to insert in a file "<<endl;
    string str2 ;
    getline(cin,str2);
    out<<str2;
    out.close(); //closes file
    return 0;
}
*/

// ii) - opening file using constructor and reading from it
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream in("my_file2.txt"); //in is constructor now of ifsream class
                        // or we can write any other name instead of in
    string str1 , str2;
    //in>>str; only first word will print , as it does not read spaces
    getline(in, str1); // in is now object for reading from file
                      // getline () will read one line now from file
    getline(in, str2);// it will print line 2                   
    cout << "this is written inside file : " << endl;
    cout << str1<<endl;
    cout << str2<<endl;
    in.close(); //closes file
    return 0;
}
*/

// method 2 -> using member functios open () of the class fstream

//i) - writting in a file
/* 
#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
    ofstream out; //out is object now 
    out.open("my_file3.txt"); // open () opens file
    out<<"writting in a file "<<endl;
    out.close(); //closes file
    return 0 ;
}
*/

//ii)- reading from a file
/*
#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
    ifstream in; //out is object now 
    in.open("my_file4.txt"); // open () opens file
    string str;
    getline(in,str);
    cout<<str;
    in.close(); //closes file
    return 0 ;
}
*/

// program to  read and write same file
/*
#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
    ofstream out; //out is object now 
    out.open("my_file3.txt"); // open () opens file
    out<<"i am writting in a file "<<endl;
    out.close(); //closes file
    ifstream in; //out is object now 
    in.open("my_file3.txt"); // open () opens file
    string str;
    getline(in,str);
    cout<<"this was written inside file :"<<endl;
    cout<<str;
    in.close();
    return 0 ;
}
*/

// Program to read multiple lines from a file using eof() function 

#include<iostream>
#include<fstream>

using namespace std ;

int main ()
{
    ofstream fileout ;
    fileout.open("my_file3.txt");
    fileout<<"this is line 1 "<<endl;
    fileout<<"this is line 2 "<<endl;
    fileout<<"this is line 3 "<<endl;
    fileout<<"this is line 4 "<<endl;
    fileout<<"this is line 5 "<<endl;
    fileout.close();

    ifstream filein ;
    filein.open("my_file3.txt");
    string str;
    cout<<"this was written in file :\n";
    while (filein.eof() ==0) //using end of file function 
    {
        getline(filein,str);
        cout<<str<<endl;
    }
   
    return 0;
}