#include <bits/stdc++.h>
using namespace std;
const int N = 18, ALL = 1 << N;
int dp[ALL], num[ALL], a[N + 5], g[N + 5];
string s;
char t[110000];
map <string, int> mp;
int main () {
    int T;
    cin >> T;
    for (int i = 1; i < ALL; i++) {
        num[i] = num[i ^ (i & -i)] + 1;
    }
    while (T--) {
        int n, m;
        cin >> n >> m;
        mp.clear();
        getchar ();
        for (int i = 1; i <= n; i++) {
            gets (t);
            s = t;
            int len = strlen (t), p, c = 0;
            for (int j = len - 1; j >= 0; j--) {
                if (s[j] == ' ') { p = j; break; }
            }
            for (int j = p + 1; s[j]; j++) {
                c *= 10;
                c += s[j] - '0';
            }
            mp[(string)s.substr (0, p)] = i;
            a[i] = c;
        }
        memset (g, 0, sizeof g);
        for (int i = 1; i <= m; i++) {
            gets (t);
            s = t;
            int p, len = strlen (t);
            for (int j = 0; ; j++) {
                if (s[j] == '-') { p = j; break; }
            }
            string s1 = s.substr (0, p - 1);
            string s2 = s.substr (p + 4, len - p - 4);
            g[mp[s2]] |= 1 << (mp[s1] - 1);
        }
        for (int i = 0; i < (1 << n); i++) dp[i] = -1;
        dp[0] = 0;
        for (int i = 0; i < (1 << n) - 1; i++) if (dp[i] != -1) {
            for (int j = 0; j < n; j++) if ((i & (1 << j)) == 0 && (i & g[j + 1]) == g[j + 1]){
                dp[i | (1 << j)] = max (dp[i | (1 << j)], dp[i] + a[j + 1] * (num[i] + 1));
            }
        }
        cout << dp[(1 << n) - 1] << endl;
    }
}
