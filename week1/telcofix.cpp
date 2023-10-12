#include <bits/stdc++.h> 
using namespace std;

// hàm chuyển thời gian sang giây
int time_to_seconds(const string &time)
{
    int h, m, s;
    sscanf(time.c_str(), "%d:%d:%d", &h, &m, &s);
    return h * 3600 + m * 60 + s;
} 

// hàm kiểm tra 1 số điện thoại có hợp lệ hay không
bool is_valid_number(string number) {
    for (char c : number) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int total = 0;
    string line;

    unordered_map<string, int> CountPhone; // sử dụng cấu trúc dữ liệu hashmap dạng <key, value> để lưu trữ số cuộc gọi của 1 số điên thoại
    unordered_map<string, int> Total_time; // sử dụng cấu trúc dữ liệu hashmap dạng <key, value> để lưu trữ tổng thời gian của 1 số điên thoại
    bool yes = true; // biến trạng thái của "số phone có hợp lệ hay không"

    // đọc dữ liệu ở block 1
    while (getline(cin, line) && line != "#")
    {
        total++;

        // xác định các vị trí ngăn cách các trường dữ liệu
        size_t pos = line.find(' ');
        size_t pos1 = line.find(' ', pos + 1);
        size_t pos2 = line.find(' ', pos1 + 1);
        size_t pos3 = line.find(' ', pos2 + 1);
        size_t pos4 = line.find(' ', pos3 + 1);

        
         // lấy thông tin của từng cuộc gọi
        string phone = line.substr(pos + 1, pos1 - pos - 1); 
        string to_phone = line.substr(pos1+1, pos2-pos1-1);
        string from_time = line.substr(pos3 + 1, pos4 - pos3 - 1);
        string to_time = line.substr(pos4 + 1);
        

        CountPhone[phone]++;                                                        // tính số lượng cuộc gọi của phone
        Total_time[phone] += time_to_seconds(to_time) - time_to_seconds(from_time); // tính tổng thời gian gọi của phone

        if (!(is_valid_number(phone)) || !(is_valid_number(to_phone))) // kiểm tra 2 số điện thoại trong 1 cuộc gọi có hợp lệ hay không?
            yes = false;
    }

    // đọc và xử lý thông tin ở block 2
    while (getline(cin, line) && line != "#")
    {
        size_t pos = line.find(' ');
        string cmd = line.substr(0, pos);
        if (cmd == "?number_total_calls")
        {
            cout << total << endl;
        }
        else if (cmd == "?number_calls_from")
        {
            string phone = line.substr(pos + 1);
            cout << CountPhone[phone] << endl;
        }
        else if (cmd == "?check_phone_number")
        {
            if (yes)
            {
                cout << "1" << endl;
            }
            else
                cout << "0" << endl;
        }
        else if (cmd == "?count_time_calls_from")
        {
            string phone = line.substr(pos + 1);
            cout << Total_time[phone] << endl;
        }
    }

    return 0;
}
