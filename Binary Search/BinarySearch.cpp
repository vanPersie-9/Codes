#include <bits/stdc++.h>
using namespace std;
/*int bs(long long int a[],long long int n, long long int k)
{
	long long int s=0,e=n-1;
	while(e>=s)
	{
		long long int mid= s + (e-s)/2;
		if(a[mid]==k)
			return mid;
		else if(a[mid] > k)
			e=mid-1;
		else
			s=mid+1;
	}
	return -1;
}*/

int main() {

	// your code here
	long long n,c;
	cin >> n;
	while(n!=0)
	{
		c=0;
		vector<long long> a;
		for(long long i=0;i<n;i++)
			{
			    long long input;
			    cin >> input;
			    a.push_back(input);
			}
 		sort(a.begin(),a.end());
		for(long long i=0;i<a.size()-1;i++)
		{
			for(long long j=i+1;j<a.size();j++)
			{
				long long sum=a[i]+a[j];
				cout << sum << "******" <<a[n-1] << endl;
				if(sum<a[n-1])
				{
                    vector<long long>::iterator it;
					it=upper_bound(a.begin(),a.end(),sum);
					cout << it-a.begin() << endl;
					c+=(long long)(a.end()-it);
				}
			}
		}
		cout << c <<endl;
		cin >> n;
	}

	return 0;
}
