//
// Created by 40637 on 2017/2/11.
//

// HAVEN'T BEEN SOVLED
//#define USING_1182
#ifdef USING_1182

#include <iostream>
#include <vector>

using namespace std;

struct Set{
    int *array;
    int parentIndex(int x) {
        while (array[x] > 0) {
            x = array[x];
        }
        return x;
    }
    void merge(int a, int b) {
        int root_a_index = parentIndex(a);
        int root_b_index = parentIndex(b);
        if (array[root_a_index] == 0) {
            array[root_a_index] = array[root_b_index];
        } else if (array[root_b_index] == 0) {

        }
    }
    int compare(int a, int b) {

    }
};

int main() {
    int n, k, c = 0;
    Set s;
    s.array = new int[n];
    for (int i = 0; i< n; i++) {
        s.array[i] = 0;
    }
    cin >> n >> k;
    for (int i=0;i<k;i++)
    {
        int d, x, y;
        if (d == 1) {
            if (x > n || y > n || x < 1 || y < 1) {
                c++;
            }
        } else {    // d == 2

        }
    }
    return 0;
}

#endif

/* Sample input:
 *
100 7
1 101 1
2 1 2
2 2 3
2 3 3
1 1 3
2 3 1
1 5 5

 *
 */