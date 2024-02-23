// file opening modes
// 1 - ios :: out -> output/write
// 2 - ios :: in  -> input/read
// 3 - ios :: app -> append
// 4 - ios :: ate -> update
// 5 - ios :: binary -> binary
/*
#include<iostream>
#include<fstream>
using namespace std;

int main ()
{
    ofstream fout;
    fout.open("my_file5.txt",ios :: out );// ios :: out is exceptional because ofstream class has permission to write a file by default 
    fout<<"i am writting this in file 5";
    fout.close();

    ifstream fin;
    fin.open("my_file5.txt", ios::in);// ios :: in is exceptional because ifstream class has permission to read a file by default
    string str;
    getline(fin,str);
    cout<<"this was written in a file :"<<endl;
    cout<<str;
    fin.close();
    return 0 ;
}
*/

// ios :: app is used to write in a file without erasing previous content of the file
/*
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("my_file5.txt", ios ::app); // ios :: app , this is used to append i.e; if we want to write in a file then previous content of file will not vanish and whatever we write it adds up in the file
    fout << "i am writting this in file 5";
    fout.close();

    ifstream fin;
    fin.open("my_file5.txt");
    string str;
    getline(fin, str);
    cout << "this was written in a file :" << endl;
    cout << str;
    fin.close();
    return 0;
}
*/

// ios :: trunc -> this deletes the previous content of file and replace it with a new one or To truncate an existing file to zero
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream out;
    out.open("my_file7.txt", ios ::trunc); // by default it clears old content and replace it with a new one also
    out << "hi i am writting in a file" << endl;
    return 0;
}