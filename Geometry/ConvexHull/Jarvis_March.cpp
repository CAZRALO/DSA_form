//Gift Wrapping
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
struct Point { ll x, y; };

//Cross Product - Tích có hướng
ll cp(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

// Khoảng cách bình phương để xử lý các điểm thẳng hàng
ll distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void solve_jarvis() {
    int n; cin >> n;
    vector<Point> p(n);
    int start = 0;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
        // Tìm điểm trái nhất (ưu tiên thấp nhất) để bắt đầu
        if (p[i].x < p[start].x || (p[i].x == p[start].x && p[i].y < p[start].y))
            start = i;
    }

    vector<Point> hull;
    int cur = start;
    do {
        hull.push_back(p[cur]);
        int next = (cur + 1) % n;
        for (int i = 0; i < n; i++) {
            if (i == cur) continue;
            ll val = cp(p[cur], p[i], p[next]);
            if (val > 0) { // Điểm i nằm bên trái hơn điểm next hiện tại
                next = i;
            } else if (val == 0) { // Thẳng hàng, chọn điểm xa hơn
                if (distSq(p[cur], p[i]) > distSq(p[cur], p[next]))
                    next = i;
            }
        }
        cur = next;
    } while (cur != start);

    // 1. Tính diện tích Shoelace
    ll area2 = 0;
    int m = hull.size();
    for (int i = 0; i < m; i++)
        area2 += (hull[i].x * hull[(i + 1) % m].y - hull[(i + 1) % m].x * hull[i].y);
    
    // 2. Tìm lại đỉnh xuất phát theo đề bài (Thấp nhất -> Trái nhất)
    int s_idx = 0;
    for (int i = 1; i < m; i++) {
        if (hull[i].y < hull[s_idx].y || (hull[i].y == hull[s_idx].y && hull[i].x < hull[s_idx].x))
            s_idx = i;
    }

    // In kết quả
    cout << m << "\n";
    cout << fixed << setprecision(1) << abs(area2) / 2.0 << "\n";
    for (int i = 0; i < m; i++) {
        int idx = (s_idx + i) % m;
        cout << hull[idx].x << " " << hull[idx].y << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    solve_jarvis(); 
    return 0;
}
