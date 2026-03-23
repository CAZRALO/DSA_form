#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

// Hàm tính tích có hướng (Cross Product)
// Trả về > 0 nếu a->b->c là ngược chiều kim đồng hồ (CCW)
ll cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void solve() {

    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;

    // Sắp xếp điểm để xây dựng Monotone Chain
    sort(p.begin(), p.end(), [](Point a, Point b) {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    });

    // Xây dựng bao lồi
    vector<Point> hull;
    // Bao dưới
    for (int i = 0; i < n; ++i) {
        while (hull.size() >= 2 && cross_product(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    // Bao trên
    int lower_size = hull.size();
    for (int i = n - 2; i >= 0; --i) {
        while (hull.size() > lower_size && cross_product(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }
    hull.pop_back(); // Loại bỏ điểm cuối trùng với điểm đầu

    // 1. Tìm diện tích (Shoelace Formula)
    ll area2 = 0;
    int m = hull.size();
    for (int i = 0; i < m; ++i) {
        area2 += (hull[i].x * hull[(i + 1) % m].y - hull[(i + 1) % m].x * hull[i].y);
    }
    if (area2 < 0) area2 = -area2;

    // 2. Tìm đỉnh xuất phát theo yêu cầu: Thấp nhất -> Trái nhất
    int start_idx = 0;
    for (int i = 1; i < m; ++i) {
        if (hull[i].y < hull[start_idx].y || (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
            start_idx = i;
        }
    }

    // Xuất kết quả
    cout << m << endl;
    cout << fixed << setprecision(1) << (double)area2 / 2.0 << endl;
    for (int i = 0; i < m; ++i) {
        int idx = (start_idx + i) % m;
        cout << hull[idx].x << " " << hull[idx].y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
