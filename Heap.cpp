#include <cstdio>
const int MAXN = 100000;
struct Heap {
    int data[MAXN], sz = 0;
    bool empty() {
        return sz == 0;
    }
    void push(int x) {
        int i = sz++;
        while (i > 0) {
            int p = (i - 1) / 2;
            if (data[x] <= x) break;
            data[i] = data[p];
            i = p;
        }
        data[i] = x;
    }
    int top() {
        return data[0];
    }
    int pop() {
        int ret = data[0];
        int x = data[--sz];
        int i = 0;
        while (i * 2 + 1 < sz) {
            int a = i * 2 + 1, b = i * 2 + 2;
            if (b < sz && data[b] < data[a]) a = b;
            if (data[a] >= x) break;
            data[i] = data[a];
            i = a;
        }
        data[i] = x;
        return ret;
    }
};
int main()
{
    Heap heap;
    heap.push(3);
    heap.push(5);
    heap.push(1);

    while (!heap.empty()) {
        printf("%d\n", heap.top());
        heap.pop();
    }
    return 0;
}