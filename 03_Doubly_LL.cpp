#include<iostream>
using namespace std ;

class node{
    public:
    int data;
    node *prev;
    node *next;

    node(){
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};


void print(node *head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void printReverse(node *tail){
    while(tail != NULL){
        cout<<tail->data<<" ";
        tail = tail->prev;
    }
    cout<<endl;
}


int getLength(node *head){
    node *temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//insert at head
void insertAtHead(node * &head , node * &tail, int data){
    if(head == NULL){
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
        return;
    }
    node *newnode = new node(data);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}


void insertAtTail(node * &head, node *&tail, int data){
    if(head == NULL){
        node *newnode = new node(data);
        head = newnode;
        tail = newnode;
    }
    else{
        node *newnode = new node(data);
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}


void insertAtPos(node * &head, node *&tail, int data, int pos){
    if(pos == 1 || head == NULL){
        insertAtHead(head,tail,data);
    }
    else if(pos >= getLength(head)){
        insertAtTail(head,tail,data);
    }
    else{
        node *curr = head;
        int val = 1;
        while(val < pos){
            curr = curr->next;
            val++;
        }
        node* prevnode = curr->prev;

        node * newnode = new node(data);
        newnode->prev = prevnode;
        prevnode->next = newnode;
        newnode->next = curr;
        curr->prev = newnode;
    }
}


int main ()
{
    node *head = NULL, *tail = NULL;

    node *first = new node(10);
    // node *second = new node(20);
    // node *third = new node(30);
    // node *forth = new node(40);

    // head =  first;
    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev = second;

    // third->next = forth;
    // forth->prev = third;

    // forth->next = NULL;
    // tail = forth;


    // print(head);
    // printReverse(tail);


    //inserting at head
    // insertAtHead(head,tail,10);
    // insertAtHead(head,tail,20);
    // insertAtHead(head,tail,30);
    // print(head);


    //inserting at tail
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    print(head);


    //inserting at given position -> 1 based index
    // insertAtPos(head,tail,100,1);
    // insertAtPos(head,tail,200,1);
    // print(head);

    // int n = getLength(head);
    // insertAtPos(head,tail,300,n);
    // n = getLength(head);
    // insertAtPos(head,tail,400,n);
    // print(head);

    insertAtPos(head,tail,500,3);
    print(head);
    insertAtPos(head,tail,600,3);
    print(head);


    return 0 ;
}