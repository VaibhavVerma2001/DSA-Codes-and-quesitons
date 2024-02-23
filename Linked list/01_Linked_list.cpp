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

// Insert at head -> if dont want to return and change in actual LL then write as (Node * &head)
void insertAtHead(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

// Insert at tail ->
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // if head null, means insert at head function
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        newNode->next = NULL;
        head = newNode;
        tail = newNode;
    }
    else
    {
        Node *newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        newNode->next = NULL;
    }
}

// Insert after given position -> 1 based index of LL
void insertAtPosition(Node *&head, Node *&tail, int data, int pos)
{
    if (head == NULL || pos <= 0)
    {
        cout << "Empty LL , inserting at head" << endl;
        insertAtHead(head, tail, data);
    }
    else
    {
        int cnt = 1;
        Node *temp = head;
        while (cnt != pos && temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp == NULL)
        {
            cout << "LL has less elements than given pos, so inserting at tail" << endl;
            insertAtTail(head, tail, data);
        }
        else
        {
            Node *newNode = new Node(data);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
}



int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // inserting at head
    // cout << "displaying values after inserting at head : ";
    // insertAtHead(head,tail, 10);
    // insertAtHead(head,tail, 15);
    // insertAtHead(head,tail, 20);
    // display(head);


    // inserting at tail
    cout << "displaying values after inserting at tail : ";
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 15);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 25);
    insertAtTail(head, tail, 30);
    display(head);


    // inserting after given pos (1 index based)
    cout << "displaying values after inserting after pos : ";
    insertAtPosition(head, tail, 50, 0);
    display(head);
    insertAtPosition(head, tail, 100, 2);
    display(head);
    insertAtPosition(head, tail, 120, 5);
    display(head);
    insertAtPosition(head, tail, 150, 15);
    display(head);


   
    return 0;
}