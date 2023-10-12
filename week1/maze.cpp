#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

// Định nghĩa một cấu trúc để biểu diễn một điểm trong mê cung
struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};


int n, m, r, c;
vector<vector<int>> maze;
vector<vector<int>> dist;  //  lưu khoảng cách từ điểm xuất phát đến các điểm khác
vector<vector<bool>> visited; // đánh dấu các điểm đã được duyệt qua

// Các hướng di chuyển: lên, xuống, trái, phải
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


// kiểm tra xem điểm đó có hợp lệ không: nằm trong biên của ma trận,là điểm 0 và chưa được duyệt qua
bool isValid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && maze[x][y] == 0 && !visited[x][y];
}



// Hàm tìm đường ngắn nhất sử dụng thuật toán BFS
int bfs() {
    queue<Point> q;
    q.push(Point(r - 1, c - 1)); // Đưa điểm xuất phát vào hàng đợi
    dist[r - 1][c - 1] = 0; // khởi tạo khoảng cách ban đầu là 0
    visited[r - 1][c - 1] = true; // đánh dấu điểm bắt đầu là đã thăm 

    while (!q.empty()) {
        Point current = q.front();
        q.pop();


         // Kiểm tra xem có đạt đến biên mê cung hay không, nếu có thì trả về khoảng cách
        if (current.x == 0 || current.x == n - 1 || current.y == 0 || current.y == m - 1) {
            return dist[current.x][current.y]+1;
        }

        // Duyệt qua các hướng di chuyển từ điểm hiện tại
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];


            // Kiểm tra xem hướng di chuyển có hợp lệ không
            if (isValid(newX, newY)) {
                q.push(Point(newX, newY));
                dist[newX][newY] = dist[current.x][current.y] + 1;  // Cập nhật khoảng cách mới
                visited[newX][newY] = true;  // Đánh dấu điểm mới đã được duyệt qua
            }
        }
    }


     // Trả về -1 nếu không tìm thấy đường đi ra khỏi mê cung
    return -1;
}

int main() {
    cin >> n >> m >> r >> c;
    maze.resize(n, vector<int>(m));
    dist.resize(n, vector<int>(m, -1)); // Khởi tạo khoảng cách với giá trị -1 
    visited.resize(n, vector<bool>(m, false)); // Khởi tạo ma trận mê cung đánh dấu chưa duyệt qua (false)


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }
    
    int result = bfs();
    cout << result << endl;
    return 0;
}
