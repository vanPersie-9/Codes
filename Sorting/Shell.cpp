#include<bits/stdc++.h>
using namespace std;

void ShellSort(int a[], int n)
{
    for(int gap=n/2;gap>0;gap /= 2 )
    {
        for(int i=gap;i<n;i++)
        {
            int temp =a[i];
            int j;
            for(j=i; j>=gap && a[j-gap] > temp ; j-=gap)
                a[j]=a[j-gap];
            a[j]=temp;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++)
         a[i] = rand()%n ;
    ShellSort(a,n);
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}
