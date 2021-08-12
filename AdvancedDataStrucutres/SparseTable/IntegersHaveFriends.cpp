/*
Link: https://codeforces.com/contest/1549/problem/D
*/

#include<bits/stdc++.h>
using namespace std;
#define TFiOS ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define int ll
#define pb push_back
#define endl "\n"
#define mp make_pair
#define ff first
#define ss second
const int MOD = 1e9+7;
 
const int N = 2e5+5;
const int KMAX = 20;
int a[N], n;
int sparseTable[N][KMAX + 1];
 
int __gcd(int x, int y) {
    if (x == 0)
        return y;
    return __gcd(y%x, x);
     
}
 
int32_t main() {
    TFiOS;
 
    int tc;
    cin >> tc;
    // tc = 1;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (i) {
                sparseTable[i - 1][0] = abs(a[i] - a[i - 1]);   // initialize sparse table
            }
        }
        // build sparse table
        for (int j = 1; j <= KMAX; j++) {
            for (int i = 0; i + (1LL << (j - 1)) < n - 1; i++) {
                sparseTable[i][j] = __gcd(sparseTable[i][j - 1], sparseTable[i + (1LL << (j - 1))][j - 1]);
            }
        }
  
        int ans = 1;
        for (int i = 0; i < n - 1; i++) {
            int L = i, g = 0;
            for (int j = KMAX; j >= 0; j--) {
                if (L + (1LL << j) >= n) {
                    continue;
                }
                if (__gcd(g, sparseTable[L][j]) != 1) {
                    g = __gcd(g, sparseTable[L][j]);
                    L += (1LL << j);
                } 
            }
            ans = max(ans, L - i + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

/*
Input:
4
5
1 5 2 4 6
4
8 2 5 10
2
1000 2000
8
465 55 3 54 234 12 45 78

Output:
3
3
2
6

*/