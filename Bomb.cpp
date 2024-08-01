#include <bits/stdc++.h>
using namespace std;

 

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n; i++) {
            pq.push({a[i], b[i]});
        }
        
        long long int ans = 0;
        while (!pq.empty() && k != 0) {
            k--;
            auto node = pq.top();
            pq.pop();
            int a_val = node.first;
            int b_val = node.second;
            if (a_val > b_val) {
                ans = ans + a_val;
                a_val -= b_val;
                pq.push({a_val, b_val});
            } else {
                ans = ans + a_val;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
