#include<bits/stdc++.h>
using namespace std;

void Heapify(int a[], int n, int x)
{
    int largest = x;
    int l = 2*x+1;
    int r = 2*x+2;
    if(l<n && a[l]>a[largest])
        largest = l;
    if(r<n && a[r]>a[largest])
        largest = r;
    if(largest!=x)
    {
        swap(a[x], a[largest]);
        Heapify(a,n,largest);
    }
}

void HeapSort(int a[], int n)
{
    for(int i=n/2;i>=0;i--)
        Heapify(a,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(a[0],a[i]);
        Heapify(a,i,0);
    }
}

int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
         a[i] = rand()%n ;
    HeapSort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
