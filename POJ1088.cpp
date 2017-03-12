//
// Created by 40637 on 2017/3/12.
//

#define USING_1088
#ifdef USING_1088

#include <cstdio>
#include <climits>
#include <cstdlib>
#include <vector>

using namespace std;

const int dimension = 120;

int map[dimension][dimension];
int dp[dimension][dimension];
int visited[dimension][dimension];

int C, R;

struct coord {
    int x;
    int y;
    coord (int x0 = -1, int y0 = -1) {
        x = x0;
        y = y0;
    }
};

coord minloc, maxloc;

int search(const coord &c) {
    printf("search(%d, %d)\n", c.y, c.x);
//    system("pause");
    if (dp[c.y][c.x] != INT_MAX) {
        return dp[c.y][c.x];
    } else if (c.x == minloc.x && c.y == minloc.y) {
        dp[c.y][c.x] = 0;
        return 0;
    }
    int farestLength = INT_MIN;
    coord farestCoord;
    if (c.x != 0) { // left node
        coord c2(c.y, c.x - 1);
        if (dp[c2.y][c2.x] == INT_MIN && visited[c2.y][c2.x] == 0) {
            visited[c2.y][c2.x] = 1;
            search(c2);
        }
        if (dp[c2.y][c2.x] > farestLength) {
            farestLength = dp[c2.y][c2.x];
            farestCoord.x = c2.x;
            farestCoord.y = c2.y;
        }
    }
    if (c.y != 0) { // above node
        coord c2(c.y - 1, c.x);
        if (dp[c2.y][c2.x] == INT_MIN && visited[c2.y][c2.x] == 0) {
            visited[c2.y][c2.x] = 1;
            search(c2);
        }
        if (dp[c2.y][c2.x] > farestLength) {
            farestLength = dp[c2.y][c2.x];
            farestCoord.x = c2.x;
            farestCoord.y = c2.y;
        }
    }
    if (c.x != C - 1) { // right node
        coord c2(c.y, c.x + 1);
        if (dp[c2.y][c2.x] == INT_MIN && visited[c2.y][c2.x] == 0) {
            visited[c2.y][c2.x] = 1;
            search(c2);
        }
        if (dp[c2.y][c2.x] > farestLength) {
            farestLength = dp[c2.y][c2.x];
            farestCoord.x = c2.x;
            farestCoord.y = c2.y;
        }
    }
    if (c.y != R - 1) { // following node
        coord c2(c.y + 1, c.x);
        if (dp[c2.y][c2.x] == INT_MIN && visited[c2.y][c2.x] == 0) {
            visited[c2.y][c2.x] = 1;
            search(c2);
        }
        if (dp[c2.y][c2.x] > farestLength) {
            farestLength = dp[c2.y][c2.x];
            farestCoord.x = c2.x;
            farestCoord.y = c2.y;
        }
    }
    int tmp = dp[farestCoord.y][farestCoord.x] + 1;
    dp[c.y][c.x] = tmp;
    printf("%d  ", tmp);
    return tmp;
}

int main() {
    int minval = INT_MAX, maxval = INT_MIN;
    scanf("%d%d", &R, &C);
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            int tmp;
            scanf("%d", &tmp);
            if (minval > tmp) {
                minval = tmp;
                minloc.x = j;
                minloc.y = i;
            }
            if (maxval < tmp) {
                maxval = tmp;
                maxloc.x = j;
                maxloc.y = i;
            }
            map[i][j] = tmp;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            dp[i][j] = INT_MIN;
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            visited[i][j] = 0;
        }
    }
    if (C == 1 && R == 1) {
        printf("0");
    } else {
        int tmp;
        visited[maxloc.y][maxloc.x] = 1;
        tmp = search(maxloc);
        printf("%d", &tmp);
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

*/