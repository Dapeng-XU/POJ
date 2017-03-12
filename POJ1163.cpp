//
// Created by 40637 on 2017/3/12.
//

//#define USING_1163
#ifdef USING_1163

#include <cstdio>

const int dimension = 105;

int dp[dimension][dimension];

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 1;i<=N;i++) {  // There are i numbers in line i;
        for (int j = 1;j<=i; j++) {
            scanf("%d", &dp[i][j]);
        }
    }
    for (int i=N - 1;i>=1;i--) {
        for (int j = 1; j<=i ; j++) {
            dp[i][j] += (dp[i+1][j] >= dp[i+1][j+1]) ? dp[i+1][j] : dp[i+1][j+1];
        }
    }
    printf("%d", dp[1][1]);
    return 0;
}

#endif

/***

Sample Input

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
Sample Output

30

 */