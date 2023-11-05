#include <bits/stdc++.h> 
using namespace std;
const int MAX_N = 10e6;
int arr[MAX_N]; // chu
int n,c;
int testcase;


// kiểm tra xem có thể lấy được tập con ít nhất c phần tử với hiệu giữa các phần tử ít nhất là distance
bool check(int distance){
    int cnt = 1;
    int i = 0, j=1;
    while(i<n){
        while(j<n&& arr[j]-arr[i]<distance) j++;
        if(j<n) cnt++;
        if(cnt>=c) return true; // lấy được c phần tử thỏa mãn
        i =j;
        j++;
    }
    return false;

}
// tìm kiếm nhị phân để tìm hiệu số lớn nhất 
int solution(){
    // khoảng thỏa mãn của hiệu số lớn nhất là 0 -> arr[n-1] - ar[0]
    int l = 0;
    int r = arr[n-1]-arr[0];
    
    while(l<=r){
        int m = (l+r)/2;
        if(check(m)) l=m+1; // mid là giá trị khả thi nên tiếp tục tìm kiếm bên phải
        else r = m-1; // mid là giá trị không khả thi nên tìm kiếm bên trái
    }
    return r; 
    
}

int main(){
    // input
    cin >> testcase;
    while(testcase--){   
        
        cin >> n  >> c;
        for (int i = 0; i < n; i++)
            {
                cin >> arr[i];
            }
        sort(arr,arr+n); // sắp xếp giá trị mảng tăng dần
        cout << solution() << endl;
    }
   

}