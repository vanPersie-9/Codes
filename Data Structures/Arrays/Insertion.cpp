#include<iostream>
using namespace std;
int main()
{
    int a[10],n,p,v;
    cout << "Enter the no. of elements in array:\n";
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "Enter the value & position of new element:\n";
    cin >> v >> p;
    for(int i=n;i>=p-1;i--)
    {
        a[i+1]=a[i];
    }
    a[p-1]=v;
    n=n+1;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}
