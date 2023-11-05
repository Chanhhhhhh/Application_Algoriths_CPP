#include <bits/stdc++.h> 
using namespace std;
const int MAX_N = 10e6;
const int MOD = 1e9+7;
int arr[MAX_N]; 
int n;
int temp[MAX_N];


// tính số cặp nghịch đảo khi merge 2 mảng
long long meg(int l, int m, int r){
    long long count=0;
     int i = l, j =m+1, k = l;
     while ((i<=m) && (j<=r))
     {
        // arr[i] < arr[j] thì lưu arr[i] vào mảng trung gian
        if(arr[i]<=arr[j]){
              temp[k] = arr[i];
              k++; i++;
        }
        // nếu arr[i]>arr[j] thì lưu arr[j] vào mảng trung gian và số cặp nghịch đảo bằng số phần tử từ i đến m
        else{
            temp[k] = arr[j];
            k++; j++;
             count = (count + (m-i+1))%MOD;

        }
     }
    // lưu các phần tử còn lại của mảng bên trái vào mảng trung gian
     while (i<=m)
     {
            temp[k] = arr[i];
            k++; i++;
     }
         // lưu các phần tử còn lại của mảng bên phải vào mảng trung gian
     while (j<=r){
        temp[k] = arr[j];
            k++; j++;
     }
     // lưu các phần tử sau khi hợp nhất vào mảng gốc
     for (int i = l; i <= r; i++)
     {
        arr[i] = temp[i];
     }
          
     return count%MOD;
}

// tính số cặp nghịch đảo
long long mergeSort(int l, int r){
    long long count = 0,m;
    if (l<r)
    {
        m = (l+r)/2;
        count +=   mergeSort(l, m); // đệ quy mảng bên trái
        count +=   mergeSort(m+1,r); // đệ quy mảng bên phải
        count +=  meg(l,m,r); // hợp nhất 2 mảng

    }
    return count%MOD;
}

int main(){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    cout << mergeSort(0,n-1);
    return 0;
}

