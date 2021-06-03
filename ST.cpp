#include <algorithm>
using namespace std;

const int logn = 21;
const int maxn = 2000001;

struct ST {
    int f[maxn][logn + 1], Logn[maxn + 1];
    void pre() {
        Logn[1] = 0;
        Logn[2] = 1;
        for (int i = 3; i < maxn; ++i) Logn[i] = Logn[i / 2] + 1;
    }
    void init(int n, int a[]) {
        for (int i = 1; i <= n; ++i) f[i][0] = a[i];
        for (int j = 1; j <= logn; ++j)
            for (int i = 1; i + (1 << j) - 1 <= n; ++i)
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    }
    int query(int x, int y) {
        int s = Logn[y - x + 1];
        return max(f[x][s], f[y - (1 << s) + 1][s]);
    }
};