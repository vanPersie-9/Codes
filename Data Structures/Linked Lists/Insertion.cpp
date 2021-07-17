#include<bits/stdc++.h>
using namespace std;
struct Node
{
   int data;
   Node* next;
};
struct Node* head;
void Insert(int x)
{
    Node* temp= new Node;
    temp->data=x;
    temp->next=head;
    head=temp;
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
    cout<< "How many numbers"<< endl;
    int n,i,x;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cout<< "\nEnter the no."<<endl;
        cin >> x;
        Insert(x);
        Print();
    }
}
