#include <bits/stdc++.h>

using namespace std;

struct node
{
    int data;
    struct node *next;
};

node *head;
////////////////////////////////////////////////////////////////////////
void insertatfirst()
{
    int x;
    cout << "Enter the element: ";
    cin >> x;
    cout << endl;
    node *temp = new node();
    temp->data = x;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    temp->next = head;
    head = temp;
}

void insertatlast()
{
    int x;
    cout << "Enter the element: ";
    cin >> x;
    cout << endl;
    node *ptr = head, *temp = new node();
    temp->data = x;
    temp->next = NULL;
    if (head != NULL)
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
        temp->next = NULL;
        return;
    }
    else
    {
        head = temp;
    }
}

void insertatdesired()
{
    int x, y;
    cout << "Enter the element: ";
    cin >> x;
    cout << endl;
    cout << "Enter the position: ";
    cin >> y;
    node *ptr = head, *temp = new node();
    temp->data = x;
    if(y==1){       //head == NULL 
        temp->next = head;
        head = temp;
        return;
    }
    y = y - 1;
    cout << endl; 
    while (--y)
    {
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    return;
}

///////////////////////////////////////////////////////////////////

void deleteatfirst()
{
    if (head == NULL)
    {
        cout << "Can't delete an empty linked_list" << endl;
        return;
    }
    else
    {
        head = head->next;
    }
}

void deleteatlast()
{
    node *ptr = head;
    node *qtr = ptr->next;
    if (head == NULL)
    {
        cout << "Can't delete an empty linked_list" << endl;
        return;
    }
    else
    {
        while (qtr->next != NULL)
        {
            ptr = ptr->next;
            qtr = qtr->next;
        }
        ptr->next = NULL;
        free(qtr);
        return;
    }
}

void deleteatdesired()
{
    int y;
    cout << "Enter the position: ";
    cin >> y;
    if(y==1){
        head = head->next;
    }
    y = y - 1;
    node *ptr = head;
    node *qtr;
    if (head == NULL)
    {
        cout << "Can't delete an empty linked_list" << endl;
        return;
    }
    else
    {
        while (--y)
        {
            ptr = ptr->next;
        }
        qtr = ptr->next;
        ptr->next = qtr->next;
        free(qtr);
        return;
    }
}
////////////////////////////////////////////////////////////////////
void reviteration()
{
    node *ptr = head;
    node *temp, *prev = NULL, *curr = ptr->next;
    while (curr != NULL)
    {
        curr = ptr->next;
        ptr->next = prev;
        prev = ptr;
        ptr = curr;
    }
    head = prev;
}
void revrecursion(node *ptr)
{
    if (ptr->next == NULL)
    {
        head = ptr;
        return;
    }
    revrecursion(ptr->next);
    (ptr->next)->next = ptr;
    ptr->next = NULL;
}

void reverselist()
{
    int x;
    cout << "Press 1 for reverse using iteration\n";
    cout << "Press 2 for reverse using recursion\n";
    cout << "Enter you choice: ";
    cin >> x;
    switch (x)
    {
    case 1:
        reviteration();
        break;
    case 2:
        revrecursion(head);
        break;
    default:
        cout << "You entered wrong choice" << endl;
        break;
    }
}

////////////////////////////////// /////////////////////////////////
void printrecurry(node *head)
{
    if (head == NULL)
    {
        cout<<"NULL\n";
        return;
    }
    cout << head->data << "->";
    printrecurry(head->next);
}
void printiteration()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << "->";
        ptr = ptr->next;
    }
    cout <<"NULL" <<endl;
}

void printlist()
{
    cout << "Press 1 for print using recursion" << endl;
    cout << "Press 2 for print using iteration" << endl;
    int x;
    cin >> x;
    switch (x)
    {
    case 1:
        printrecurry(head);
        break;
    case 2:
        printiteration();
        break;
    default:
        cout << "you entered wrong choice";
        break;
    }
    cout << endl;
}

int menu()
{
    int x;
    cout << "Press 1 at the first position" << endl;
    cout << "Press 2 for insert at the desired position" << endl;
    cout << "Press 3 for insert at the last position" << endl;
    cout << "Press 4 for delete the element of first position " << endl;
    cout << "Press 5 for delete the element of desired position " << endl;
    cout << "Press 6 for delete the element of last position " << endl;
    cout << "Press 7 for reverse the linked_list" << endl;
    cout << "Press 8 for print the linked_list" << endl;
    cout << "Press 9 to exit the menu" << endl;
    cout << "Enter your choice !" << endl;
    cin >> x;
    return x;
}
int main(int argc, char **argv)
{
    head = NULL;
    while (true)
    {
        switch (menu())
        {
        case 1:
            insertatfirst();
            break;
        case 3:
            insertatlast();
            break;
        case 2:
            insertatdesired();
            break;
        case 4:
            deleteatfirst();
            break;
        case 6:
            deleteatlast();
            break;
        case 5:
            deleteatdesired();
            break;
        case 7:
            reverselist();
            break;
        case 8:
            printlist();
            break;
        case 9:
            exit(0);
            break;
        default:
            cout << "You entered wrong choice !" << endl;
            break;
        }
    }

    return 0;
}
