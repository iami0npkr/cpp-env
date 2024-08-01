#include <bits/stdc++.h>
using namespace std;

class SGTree{
    vector<int> seg;
    public:
    SGTree(int n){
        seg.resize(4 * n);
    }

    void build(int ind, int low, int high, vector<int> &arr,bool orr) {
        if (low == high) {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr,!orr);
        build(2 * ind + 2, mid + 1, high, arr,!orr);
        if(orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
    }

    int query(int ind, int low, int high, int l, int r,bool orr) {
        if (l > high || r < low) {
            return 0; // Return 0 as this is OR operation identity
        }
        if (l <= low && r >= high) {
            return seg[ind];
        }
        int mid = (low + high) / 2;
        int left = query(2 * ind + 1, low, mid, l, r,!orr);
        int right = query(2 * ind + 2, mid + 1, high, l, r,!orr);
        if(orr) return left | right;
        else return left^right;
    }

    void update(int ind, int low, int high, int i, int val,bool orr) {
        if (low == high) {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid) {
            update(2 * ind + 1, low, mid, i, val,!orr);
        } else {
            update(2 * ind + 2, mid + 1, high, i, val,!orr);
        }
        if(orr) seg[ind] = seg[2 * ind + 1] | seg[2 * ind + 2];
        else seg[ind] = seg[2 * ind + 1] ^ seg[2 * ind + 2];
        
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int size = (1 << n); // Calculate size as 2^n
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    SGTree sgt(size);
    bool orr=true;
    if(n%2==0)
    orr=false;
    sgt.build(0, 0, size - 1, arr,orr);

    for (int i = 0; i < m; i++) {
        int p, b;
        cin >> p >> b;
        sgt.update(0, 0, size - 1, p - 1, b,orr);
        cout << sgt.query(0, 0, size - 1, 0, size - 1,orr) << endl;
    }
    return 0;
}
