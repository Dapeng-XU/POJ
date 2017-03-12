//
// Created by 40637 on 2017/3/12.
//

//#define USING_1050
#ifdef USING_1050

#include <cstdio>

using namespace std;

const int dimension = 150;

char src[dimension * dimension];
int dp[dimension * dimension];

int main() {
    int N;
    scanf("%d", &N);

    printf();
    return 0;
}

#endif

//struct coord {
//    int x;
//    int y;
//    coord(int x0=0, int y0=0) {
//        x = x0; y = y0;
//    }
//};
//
//inline int convert2dto1d(coord &c) {
//    return c.x * dimension + c.y;
//};
//
//inline coord& convert1dto2d(int x) {
//    coord c;
//    c.y = x % dimension;
//    c.x = x / dimension;
//    return c;
//}

/**

Sample Input

4
0 -2 -7 0 9 2 -6 2
-4 1 -4  1 -1

8  0 -2
Sample Output

15

*/