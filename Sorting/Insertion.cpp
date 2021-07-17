#include<bits/stdc++.h>
using namespace std;

void InsertionSort(int a[], int n)
{
    for(int i=1;i<n;i++)
    {
        int value = a[i], hole = i;
        while(hole > 0 && a[hole-1] > value )
            a[hole] = a[hole-- -1];
        a[hole] = value;
    }
}

int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
         a[i] = rand()%n ;
    InsertionSort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
