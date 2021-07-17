#include<iostream>
using namespace std;
int main()
{
    int a[10],n,p;
    cout << "Enter the no. of elements in array:\n";
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    cout << "Enter the position to be deleted:\n";
    cin >> p;
    for(int i=p-1;i<=n-1;i++)
    {
        a[i]=a[i+1];
    }
    n=n-1;
    for(int i=0;i<n;i++)
        cout << a[i] << " ";
}
