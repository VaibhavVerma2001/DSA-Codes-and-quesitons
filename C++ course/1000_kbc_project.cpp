#include <iostream>
using namespace std;

int main()
{
    cout<<endl;
    cout<<endl;
    cout << "****************************************** WELCOME TO CSE KE YODHA ****************************************" << endl;
    cout << "ENTER YOUR NAME \n";
    static int quesno = 1;
    static int count = 0;
    string name;
    getline(cin, name);
    cout << "HELLO, " << name << " THANKS FOR SHOWING INTEREST IN OUR GAME .\nSO BEFORE ENTERING THE GAME , HERE SOME RULES OF OUR GAME \n";
    cout << "RULE 1 :- YOU WILL BE GIVEN 10 MCQ's 4 OPTIONS , SELECT CORRECT OPTION ACCORDING TO YOUR KNOWLEDGE \n";
    cout << "RULE 2 :- YOU WILL GET 10 POINTS FOR EACH CORRECT ANSWER , SO MAXIMUM 100 MARKS FOR ALL CORRECT ANSWERS\n";
    cout<<"RULE 3 :- IF YOU SCORE 100 POINTS , THEN YOU WILL BECOME CSE KA YODHA\n"<<endl;
    cout << "TYPE 1 IF YOU WANT TO CONTINUE , ELSE TYPE 0 TO EXIT  \n"; //IF user types 1 we enter game //1st IF
    bool ans;
    cin >> ans;
    if (ans == 1) //game begins if user enters yes
    {
        cout << "\n!!!  WELOME TO THE GAME  !!!\n"<<endl;
        char option;
        { //enters ques 1      

            cout << "HERE COMES QUESTION " << quesno<< endl<<endl;
            cout << "Which of the following is the correct syntax of including a user defined header files in C++? \na) #include <userdefined.h> \nb) #include <userdefined>\nc) #include''userdefined''\nd) #include [userdefined]  " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'c'|| option =='C')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-1

        { //enters ques 2 
;
            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which of the following is a correct identifier in C++?\na) 7var_name\nb) 7VARNAME\nc) VAR_1234\nd) $var_name  " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'c'|| option =='C')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-2

        { //enters ques 3 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which of the following is called address operator?\na) *\nb) &\nc) _\nd) %  " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'b'|| option =='B')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-3

        { //enters ques 4 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which of the following is used for comments in C++?\na) // comment\nb) /* comment */\nc) both // comment or /* comment */\nd) // comment */" << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'c'|| option =='C')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-4

        { //enters ques 5 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "What are the actual parameters in C++?\na) Parameters with which functions are called\nb) Parameters which are used in the definition of a function\nc) Variables other than passed parameters in a function\nd) Variables that are never used in the function " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'a'|| option =='A')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-5

        { //enters ques 6 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << " What are the formal parameters in C++?\na) Parameters with which functions are called\nb) Parameters which are used in the definition of the function\nc) Variables other than passed parameters in a function\nd) Variables that are never used in the function " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'b'|| option =='B')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-6

        { //enters ques 7 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which function is used to read a single character from the console in C++?\na) cin.get(ch)\nb) getline(ch)\nc) read(ch)\nd) scanf(ch) " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'a'|| option =='A')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-7

        { //enters ques 8

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which of the following is called extraction/get from operator?\na) <<\nb) >>\nc) >\nd) < " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'b'|| option =='B')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-8

        { //enters ques 9 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Who created C++?\na) Bjarne Stroustrup\nb) Dennis Ritchie\nc) Ken Thompson\nd) Brian Kernighan " << endl;
            cout << "GIVE YOUR ANSWER\n";
            cin >> option;
            if (option == 'a'|| option =='A')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-9

        { //enters ques 10 

            cout << "\nHERE COMES QUESTION " << quesno<< endl;
            cout << "Which of the following is called insertion/put to operator?\na) <<\nb) >>\nc) >\nd) <"<<endl;
            cin >> option;
            if (option == 'a'|| option =='A')
            {
                cout<<"CORRECT ANSWER\n";
                count++;
            }
            else
            {
                cout<<"INCORRECT ANSWER\n";
            }
            quesno++;
        }  //exit of quest-10


    }
    else // if user enters 0
    {
        cout <<"TUMSE KUCHH NA HO PAYEGA \n";
    }
    int score = 10*count;
    if(score<=40)
    {
        cout<<"YOU NEED TO WORK HARD , YOUR SCORE IS :  "<<score<<endl;
    }
    else if(score>40 &&score <=90)
    {
        cout<<"GOOD JOB, YOUR SCORE IS :  "<<score<<endl;
    }
    else
    {
        cout<<"CONGRATULATIONS !!! \nYOUR SCORE IS : "<<score<<" YOU ARE CSE KA YODHA\n";
    }
    cout<<"THANKS FOR PLAYING , GOOD LUCK !";
    return 0;
}