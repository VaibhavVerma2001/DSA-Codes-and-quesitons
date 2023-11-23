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


//delete at head
void deleteAtPos(node * &head, node * &tail, int pos){
    if(head == NULL){
        cout<<"Already empty linked list"<<endl;
        return;
    }

    // when there is only 1 node
    if(head->next == NULL){
        cout<<"Only One node "<<endl;
        node *p = head;
        tail = NULL;
        head = NULL;
        delete p;
        return ;
    }

    //delete from head
    if(pos == 1){
        cout<<"deleting head node "<<endl;
        node * p = head;
        head = head->next;
        head->prev = NULL;
        delete p;
        return ;
    }

    // delete at given pos
    int len = getLength(head);

    // means last node
    if(pos == len){
        cout<<"pos = length, so deleting last node"<<endl;
        node *p = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete p;
    }

    else if(pos > len){
        cout<<"That pos does not exists"<<endl;
    }

    else{
        int i = 1;
        node *curr = head;
        while(i != pos && curr != NULL){
            i++;
            curr = curr->next;
        }
        node *prevnode = curr->prev;

        prevnode->next = curr->next;
        curr->next->prev  = prevnode;

        delete curr;
    }
}



int main ()
{
    node *head = NULL, *tail = NULL;

    //inserting at tail
    insertAtTail(head,tail,10);
    insertAtTail(head,tail,20);
    insertAtTail(head,tail,30);
    insertAtTail(head,tail,40);
    insertAtTail(head,tail,50);
    insertAtTail(head,tail,60);
    print(head);


    // deleting from head position
    deleteAtPos(head,tail,1);
    print(head);


    deleteAtPos(head,tail,5);
    print(head);

    deleteAtPos(head,tail,3);
    print(head);
    
    deleteAtPos(head,tail,2);
    print(head);


    return 0 ;
}