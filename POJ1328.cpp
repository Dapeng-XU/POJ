//
// Created by 40637 on 2017/2/12.
//

// HAVEN'T BEEN SOLVED
// 数据都对，但总是WA
//#define USING_1328
#ifdef USING_1328

#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    double x;
    double y;
    bool isCovered;
    double halfXCovered;

    Point(double _x, double _y, bool _isCovered) {
        x = _x;
        y = _y;
        isCovered = _isCovered;
        halfXCovered = -1.0;
    }
};

bool compare_x(const Point &a, const Point &b) {
    return (a.x < b.x);
}

int main() {
    int n, T = 0, c;
    double d, x, y;
    vector<Point> islands;
    bool noSolution;
    while (true) {
        islands.clear();
        T++;
        scanf("%d%lf", &n, &d);
        if (!n && !d)
            break;
        double d_2 = d * d;
        noSolution = false;
        islands.reserve(n);
        for (int i = 0; i < n; i++) {
            scanf("%lf%lf", &x, &y);
            if (y > d && !noSolution) {
                printf("Case %d: -1\n", T);
                noSolution = true;
            }
            if (!noSolution) {
                islands.push_back(Point(x, y, false));
            }
        }
        if (noSolution)
            continue;
        sort(islands.begin(), islands.end(), compare_x);
        for (int i = 0; i < n; i++) {
            islands[i].halfXCovered = floor(sqrt(d_2 - islands[i].y * islands[i].y));
        }
        c = 0;
        while (true) {
            double minXval = 200000000000000000000.0;
            for (int i = 0; i < n; i++) {
                if (!islands[i].isCovered) {
                    double radarX = islands[i].x + islands[i].halfXCovered;
                    if (radarX < minXval)
                        minXval = radarX;
                }
            }
            if (minXval > 100000000000000000000.0) {
                printf("Case %d: %d\n", T, c);
                break;
            }
            c++;
            for (int i = 0; i < n; i++) {
                if (!islands[i].isCovered) {
                    if (abs(islands[i].x - minXval) <= islands[i].halfXCovered) {
                        islands[i].isCovered = true;
                    }
                }
            }
        }
    }
    return 0;
}

#endif

/* Sample input:

3 2
1 2
-3 1
2 1

1 2
0 2

5 4
3 4
1 4
10 1
-2 2
-4 3

0 0

 */