#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n, res = 1e9;
// Giáo viên thứ i có thể dạy các môn T[i][j]
int T[11][31];
int c[31][31];
// Môn học thứ i được dạy bởi gv x[i]
int x[31];
// Load của giáo viên thứ i trong lời giải hiện tại
int load[11];

bool check(int i, int k){
    // 1. Điều kiện gv k có thể dạy môn i
    if(T[k][i] != 1) return false;

    // 2. Không conflic với các môn còn lại của giáo viên k
    for(int j = 1; j < i; ++j) {
        if(c[i][j] == 1 && x[j] == k) return false;
    }

    return true;
}

void solve() {
    int maxLoad = 0;
    for(int i = 1; i <= m; ++i)
        maxLoad = max(maxLoad, load[i]);
    
    if(res > maxLoad) 
        res = maxLoad;
}

// Xét môn học thứ i
void Try(int i) {
    for(int k = 1; k <= m; ++k) {
        if(check(i, k)) {
            x[i] = k;
            load[k]++;
            if(i == n) solve();
            else Try(i + 1);
            load[k]--;
        }
    }
}

int main() {
    int k, d1, d2;
    cin >> m >> n;
    for(int i = 1; i<= m; ++i) {
        cin >> k;
        for(int j = 1; j <= k; ++j) {
            cin >> d1;
            T[i][d1] = 1;
        }
    }
    cin >> k;
    for(int i = 1; i <= k; ++i) {
        cin >> d1 >> d2;
        c[d1][d2] = 1;
        c[d2][d1] = 1;
    }
    Try(1);
    if(res == 1e9)
        cout << -1;
    else cout << res;
    return 0;
}