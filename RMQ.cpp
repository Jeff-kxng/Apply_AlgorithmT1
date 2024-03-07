/*Problem: LAB.01.03 - Range Minimum Query*/

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6 + 5;
const int LOGN = 20; // Adjust this based on the maximum array size

int a[maxN];
int st[maxN][LOGN]; // Sparse table

// Preprocessing: Build the sparse table
void buildSparseTable(int n) {
    for (int i = 0; i < n; ++i)
        st[i][0] = a[i];

    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Query: Find the minimum value in the range [l, r]
int query(int l, int r) {
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    buildSparseTable(n);

    cin >> m;
    int ans = 0;
    while (m--) {
        int i, j;
        cin >> i >> j;
        ans += query(i, j);
    }

    cout << ans << "\n";
    return 0;
}
