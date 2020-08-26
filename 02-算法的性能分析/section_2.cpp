/* ************************************************************************
> File Name:     我们的程序为什么会超时？
> Author:        SunXiuyang
> Leetcode刷题攻略: https://github.com/youngyangyang04/leetcode-master 
 ************************************************************************/

#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono;

// O(n)
void function1(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        k++;
    }
}

// O(n^2)
void function2(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long j = 0; j < n; j++) {
            k++;
        }
    }

}

// O(nlogn)
void function3(long long n) {
    long long k = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = 1; j < n; j = j*2) { // 注意这里j=1
            k++;
        }
    }
}


void time_test() {
    long long n; // 数据规模
    while (cin>>n) {
        milliseconds start_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );

        function3(n);

        milliseconds end_time = duration_cast<milliseconds >(
            system_clock::now().time_since_epoch()
        );
        cout << "耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count() 
            <<" ms"<< endl;
    }
}

int main() {
    time_test();
}

