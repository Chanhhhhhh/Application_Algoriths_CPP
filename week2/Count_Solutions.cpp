#include <bits/stdc++.h>

using namespace std;
int n,M;
int a[10000]; // lưu hệ số của phương trình 
int cnt=0; // số nghiệm
int _solution[10000]; // lưu nghiệm
int sum=0; 

// hàm tính tổng các hệ số từ 1-> index  
int T(int index){
    int f = 0;
    for(int i = 1; i <= index; i++){
        f += a[i];
    }
    return f;
}

// hàm tính số nghiệm của phương trình
void solution(int k){
    for(int i = 1; i <= (M-(T(n) - T(k)) - sum)/a[k]; i++){
        sum += i * a[k];
        if(k == n){
            if(sum == M){
                cnt++;
            }
        }
        else {
            solution(k+1);
        }
        sum -= i * a[k];
    }

}

int main() {
    cin >> n >> M;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
solution(1);
cout << cnt << endl;
    return 0;
}