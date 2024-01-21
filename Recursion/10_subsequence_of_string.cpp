// Q - Given a string, find all its subsequences
// IP 1 -> str = "abc"
// OP -> ["a" , "b" , "c" , "ab" , "bc" ,"ac" , "abc", ""] -> 8 subseq.
// therefore total subseq. = 2 ^ n


// INCLUDE - EXCLUDE PATTERN
// At each index we have 2 choices, either include that character or exclude that

#include<iostream>
#include<string>
using namespace std ;


// str is input string, output string contains output , initially empty, i is current index
void findSubSeq(string str, string output, int i){
    // BC
    // in this case ans is build in output string
    if(i>= str.length()){
        // -> to see output clealry
        cout<<"->"<<output<<endl;
        return ;
    }

    char ch = str[i];

    // exclude
    findSubSeq(str,output,i+1);

    // include
    // include char ch in output string
    output.push_back(ch);
    findSubSeq(str,output,i+1);





    // Method 2 - 
    // Note if we include first instead of exclude then we need to pop that element before exclude function call also

    // include
    // output.push_back(ch);
    // findSubSeq(str,output,i+1);

    // // exclude
    // output.pop_back();
    // findSubSeq(str,output,i+1);

}



int main ()
{
    string str = "abc";
    findSubSeq(str,"",0);
    return 0 ;
}

