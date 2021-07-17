#include<bits/stdc++.h>
using namespace std;

void Merge(int a[], int l, int m, int r)
{
    int n1= m-l+1;
    int n2= r-m;

    int L[n1],R[n2];

    for(int i=0;i<n1;i++)
        L[i]=a[l+i];
    for(int j=0;j<n2;j++)
        R[j]=a[j+m+1];
    int j=0,k=l,i=0;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            a[k++]=L[i++];
        else
            a[k++]=R[j++];
    }
    while(i<n1)
        a[k++]=L[i++];
    while(j<n2)
        a[k++]=R[j++];
}
void MergeSort(int a[], int l, int r)
{
    if(l<r)
    {
        int m = (r+l)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
}
int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
         a[i] = rand()%n ;
    MergeSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
