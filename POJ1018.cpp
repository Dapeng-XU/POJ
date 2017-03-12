//
// Created by 40637 on 2017/2/27.
//

//#define USING_1018
#ifdef USING_1018

#include <cstdio>

using namespace std;

int c[10000000];

int main() {
    double d;
    printf("%d\n", sizeof(int));

    printf("%d\n", sizeof(c));
    for (int i = 0; i< sizeof(c) / sizeof(int); i++) {
        if (i % 8193 == 0) {
            c[i] = -i;
        }
    }
    printf("double: ");
    scanf("%lf", &d);
    printf("round: %.3lf", d);
    return 0;
}

#endif

/*


 */