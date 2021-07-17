#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
struct Node* head;
void Insert(int n,int x)
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
}
void Print()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<"  ";
        temp=temp->next;
    }
}
int main()
{
    head=NULL;
    int M,i,x,p;
    char c='y';
    while(c=='y')
    {

       cout<< "\nEnter the  position & NO. "<<endl;
        cin >> p>> x;
        Insert(p,x);
        Print();

    cout << "\nAgain? y/n : \n";
    cin >> c;
    }
}
