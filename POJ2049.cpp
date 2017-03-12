//
// Created by 40637 on 2017/2/13.
//

//#define USING_2049
#ifdef USING_2049

#include <cstdio>
#include <queue>
using namespace std;

#define MAPSIZE 400
// the end point of the wall: [1, 199]

int map[MAPSIZE][MAPSIZE];

#define WALL -1
#define PATH -2
#define DOOR -3
#define MARLIN -4

struct Point{
    int x, y;
    Point(int _x, int _y) {
        x = _x;
        y = _y;
    }
};

int main() {
    int m, n, x, y, d, t, c;
    double nemoXd, nemoYd;
    int nemoXi, nemoYi;
    while (true) {
        for (int i=0;i<MAPSIZE;i++) {
            for (int j=0;j<MAPSIZE;j++) {
                map[i][j] = PATH;
            }
        }
        scanf("%d%d", &m, &n);
        if (m == -1 && n == -1) {
            break;
        }
        for (int i=0;i<m;i++) {
            // get wall
            scanf("%d%d%d%d", &x, &y, &d, &t);
            x = 2*x;
            y = 2*y;
            for (int j=0;j<t;j++) {
                if (d == 0) {
                    map[x + 1 + 2 * j][y] = WALL;
                } else {
                    map[x][y + 1 + 2 * j] = WALL;
                }
            }
        }
        for (int i=0;i<n;i++) {
            // get door
            scanf("%d%d%d", &x, &y, &d);
            x = 2*x;
            y = 2*y;
            if (d == 0) {
                map[x + 1][y] = DOOR;
            } else {
                map[x][y + 1] = DOOR;
            }
        }
        scanf("%lf%lf", &nemoXd, &nemoYd); // nemo
        if (nemoXd > 199 || nemoYd > 199 || nemoXd < 0 || nemoYd < 0) {
            printf("0\n");
            continue;
        }
        nemoXi = 2 * static_cast<int>(nemoXd) + 1;
        nemoYi = 2 * static_cast<int>(nemoYd) + 1;
        map[nemoXi][nemoYi] = 0;
        if (nemoXi == 0 && nemoYi == 0) {
            c = 0;
        } else {
            queue<Point> q;
            q.push(Point(1,1));
            while (!q.empty()) {
                Point &p = q.front();
                x = p.x;
                y = p.y;
                q.pop();
                if (x - 2 > 0 && map[x - 1][y] == PATH && map[x-2][y]==PATH) {
                    map[x-2][y] = MARLIN;
                    q.push(Point(x-2,y));
                }
                if (y - 2 > 0 && map[x][y - 1] == PATH && map[x][y-2]==PATH) {
                    map[x][y-2] = MARLIN;
                    q.push(Point(x, y-2));
                }
                if (x + 2 < 400 && map[x + 1][y] == PATH && map[x+2][y]==PATH) {
                    map[x+2][y] = MARLIN;
                    q.push(Point(x+2,y));
                }
                if (y + 2 < 400 && map[x][y + 1] == PATH && map[x][y+2]==PATH) {
                    map[x][y+2] = MARLIN;
                    q.push(Point(x, y+2));
                }
            }
            q.push(Point(nemoXi, nemoYi));
            bool foundNemo = false;
            c = MAPSIZE * MAPSIZE;
            while (!q.empty()) {
                Point &p = q.front();
                x = p.x;
                y = p.y;
                q.pop();
                int *nblock, *npath, cblock = map[x][y];
                if (x - 2 > 0) {
                    nblock = &map[x-2][y];
                    npath = &map[x-1][y];
                    if (*npath == PATH) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock < c) ? cblock : c;
                        } else if (*nblock > cblock || *nblock == PATH) {
                            *nblock = cblock;
                            q.push(Point(x-2, y));
                        }
                    } else if (*npath == DOOR) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock + 1 < c) ? (cblock + 1) : c;
                        } else if (*nblock > cblock + 1 || *nblock == PATH) {
                            *nblock = cblock + 1;
                            q.push(Point(x-2, y));
                        }
                    }
                }
                if (y - 2 > 0) {
                    nblock = &map[x][y-2];
                    npath = &map[x][y-1];
                    if (*npath == PATH) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock < c) ? cblock : c;
                        } else if (*nblock > cblock || *nblock == PATH) {
                            *nblock = cblock;
                            q.push(Point(x, y-2));
                        }
                    } else if (*npath == DOOR) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock + 1 < c) ? (cblock + 1) : c;
                        } else if (*nblock > cblock + 1 || *nblock == PATH) {
                            *nblock = cblock + 1;
                            q.push(Point(x, y-2));
                        }
                    }
                }
                if (x + 2 < 400) {
                    nblock = &map[x+2][y];
                    npath = &map[x+1][y];
                    if (*npath == PATH) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock < c) ? cblock : c;
                        } else if (*nblock > cblock || *nblock == PATH) {
                            *nblock = cblock;
                            q.push(Point(x+2, y));
                        }
                    } else if (*npath == DOOR) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock + 1 < c) ? (cblock + 1) : c;
                        } else if (*nblock > cblock + 1 || *nblock == PATH) {
                            *nblock = cblock + 1;
                            q.push(Point(x+2, y));
                        }
                    }
                }
                if (y+2 < 400) {
                    nblock = &map[x][y+2];
                    npath = &map[x][y+1];
                    if (*npath == PATH) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock < c) ? cblock : c;
                        } else if (*nblock > cblock || *nblock == PATH) {
                            *nblock = cblock;
                            q.push(Point(x, y+2));
                        }
                    } else if (*npath == DOOR) {
                        if (*nblock == MARLIN) {
                            foundNemo = true;
                            c = (cblock + 1 < c) ? (cblock + 1) : c;
                        } else if (*nblock > cblock + 1 || *nblock == PATH) {
                            *nblock = cblock + 1;
                            q.push(Point(x, y+2));
                        }
                    }
                }
            }
            if (!foundNemo) {
                c = -1;
            }
        }
        printf("%d\n", c);
    }
    return 0;
}

#endif

/* Sample input:

8 9
1 1 1 3
2 1 1 3
3 1 1 3
4 1 1 3
1 1 0 3
1 2 0 3
1 3 0 3
1 4 0 3
2 1 1
2 2 1
2 3 1
3 1 1
3 2 1
3 3 1
1 2 0
3 3 0
4 3 1
1.5 1.5
4 0
1 1 0 1
1 1 1 1
2 1 1 1
1 2 0 1
1.5 1.7
-1 -1

8 10
1 1 1 3
2 1 1 3
3 1 1 3
4 1 1 3
1 1 0 3
1 2 0 3
1 3 0 3
1 4 0 3
2 1 1
2 2 1
2 3 1
3 1 1
3 2 1
3 3 1
2 2 0
1 2 0
3 3 0
4 3 1
3.5 1.5

0 4
1 1 0
1 1 1
2 1 1
1 2 0
1.5 1.7

10 14
1 1 1 4
2 1 1 4
3 1 1 3
4 1 1 4
5 1 1 5
1 1 0 4
1 2 0 4
1 3 0 3
1 4 0 4
1 5 0 4
1 4 1
1 4 0
1 2 0
1 3 0
2 1 1
2 2 1
2 4 1
2 2 0
3 1 1
3 2 0
4 2 1
4 3 1
3 4 1
3 4 0
3.1 1.6


 */