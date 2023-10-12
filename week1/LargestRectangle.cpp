#include <iostream>
#include <vector>
using namespace std;


// hàm tìm hình chữ nhật gồm toàn bộ điểm đen có diện tích lớn nhất
int maxRectangle(vector<vector<int>>& matrix) {

    // nếu trận rỗng thì trả về 0
    if (matrix.empty()) return 0;


    int n = matrix.size();
    int m = matrix[0].size();

     // đưa ma trận về dạng biểu đồ gồm m cột
    vector<int> height(m, 0); // lưu độ cao của các cột (giá trị ban đầu là 0)
    vector<int> left(m, 0);  // lưu vị trí biên trái của vùng hình chữ nhật có thể phủ được cột j
    vector<int> right(m, m);  // lưu vị trí biên phải của vùng hình chữ nhật có thể phủ được cột j
    
    int maxArea = 0; // biến lưu diện tích hình chữ nhật lớn nhất



    // vòng lặp để xét từng hàng của ma trận
    for (int i = 0; i < n; i++) {
        
        int curLeft = 0, curRight = m;


        // tính chiều cao của từng cột 
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }

        // tìm vị trí biên trái của vùng hình chữ nhật có thể phủ được cột j
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1)
                left[j] = max(left[j], curLeft);
            else {
                left[j] = 0;
                curLeft = j + 1;
            }
        }

           // tìm vị trí biên trái của vùng hình chữ nhật có thể phủ được cột j
        for (int j = m - 1; j >= 0; j--) {
            if (matrix[i][j] == 1)
                right[j] = min(right[j], curRight);
            else {
                right[j] = m;
                curRight = j;
            }
        }

       // tính diện tích của các vùng hình chữ nhật tìm được
        for (int j = 0; j < m; j++) {
            maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
        }
    }
 
    return maxArea;
}

int main() {

    int n, m;
    cin >> n >> m;
    // khai báo và khởi tạo ma trận
    vector<vector<int>> matrix(n, vector<int>(m, 0));

    // nhập dữ liệu cho ma trận
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = maxRectangle(matrix);
    cout << result << endl;

    return 0;
}
