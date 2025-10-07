// =====================================================
// Segment Tree (soma em intervalos com atualização)
// =====================================================
#include <bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int n;
    vector<long long> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.assign(4*n, 0);
        build(1, 0, n-1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*idx, l, mid, arr);
        build(2*idx+1, mid+1, r, arr);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    long long query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0; // fora do intervalo
        if (ql <= l && r <= qr) return tree[idx];
        int mid = (l + r) / 2;
        return query(2*idx, l, mid, ql, qr) + query(2*idx+1, mid+1, r, ql, qr);
    }

    void update(int idx, int l, int r, int pos, int val) {
        if (l == r) {
            tree[idx] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (pos <= mid) update(2*idx, l, mid, pos, val);
        else update(2*idx+1, mid+1, r, pos, val);
        tree[idx] = tree[2*idx] + tree[2*idx+1];
    }

    // Interfaces mais práticas
    long long query(int l, int r) { return query(1, 0, n-1, l, r); }
    void update(int pos, int val) { update(1, 0, n-1, pos, val); }
};

// ====================== EXEMPLO ======================
// vector<int> arr = {1, 3, 5, 7, 9, 11};
// SegmentTree st(arr);
// cout << st.query(1, 3) << "\n"; // soma [3,5,7] = 15
// st.update(2, 10); // arr[2] = 10
// cout << st.query(1, 3) << "\n"; // 3 + 10 + 7 = 20
