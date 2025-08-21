#include <iostream>
using namespace std;

// 快速幂取模函数
long long mod_pow(long long base, long long exp, long long modulus) {
    long long result = 1;
    base = base % modulus;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % modulus;
        }
        exp = exp >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main() {
    const long long MOD = 1e9 + 7;
    const int length = 10000;

    // 计算 9^10000 % MOD
    long long all_nine = mod_pow(9, length, MOD);
    
    // 计算 8^10000 % MOD
    long long without_three_or_seven = mod_pow(8, length, MOD);
    
    // 计算 7^10000 % MOD
    long long without_three_and_seven = mod_pow(7, length, MOD);

    // 使用容斥原理计算结果
    long long result = (all_nine - 2 * without_three_or_seven + without_three_and_seven + MOD) % MOD;

    cout << result << endl;

    return 0;
}