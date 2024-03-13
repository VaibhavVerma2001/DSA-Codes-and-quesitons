#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// print LL
void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Insert at tail ->
void insertAtTail(Node *&head, int data)
{
    // if head null, means insert at head function
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while(temp->next !=NULL){
            temp = temp->next;
        }
        Node *newNode = new Node(data);
        temp->next = newNode;
        newNode->next = NULL;
    }
}


// Delete from start
void deleteAtHead(Node * &head){
    if(head == NULL){
        cout<<"Empty Linked list"<<endl;
    }
    else{
        Node *p = head;
        head = head->next;
        delete p;
    }
}

// Delete last node
void deleteAtLast(Node * &head){
    if(head == NULL){
        cout<<"Empty Linked list"<<endl;
    }
    else{
        Node *p = NULL;
        Node *q = head;
        while(q->next !=NULL){
            p = q;
            q = q->next;
        }

        // when there is only 1 node left, then p is null
        if(p == NULL){
            cout<<"Now LL is empty"<<endl;
            head = NULL;
        }
        else{
            p->next = NULL;
        }
        
        delete q;
    }
}


int main()
{
    Node *head = NULL;
    Node *tail = NULL;


    // inserting at tail
    cout << "displaying values after inserting at tail : ";
    insertAtTail(head, 5);
    insertAtTail(head, 10);
    // insertAtTail(head, 15);
    // insertAtTail(head, 20);
    // insertAtTail(head, 25);
    // insertAtTail(head, 30);
    display(head);


    //cout<<"displaying values after deleting from head : ";
    // deleteAtHead(head);
    // display(head);
    // deleteAtHead(head);
    // display(head);

    cout <<"displaying values after deleting from last : ";
    deleteAtLast(head);
    display(head);
    deleteAtLast(head);
    display(head);


    return 0;
}