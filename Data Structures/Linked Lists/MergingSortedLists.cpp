#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
struct Node* head1;
struct Node* head2;
struct Node* head3;
struct Node* Insert(int data, int n ,struct Node* head)
{
    Node* temp1 = new Node;
    temp1->data=data;
    temp1->next=NULL;
    if(n==1)
    {
        temp1->next=head;
        head=temp1;
        return head;
    }
    Node* temp2=head;
    for(int i=0;i<n-2;i++)
    {
        temp2=temp2->next;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
    return head;
}
struct Node* MergeSorted(struct Node* head1 , struct Node* head2 , struct Node* head3)
{
  if(head1==NULL && head2==NULL)
    return head3;
  Node* temp1=head1;
  Node* temp2=head2;
  if(head1->data > head2->data)
    {head3=head2;temp2=temp2->next;}
  else
    {head3=head1;temp1=temp1->next;}
  Node* temp3=head3;
  while(temp1!=NULL && temp2!=NULL)
  {
      if(temp1->data > temp2->data)
      {
          temp3->next=temp2;
          temp2=temp2->next;
          temp3=temp3->next;
      }
      else
      {
          temp3->next=temp1;
          temp1=temp1->next;
          temp3=temp3->next;
      }
  }
  if(temp2==NULL)
  {
      while(temp1!=NULL)
      {
          temp3->next=temp1;
          temp1=temp1->next;
          temp3=temp3->next;
      }

  }
  else
  {
     while(temp2!=NULL)
     {
          temp3->next=temp2;
          temp2=temp2->next;
          temp3=temp3->next;
     }
  }
  return head3;

}
void Print(struct Node* head)
{
   Node* temp3=head;
   while(temp3!=NULL)
   {
       cout<< temp3->data << " ";
       temp3=temp3->next;
   }
   cout<<endl;
}
int main()
{
    head1=NULL;//empty list
    head2=NULL;
    head3=NULL;
    head1=Insert(107,1,head1);
    head1=Insert(15,1,head1);
    head1=Insert(9,1,head1);
    head1=Insert(6,1,head1);
    head1=Insert(3,1,head1);
    head2=Insert(77,1,head2);
    head2=Insert(45,1,head2);
    head2=Insert(19,1,head2);
    head2=Insert(12,1,head2);
    head2=Insert(8,1,head2);
    head2=Insert(7,1,head2);
    head2=Insert(6,1,head2);
    Print(head1);
    cout << endl;
    Print(head2);
    cout << endl;
    head3=MergeSorted(head1,head2,head3);
    Print(head3);
}
