/**************************** ADD-UP ************************************
the BFS algorithm is as follows:

BFS(G, s)
[for all nodes, mark unexplored]
- mark s as explored
- let Q = queue ds, initiated with s
- while Q not empty
    - remove 1st node of Q, call it v
    - for each edge(v, w)
    - if w unexplored
        - mark w as explored
        - add w to Q

so the main while loop's time complexity is proportional to s, namely
O(Ns + Ms), all nodes and all edges (see the if-unexplored statement,
each loop takes us O(1) constant time) reachable from s.

the DFS algorithm is as follows:

DFS(G, s)
[for all nodes, mark unexplored]
- mark s as explored
- for every edge(s, v)
    - if v unexplored
        - DFS(G, v)

time complexity is also O(Ns + Ms), nodes reachable from s are visited
at most once and edges reachable from s are visited at most twice.
*************************************************************************/

//////////////////////////////////////////////////////////////////////////
// use breath-first-search or depth-first-search to do find
// time complexity is O(M + N) [or O(max(M, N))]
//////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <list>
#include <assert.h>
using namespace std;

bool *BFS(bool **adj_m, int n, int s, int d) {
    bool *explored = new bool[n];
    memset(explored, 0, sizeof(explored));
    int v, w;
    list<int> l;

    explored[s] = true;
    l.push_back(s);

    while (!l.empty()) {
        w = -1;
        v = l.front();
        l.pop_front();

        // find next edge
        while (++w < n && !adj_m[v][w]);
        while (w < n) {
            if (!explored[w]) {
                explored[w] = true;
                l.push_back(w);
            }

            while (++w < n && !adj_m[v][w]);
        }
    }

    return explored;
}

int main() {
    srand(time(0));
    int n = 5, j = 0, s = rand() % n;
    bool **adj_m = new bool *[n];

    for (int i = 0; i < n; ++i) {
        adj_m[i] = new bool[n];
        memset(adj_m[i], 0, sizeof(adj_m[i]));
    }

    // randomize adjacent matrix
    while ((j = j + 1 + rand() % n) < n * n) {
        adj_m[j / n][j % n] = true;
    }

    // print adjacent matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%d ", adj_m[i][j]);
        }
        printf("\n");
    }

    //while (!adj_m[s / n][s % n]) { ++s; }
    for (int d = 0; d < n; ++d) {
        bool *explored = BFS(adj_m, n, s, d);
        assert(explored);

        printf("Is there a route from v-%d to v-%d? ", s, d);
        cout << (explored[d] ? "Yes" : "No") << endl;
        delete explored;
    }

    return 0;
}
