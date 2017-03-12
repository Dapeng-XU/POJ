//
// Created by 40637 on 2017/2/12.
//

//#define USING_1703
#ifdef USING_1703

#include <cstdio>

using namespace std;

struct Node{
    Node* parent;
    Node* opposite;
};

Node* represent(Node *x) {
    if (x->parent)
        return (x->parent = represent(x->parent));
    else
        return x;
}

void unionSet(Node *a, Node *b) {
    if (a == b)
        return;
    Node *ra = represent(a);
    Node *rb = represent(b);
    if (ra != rb) {
        rb->parent = ra;
    }
}

int main() {
    int T, N, M;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) {
        scanf("%d %d", &N, &M);
        Node *crim = new Node[N+1];
        for (int j = 0; j <= N; j++) {
            crim[j].parent = 0;
            crim[j].opposite = 0;
        }
        char action[3];
        int a, b;
        for (int j = 0; j < M; j++) {
            scanf("%s %d %d", action, &a, &b);
            Node *ra = represent(&crim[a]);
            Node *rb = represent(&crim[b]);
            if (action[0] == 'A') {
                if (!ra->opposite || !rb->opposite) {
                    printf("Not sure yet.\n");
                } else if (ra == rb) {
                    printf("In the same gang.\n");
                } else if (ra->opposite == rb) {
                    printf("In different gangs.\n");
                } else {
                    printf("Not sure yet.\n");
                }
            } else {
                if (!ra->opposite) {
                    if (!rb->opposite) {
                        ra->opposite = rb;
                        rb->opposite = ra;
                    } else {
                        unionSet(rb->opposite, ra);
                    }
                } else {
                    if (!rb->opposite) {
                        unionSet(ra->opposite, rb);
                    } else {
                        unionSet(ra->opposite, rb);
                        unionSet(ra, rb->opposite);
                    }
                }
            }
        }
    }
    return 0;
}

#endif

/*
1
5 5
A 1 2
D 1 2
A 1 2
D 2 4
A 1 4

 */