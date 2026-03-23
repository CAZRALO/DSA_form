#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

typedef long long ll;
struct Point { ll x, y; };

ll cp(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

void solve_brute() {
    int n; cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;

    vector<Point> hull;
    // Duyệt mọi cặp điểm i, j
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            bool ok = true;
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) continue;
                // Nếu có điểm k nằm bên phải đoạn i->j (cp < 0), thì i->j không là cạnh bao lồi CCW
                if (cp(p[i], p[j], p[k]) < 0) {
                    ok = false; break;
                }
            }
            if (ok) {
                // Kiểm tra xem p[i] đã có trong hull chưa để tránh trùng
                bool exists = false;
                for(auto& pt : hull) if(pt.x == p[i].x && pt.y == p[i].y) exists = true;
                if(!exists) hull.push_back(p[i]);
            }
        }
    }
}
