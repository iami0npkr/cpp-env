#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    int mod = 1e9 + 7;

    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> v1(n + 1, 0);
        vector<int> v2(2 * n + 2, 0);

        for (int i = 0; i < n; ++i)
        {
            v1[i + 1] = v1[i] + (s[i] == '1' ? 1 : -1);
        }
        long long int ans = 1;
        for (int j = 1; j <= n; ++j)
        {
            v2[v1[j - 1] + n] += j;
            ans = (ans + (long long)v2[v1[j] + n] * (n - j + 1)) % mod;
        }

        cout << (ans - 1 + mod) % mod << endl;
    }

    return 0;
}
