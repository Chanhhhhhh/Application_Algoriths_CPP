#include <bits/stdc++.h> 
using namespace std;
const int MAX_N = 10e5;
pair<int,int> segment[MAX_N];
int n;

bool check(pair<int,int> a, pair<int,int> b){
    return a.second<b.second;
}

// tìm số đoạn không cắt nhau
int findSolution(){
    sort(segment,segment+n, check);// // sắp xếp mảng chứa các đoạn theo điểm cuối
    
    int result = 0;
    int last = -1;
    for (int i = 0; i < n; i++)
    {
        if(segment[i].first>last){
            result++;
            last = segment[i].second;
        }
    }
    return result;
    
}
int main() 
{ 
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> segment[i].first >> segment[i].second;
    }

     cout << findSolution();    
    
}