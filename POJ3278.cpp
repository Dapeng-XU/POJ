//
// Created by 40637 on 2017/2/13.
//

//#define USING_3278
#ifdef USING_3278

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int UPPERBOUND = 200000;
const int eigen = -1;

int maxval = UPPERBOUND;

bool visited[UPPERBOUND + 1];

int main() {
    int n, k, c = 0;
    cin >> n >> k;
    if (k < n) {
        cout << (n - k);
    } else { // Thus we have the condition k >= n (n <= k).
        memset(visited, 0, sizeof(bool) * (UPPERBOUND + 1));
        int minval = n / 2;
        maxval = (maxval < (k * 2)) ? maxval : (k * 2);
        queue<int> q;  // The location of the farmer
        q.push(n);
        q.push(eigen);
        while (true) {
            int cur = q.front();
            q.pop();
//            cout << cur << " ";
            if (cur == k) {
                break;
            }
            if (cur == eigen) {
                q.push(eigen);
                c++;
//                cout << c << endl;
//                cout << endl;
                continue;
            }
            if (!visited[cur]) {
                visited[cur] = true;
            } else {
                continue;
            }
            // check constraints
            int ret;
            ret = cur + 1;
            if (ret <= maxval) {
                q.push(ret);
            }
            ret -= 2;
            if (minval <= ret) {
                q.push(ret);
            }
            ret = cur << 1;
            if (ret <= maxval) {
                q.push(ret);
            }
        }
        cout << c;
    }
//    int x; cin >> x;
    return 0;
}

#endif