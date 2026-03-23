#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <stack>

using namespace std;

typedef long long ll;

struct Point {
    ll x, y;
};

Point pivot;

// Tính bình phương khoảng cách
ll distSq(Point p1, Point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// Tích có hướng: > 0 là rẽ trái (CCW), < 0 là rẽ phải (CW), 0 là thẳng hàng
ll cp(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// So sánh để sắp xếp theo góc cực
bool compare(Point p1, Point p2) {
    ll val = cp(pivot, p1, p2);
    if (val == 0) // Nếu thẳng hàng, điểm nào gần pivot hơn thì đứng trước
        return distSq(pivot, p1) < distSq(pivot, p2);
    return val > 0;
}

void solve() {
    int n;
    cin >> n;
    vector<Point> p(n);
    int min_idx = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        // Tìm điểm thấp nhất, trái nhất làm pivot
        if (p[i].y < p[min_idx].y || (p[i].y == p[min_idx].y && p[i].x < p[min_idx].x))
            min_idx = i;
    }

    // Đưa pivot về vị trí đầu tiên và sắp xếp phần còn lại
    swap(p[0], p[min_idx]);
    pivot = p[0];
    sort(p.begin() + 1, p.end(), compare);

    // Xử lý các điểm thẳng hàng ở cuối danh sách (để lấy điểm xa nhất)
    // Nếu đề bài yêu cầu bỏ qua điểm thẳng hàng trên cạnh bao lồi
    int m = 1;
    for (int i = 1; i < n; i++) {
        while (i < n - 1 && cp(pivot, p[i], p[i + 1]) == 0) i++;
        p[m++] = p[i];
    }
    if (m < 3) return; // Không tạo được đa giác

    vector<Point> hull;
    hull.push_back(p[0]);
    hull.push_back(p[1]);
    hull.push_back(p[2]);

    for (int i = 3; i < m; i++) {
        while (hull.size() >= 2 && cp(hull[hull.size() - 2], hull.back(), p[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p[i]);
    }

    // 1. Tính diện tích Shoelace
    ll area2 = 0;
    int sz = hull.size();
    for (int i = 0; i < sz; i++) {
        area2 += (hull[i].x * hull[(i + 1) % sz].y - hull[(i + 1) % sz].x * hull[i].y);
    }

    // 2. Xuất kết quả
    cout << sz << "\n";
    cout << fixed << setprecision(1) << abs(area2) / 2.0 << "\n";
    for (int i = 0; i < sz; i++) {
        cout << hull[i].x << " " << hull[i].y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}
