#include<bits/stdc++.h>
using namespace std;

int Partition(int a[], int s, int e)
{
    int pivot=a[e];
    int pIndex=s;
    for(int i=s;i<e;i++)
        if(a[i] <= pivot )
            swap(a[i],a[pIndex++]);
    swap(a[pIndex],a[e]);
    return pIndex;
}
void QuickSort(int a[], int s, int e)
{
   if(s<e)
   {
       int pIndex=Partition(a,s,e);
       QuickSort(a,s,pIndex-1);
       QuickSort(a,pIndex+1,e);
   }
}
int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        a[i] = rand()%n ;
    QuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
