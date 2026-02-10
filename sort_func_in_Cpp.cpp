#include <iostream>
#include <algorithm>
#include <random>
#include <chrono>
#include <vector>
#include <string>

using namespace std;

void printExecutionTime(const string& arrayName, double timeMs) {
    cout << arrayName << ": " << timeMs << " ms" << endl;
}

int main() {
    const int SIZE = 1000000;
    
    // Random số
    // Seed
    mt19937 gen(random_device{}());
    uniform_real_distribution<double> realDist(0.0, 1000000.0);
    uniform_int_distribution<int> intDist(0, 1000000);
    
    // Array 1: Số thực tăng dần
    vector<double> arr1(SIZE);
    for (int i = 0; i < SIZE; i++) {
        arr1[i] = i * 1.5;
    }
    
    // Array 2: Số thực giảm dần
    vector<double> arr2(SIZE);
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = (SIZE - i) * 1.5;
    }
    
    // Arrays 3-6: Số thực ngẫu nhiên
    vector<vector<double>> randomDouble(4, vector<double>(SIZE));
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < SIZE; i++) {
            randomDouble[j][i] = realDist(gen);
        }
    }
    
    // Arrays 7-10: Số nguyên ngẫu nhiên
    vector<vector<int>> randomInt(4, vector<int>(SIZE));
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < SIZE; i++) {
            randomInt[j][i] = intDist(gen);
        }
    }
    
    // Chạy và đo thời gian
    auto start = chrono::high_resolution_clock::now();
    sort(arr1.begin(), arr1.end());
    auto end = chrono::high_resolution_clock::now();
    printExecutionTime("Array 1 (Số thực tăng dần)", 
        chrono::duration<double, milli>(end - start).count());
    
    start = chrono::high_resolution_clock::now();
    sort(arr2.begin(), arr2.end());
    end = chrono::high_resolution_clock::now();
    printExecutionTime("Array 2 (Số thực giảm dần)", 
        chrono::duration<double, milli>(end - start).count());
    
    for (int j = 0; j < 4; j++) {
        start = chrono::high_resolution_clock::now();
        sort(randomDouble[j].begin(), randomDouble[j].end());
        end = chrono::high_resolution_clock::now();
        printExecutionTime("Array " + to_string(3 + j) + " (Số thực ngẫu nhiên)", 
            chrono::duration<double, milli>(end - start).count());
    }
    
    for (int j = 0; j < 4; j++) {
        start = chrono::high_resolution_clock::now();
        sort(randomInt[j].begin(), randomInt[j].end());
        end = chrono::high_resolution_clock::now();
        printExecutionTime("Array " + to_string(7 + j) + " (Số nguyên ngẫu nhiên)", 
            chrono::duration<double, milli>(end - start).count());
    }
    
    return 0;
}

// Kết quả (sẽ khác nhau tùy lần chạy):
// Array 1 (Số thực tăng dần): 116.665 ms
// Array 2 (Số thực giảm dần): 91.87 ms
// Array 3 (Số thực ngẫu nhiên): 258.164 ms
// Array 4 (Số thực ngẫu nhiên): 254.201 ms
// Array 5 (Số thực ngẫu nhiên): 251.108 ms
// Array 6 (Số thực ngẫu nhiên): 248.563 ms
// Array 7 (Số nguyên ngẫu nhiên): 201.391 ms
// Array 8 (Số nguyên ngẫu nhiên): 199.257 ms
// Array 9 (Số nguyên ngẫu nhiên): 199.983 ms
// Array 10 (Số nguyên ngẫu nhiên): 200.314 ms