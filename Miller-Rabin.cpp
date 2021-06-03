#include <cstdlib>
typedef long long LL;

LL quickPow(LL a, LL b, LL m) {
    a %= m;
    LL res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
bool millerRabin(LL n) {
    if (n < 3) return n == 2;
    LL a = n - 1, b = 0;
    while (a % 2 == 0) {
        a /= 2;
        ++b;
    }
    // test_time为测试次数，建议设为不小于8的整数以保证正确率，但也不宜过大，否则会影响效率
    int test_time = 8; 
    for (int i = 1; i <= test_time; ++i) {
        LL j = 0;
        LL x = rand() % (n - 2) + 2, v = quickPow(x, a, n);
        if (v == 1 || v == n - 1) continue;
        for (; j < b; ++j) {
            v = v * v % n;
            if (v == n - 1) break;
        }
        if (j >= b) return 0;
    }
    return 1;
}