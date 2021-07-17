#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
struct Node* head;
struct Node* InsertAt(int n,int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->next=NULL;
    if(n==1)
    {
        temp->next=head;
        head=temp;
    }
    else
    {
        Node* temp1=new Node;
        temp1=head;
        for(int i=1;i<n-1;i++)
           temp1=temp1->next;
        temp->next=temp1->next;
        temp1->next=temp;
    }
    return head;
}
struct Node* InsertAfter(int x, int y)
{
    Node* temp=new Node;
    temp->data=x;
    temp->next=NULL;
    Node* temp1=head;
    Node* preptr=temp1;
    while(preptr->data != y)
    {
        preptr=temp1;
        temp1=temp1->next;
    }
    temp->next=temp1;
    preptr->next=temp;
    return head;
}
struct Node* InsertBefore(int x,int y)
{
    Node* temp=new Node;
    temp->data=x;
    temp->next=NULL;
    Node* temp2=head;
    Node* preptr=temp2;
    if(temp2->data == y)
    {
        temp->next=temp2;
        head=temp;
        return head;
    }
    while( temp2->data != y)
    {
        preptr=temp2;
        temp2=temp2->next;
    }
    temp->next=temp2;
    preptr->next=temp;
    return head;
}
struct Node* DeleteAt(int n)
{
    Node* temp=head;
    if(n==1)
        {head=head->next;return head;}
    for(int i=1;i<n-1;i++)
    {
      temp=temp->next ;
    }
    temp->next=(temp->next)->next;
    return head;
}
struct Node* DeleteAfter(int x)
{
    Node* temp1=head;
    Node* preptr=temp1;
    if(preptr->data==x)
    {
       temp1=temp1->next;
       preptr->next=temp1->next;
       return head;
    }
    while(preptr->data!=x)
    {
        preptr=temp1;
        temp1=temp1->next;
    }
    preptr->next=temp1->next;
    free(temp1);
    return head;
}
struct Node* Print()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
    return head;
}
int main()
{
    int o;
    head=NULL;
    do
    {
        cout << "\n*****MAIN MENU*****\n";
        cout << "1: Insert Node At particular position \n";
        cout << "2: Insert After a particular Node\n";
        cout << "3: Insert Before a particular Node\n";
        cout << "4: Delete From Position \n";
        cout << "5: Delete After a Particular Node\n";
        cout << "6: Exit.!\n";
        cin >> o;
        switch(o)
        {
            case 1: cout << "Enter data and position:\n";
                    int n,p;
                    cin >> n >> p;
                    head=InsertAt(p,n);
                    head=Print();
                    break;
            case 2: cout << "Enter data and node value:\n";
                    int d,v;
                    cin >> d >> v;
                    head=InsertAfter(d,v);
                    head=Print();
                    break;
            case 3: cout << "Enter data and node value:\n";
                    int d1,v1;
                    cin >> d1 >> v1;
                    head=InsertBefore(d1,v1);
                    head=Print();
                    break;
            case 4: cout << "Enter the position to be deleted:\n";
                    int p1;
                    cin >> p1;
                    head =DeleteAt(p);
                    head=Print();
                    break;
            case 5: cout << "Enter the node value:\n";
                    int v2;
                    cin >> v2;
                    head=DeleteAfter(v2);
                    head=Print();
                    break;
        }
    }while(o!=6);
}
