//
// Created by 40637 on 2017/2/11.
//

//#define USING_1488
#ifdef USING_1488

#include <cstdio>

using namespace std;

int main() {
    bool hasLeft = false;
    char curChar;
    while (scanf("%1c", &curChar)!=EOF) {
        if (curChar == '\"') {
            if (hasLeft) {
                printf("''");
                hasLeft = false;
            } else {
                printf("``");
                hasLeft = true;
            }
        } else
            printf("%c", curChar);
    }
    return 0;
}

#endif

/* Sample input:

"To be or not to be," quoth the Bard, "that
is the question".
The programming contestant replied: "I must disagree.
To `C' or not to `C', that is The Question!"

 */