#include<bits/stdc++.h>
using namespace std;
int n;  // so khach
int k; // số lượng khách tối đa của xe buýt
int best_sol=10000; // lưu giải pháp tốt nhất cho tuyến đường
int C[1000][1000]; // ma trận biểu diễn khoảng cách giữa 2 điểm
int appear[1000]; // xem hành khách i đã xuất hiện chưa
int cmin=100000;
int load=0; // số khách hiện tại của xe
int sol; // Đồ dài quảng đường đã đi
int X[1000]; // Lưu thứ tự các điểm đi qua

// kiểm tra xem khách v đã xuất hiện hay chưa hoặc lên xe có vượt trọng tải của xe hay k
int check(int v){
	if(load==k&&v<=n ) return 0;
	if(appear[v]==1) return 0;
	if(v>n&&appear[v-n]==0) return 0;
	return 1;
}


// cập nhập giải pháp tốt hơn
void solution(){
	if(sol+C[X[2*n]][0]<best_sol){
		best_sol=sol+C[X[2*n]][0];
	}
}


// hàm đệ quy quay lui để duyệt tất cả các trường hợp tuyến đường
void Try(int k){
	if(sol+cmin*(2*n-k+2)>best_sol) return;
	for(int v=1;v<=2*n;v++){
		if(check(v)){
			X[k]=v;
			appear[v]=1;
			if(v>n) load--;
			if(v<=n) load++;
			sol+=C[X[k-1]][v];
			if(k==2*n) {
				solution();
			}
			else
			{
				Try(k+1);
			}
			appear[v]=0;
			if(v>n) load++;
			if(v<=n) load--;
			sol-=C[X[k-1]][v];
		}
	}
}
int main(){
	cin >> n >> k;
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			cin >> C[i][j];
			if(C[i][j]<cmin&&C[i][j]>0) cmin=C[i][j];
		}
	}
	X[0]=0;
	Try(1);
	cout << best_sol;
}
