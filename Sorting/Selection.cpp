#include<bits/stdc++.h>
using namespace std;

void SelectionSort(int a[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        int imin=i;
        for(int j=i+1;j<n;j++)
            if(a[j]<a[imin])
                imin=j;
        swap(a[i],a[imin]);
    }
}

int main()
{
    int n=50;
    //cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
        a[i] = rand()%n ;
    SelectionSort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
    return 0;
}
/*
T(n)     :  O(n^2)
Stability:  Unstable
*/
