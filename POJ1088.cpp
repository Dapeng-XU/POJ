//
// Created by 40637 on 2017/3/12.
//

#define USING_1088
#ifdef USING_1088

/* WARNING: The length of the longest path MAY NOT START FROM the HIGHEST point or
 * END AT the LOWEST point!
 */

#include <cstdio>
#include <climits>
#include <queue>

using namespace std;

const int dimension = 200;

int map[dimension][dimension];
int dp[dimension][dimension];

int C, R;

struct coord {
    int x;
    int y;
    coord (int x0 = -1, int y0 = -1) {
        x = x0;
        y = y0;
    }
};

vector<coord> minlist, maxlist;

int main() {
    int minval = INT_MAX, maxval = INT_MIN;
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int tmp;
            scanf("%d", &tmp);
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dp[i][j] = INT_MIN; // row-major
        }
    }
    if (C == 1 && R == 1) {
        printf("1");
    } else {
        queue<coord> q;
//        while (!minlist.empty()) {
//            coord minloc = minlist.back();
//            minlist.pop_back();
//            q.push(minloc);
////            printf("(%d, %d)\n", minloc.y, minloc.x);
//            dp[minloc.y][minloc.x] = 0;
//        }
        while (!q.empty()) {
            coord c = q.front();
            q.pop();
            int cur = dp[c.y][c.x], *tmp;
//            printf("(%d, %d, %d, %d)  ", c.y, c.x, cur, dp[c.y][c.x]);
            if (c.x != 0) {
                tmp = &dp[c.y][c.x - 1];
                if (*tmp < cur + 1 && map[c.y][c.x - 1] < map[c.y][c.x]) {
                    *tmp = cur + 1;
                    q.push(coord(c.x - 1, c.y));
                }
            }
            if (c.x != C - 1) {
                tmp = &dp[c.y][c.x + 1];
                if (*tmp < cur + 1 && map[c.y][c.x + 1] < map[c.y][c.x]) {
                    *tmp = cur + 1;
                    q.push(coord(c.x + 1, c.y));
                }
            }
            if (c.y != 0) {
                tmp = &dp[c.y - 1][c.x];
                if (*tmp < cur + 1 && map[c.y - 1][c.x] < map[c.y][c.x]) {
                    *tmp = cur + 1;
                    q.push(coord(c.x, c.y - 1));
                }
            }
            if (c.y != R - 1) {
                tmp = &dp[c.y + 1][c.x];
                if (*tmp < cur + 1 && map[c.y + 1][c.x] < map[c.y][c.x]) {
                    *tmp = cur + 1;
                    q.push(coord(c.x, c.y + 1));
                }
            }
        }
        int tmp = INT_MIN;
//        while (!maxlist.empty()) {
//            coord maxloc = maxlist.back();
//            maxlist.pop_back();
//            if (tmp < dp[maxloc.y][maxloc.x]) {
//                tmp = dp[maxloc.y][maxloc.x];
//            }
//        }
        tmp++;
        printf("%d", tmp);
    }
    return 0;
}

#endif

/**

Sample Input

5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

Sample Output

25

Input: 4 4 1 0 5 6 2 3 4 7 15 16 14 8 13 12 11 10
Output: 15

Input: 1 1 37
Output: 1

Input: 2 3 1 2 5 6 3 4
Output: 4

Input: 3 2 1 2 5 6 3 4
Output: 3

Input: 5 5  5 5 5 5 5 5 4 4 4 5 5 4 1 4 5 5 4 4 4 5 5 5 5 5 5
Output: 3

Input: 5 5  1 1 1 1 1 1 4 4 4 1 1 4 5 4 1 1 4 4 4 1 1 1 1 1 1
Output: 3

Input: 3 5  1 4 5 6 1 4 5 4 7 5 4 4 1 3 2
Output: 5

*/