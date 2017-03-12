//
// Created by 40637 on 2017/2/11.
//

#ifdef USING_1573

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int cols, rows, pos;
    char** map = new char*[10];
    int** path = new int*[10];
    for (int i = 0;i<10; i++) {
        map[i] = new char[10];
        path[i] = new int[10];
    }

    while (true) {
        for (int i=0;i<10;i++) {
            memset(path[i], 0, 10 * sizeof(int));
        }
        cin >> rows >> cols >> pos;
        if (cols == 0) {
            break;
        }
        for (int i = 0;i < rows; i++) {
            cin >> map[i];
        }
        path[0][pos-1] = 1;
        int x = pos - 1, y = 0;
        int steps = 1;
        while (true) {
            switch (map[y][x]) {
                case 'S':
                    y++;
                    break;
                case 'W':
                    x--;
                    break;
                case 'E':
                    x++;
                    break;
                case 'N':
                    y--;
                    break;
            }
            if (x < 0 || x > cols - 1 || y < 0 || y > rows - 1) {
                cout << steps << " step(s) to exit" << endl;
//                cout << "steps: " << steps << endl;
//                cout << "x: " << x << endl;
//                cout << "y: " << y << endl;
                break;
            }
            steps++;
            if (path[y][x] != 0) {
                cout << (path[y][x] - 1) << " step(s) before a loop of "
                        << (steps - path[y][x]) << " step(s)" << endl;
//                cout << "steps: " << steps << endl;
//                cout << "x: " << x << endl;
//                cout << "y: " << y << endl;
                break;
            }
            path[y][x] = steps;
        }
    }
//    int x;
//    cin >> x;
    return 0;
}

#endif

/* Sample input:

3 6 5
NEESWE
WWWESS
SNWWWW
4 5 1
SESWE
EESNW
NWEEN
EWSEN
0 0 0


 */