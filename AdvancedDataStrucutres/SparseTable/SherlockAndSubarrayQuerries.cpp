/*
Link: https://www.hackerrank.com/contests/codeagon2015/challenges/sherlock-and-subarray-queries
*/

#include <bits/stdc++.h>
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

const int N = 1e5 + 5;
const int KMAX = 18;
int n, m;
int a[N];
pair<int, int> sparseTable[N][KMAX + 1];


int32_t main()
{
    TFiOS;

    int tc;
    // cin >> tc;
    tc = 1;
    while (tc--) {
        cin >> n >> m;

        // initialize sparse table
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sparseTable[i][0].ff = a[i];
            sparseTable[i][0].ss = 1;
        }

        // build sparse table
        for (int j = 1; j <= KMAX; j++) {
            for (int i = 0; i + (1LL << j) - 1 < n; i++) {
                int maxLeft = sparseTable[i][j - 1].ff;
                int maxRight = sparseTable[i + (1LL << (j - 1))][j - 1].ff;
                int countLeft = sparseTable[i][j - 1].ss;
                int countRight = sparseTable[i + (1LL << (j - 1))][j - 1].ss;
                if (maxLeft == maxRight) {
                    sparseTable[i][j].ff = maxLeft;
                    sparseTable[i][j].ss = countLeft + countRight;
                }
                else if (maxLeft > maxRight) {
                    sparseTable[i][j].ff = maxLeft;
                    sparseTable[i][j].ss = countLeft;
                }
                else {
                    sparseTable[i][j].ff = maxRight;
                    sparseTable[i][j].ss = countRight;
                }
            }
        }

        // queries
        while (m--) {
            int L, R;
            cin >> L >> R;
            L--;    R--;
            int ans = 0;
            int mx = INT_MIN;
            for (int j = KMAX; j >= 0; j--) {
                if ( L + (1LL << j) - 1 <= R) {
                    int maxElement = sparseTable[L][j].ff;
                    int count = sparseTable[L][j].ss;
                    L += (1LL << j);
                    if (maxElement > mx) {
                        mx = maxElement;
                        ans = count;
                    } 
                    else if (maxElement == mx) {
                        ans += count;
                    }
                    else
                        continue;
                }
            }
            cout << ans << endl;
        }
    }
    return 0;
}