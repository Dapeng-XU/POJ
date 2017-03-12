//
// Created by 40637 on 2017/2/11.
//

//#define USING_1611
#ifdef USING_1611

#include <iostream>

using namespace std;

struct Node{
    Node* parent;
};

Node* findParent(Node* x) {
    if (!x->parent) {
        return x;
    } else {
        Node* y = findParent(x->parent);
        x->parent = y;
        return y;
    }
}

void unionSet(Node *a, Node *b) {
    if (a == b)
        return;
    Node *pa = findParent(a);
    Node *pb = findParent(b);
    if (pa != pb) {
        pb->parent = pa;
    }
}

int main() {
    int n, m, k, c;
    while(true) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }
        Node* stu = new Node[n];
        for (int i = 0; i < n; i++) {
            stu[i].parent = 0;
        }
        c = 1;
        for (int i = 0; i < m; i++) {
            cin >> k;
            int curline_0, curline_j;
            cin >> curline_0;
            for (int j = 1; j < k; j++) {
                cin >> curline_j;
                unionSet(findParent(&stu[curline_0]), &stu[curline_j]);
            }
        }
        Node* zeroval = findParent(&stu[0]);
        for (int i = 1; i < n; i++) {
            if (findParent(&stu[i]) == zeroval) {
                c++;
            }
        }
        cout << c << endl;
        delete[] stu;
    }
    return 0;
}

#endif

/* Sample input:

100 4
2 1 2
5 10 13 11 12 14
2 0 1
2 99 2
200 2
1 5
5 1 2 3 4 5
1 0
0 0

 */