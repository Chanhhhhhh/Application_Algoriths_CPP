#include <bits/stdc++.h>
using namespace std;

// kiểm tra số điẹn thoại có hợp lệ hay không
bool is_valid_number(const std::string& phoneNumber) {
    return std::all_of(phoneNumber.begin(), phoneNumber.end(), ::isdigit);
}

// tính thời gian cuộc gọi (theo giây)
 int toSecond(string from_time, string to_time){
    int from_hour, from_minute, from_second;
            int to_hour, to_minute, to_second;
            sscanf(from_time.c_str(), "%d:%d:%d", &from_hour, &from_minute, &from_second);
            sscanf(to_time.c_str(), "%d:%d:%d", &to_hour, &to_minute, &to_second);
            return (to_hour - from_hour) * 3600 + (to_minute - from_minute) * 60 + (to_second - from_second);
}



int main() {
    clock_t start, end; 
    start = clock(); 

     ifstream inputFile;
    inputFile.open("telco.txt"); 
    unordered_map<string, int> total_duration; // lưu tổng thời gian cuộc gọi từ 1 số điện thoại
    unordered_map<string, int> phoneCount; // lưu số cuộc gọi từ 1 số điện thoại


    string line; 
    int CountLine=0; // số dòng input
     int CountCall = 0; // số cuộc gọi hợp lệ

     // đọc firts block
    while (getline(inputFile, line) && line != "#") {
        stringstream ss(line);
        string cmd, from_number, to_number, date, from_time, to_time;
        ss >> cmd >> from_number >> to_number >> date >> from_time >> to_time;  

        // kiểm tra số điện thoại có hợp lệ không, nếu hợp lệ thì lưu lại thời gian         
        if (is_valid_number(from_number) && is_valid_number(to_number)) {          
            total_duration[from_number]+=toSecond(from_time,to_time);
            phoneCount[from_number]++;
            CountCall++;
            
        }
        CountLine++;
    }


// đọc second block
    while (getline(inputFile, line) && line != "#") {
        stringstream ss(line);
        string cmd, phone_number;
        ss >> cmd;
        if (cmd == "?check_phone_number") {
            if(CountLine == CountCall) // nếu số dòng == số cuộc gọc hợp lệ thì số điện thoại đều chính xác
            cout << 1 << endl;
        } else if (cmd == "?number_calls_from") {
            ss >> phone_number;
            cout << phoneCount[phone_number] << endl;          
        } else if (cmd == "?number_total_calls") {
            cout << CountCall << endl;
        } else if (cmd == "?count_time_calls_from") {
            ss >> phone_number;
            cout << total_duration[phone_number] << endl;
        }
    }

     end = clock();
     cout << (double)(end - start) / CLOCKS_PER_SEC << endl;
    return 0;
}