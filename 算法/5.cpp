#include<bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int k, n;
ll result = 0xFFFFFFFFFFFFFFFFULL; // 初始化为最大值
struct Point { int x, y; } a[55];

struct Rect {
    int l, r, u, d;
    bool active = false;
    ll area() const {
        if (!active) return 0;
        return (ll)(r - l) * (u - d);
    }
    void insert(int x, int y) {
        if (!active) {
            l = r = x;
            u = d = y;
            active = true;
        } else {
            l = min(l, x);
            r = max(r, x);
            d = min(d, y);
            u = max(u, y);
        }
    }
    bool include(int x, int y) const {
        if (!active) return false;
        return x >= l && x <= r && y >= d && y <= u;
    }
} rects[5];

bool checkDisjoint(const Rect &x, const Rect &y) {
    if (!x.active || !y.active) return true;
    // 不重叠且不接触：一个矩形的右边界必须小于另一个的左边界，以此类推
    return (x.r < y.l) || (y.r < x.l) || (x.u < y.d) || (y.u < x.d);
}
void dfs(int idx) {
    ll current_area = 0;
    for (int i = 0; i < k; i++) current_area += rects[i].area();
    if (current_area >= result) return; // 剪枝
    if (idx == n) {
        result = current_area;
        return;
    }
    for (int i = 0; i < k; i++) {
        Rect backup = rects[i];
        rects[i].insert(a[idx].x, a[idx].y);
        bool ok = true;
        for (int j = 0; j < k; j++) {
            if (i == j) continue;
            if (!checkDisjoint(rects[i], rects[j])) {
                ok = false;
                break;
            }
        }
        if (ok) dfs(idx + 1);
        rects[i] = backup; // 回溯
    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    dfs(0);
    cout << result << endl;
    return 0;
}