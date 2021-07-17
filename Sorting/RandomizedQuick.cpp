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
int RandomizedPartition(int a[],int s, int e)
{
    int pIndex = s + rand()%(e-s) ;
    swap(a[pIndex],a[e]);
    return Partition(a,s,e);

}
void RandomizedQuickSort(int a[], int s, int e)
{
   if(s<e)
   {
       int pIndex=RandomizedPartition(a,s,e);
       RandomizedQuickSort(a,s,pIndex-1);
       RandomizedQuickSort(a,pIndex+1,e);
   }
}
int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
         a[i] = rand()%n ;
    RandomizedQuickSort(a,0,n-1);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
