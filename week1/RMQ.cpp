#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MAXLOG = 20;

int n, m, a[MAXN], st[MAXN][MAXLOG], lg2[MAXN];

// xây dựng Sparse Table
void buildRMQ() {
    // Khởi tạo hàng đầu tiên của Sparse Table với các giá trị từ mảng a
    for (int i = 0; i < n; ++i) st[i][0] = a[i];

    // Xây dựng các hàng còn lại của Sparse Table
    for (int j = 1; (1 << j) <= n; ++j) {
        for (int i = 0; i + (1 << j) <= n; ++i) {
            // Sử dụng quy tắc để tính giá trị tại [i][j] từ [i][j-1] và [i + 2^(j-1)][j-1]
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }

    // Tính toán các giá trị trong mảng lg2 để sử dụng trong truy vấn
    for (int i = 2; i <= n; ++i) lg2[i] = lg2[i >> 1] + 1;
}

// Hàm truy vấn RMQ trong đoạn [l, r]
int queryRMQ(int l, int r) {
    int k = lg2[r - l + 1];
    // Sử dụng Sparse Table để tìm min trong đoạn [l, r]
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    buildRMQ();

    // Nhập m và thực hiện truy vấn RMQ
    cin >> m;
    int result = 0;
    while (m--) {
        int l, r;
        cin >> l >> r;

        result += queryRMQ(l, r);
    }

    cout << result << '\n';

    return 0;
}