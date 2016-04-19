#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <iterator>
#include <queue>
#include <cstdio>
using namespace std;

list<int> *adj;

bool bfs(int v, int start) {
    queue<int> q;
    int color[v+1];
    for (int i = 0; i < v+1; i++)
        color[i] = -1;

    color[start] = 1;   

    q.push(start);
    while(!q.empty()) {
        int vert = q.front();
        q.pop();

        for (list<int>::iterator it = adj[vert].begin(); it != adj[vert].end(); it++) {
            if (color[*it] == -1) {
                color[*it] = 1 - color[vert];
                q.push(*it);
            }

            else if (color[*it] == color[vert])
                return false;
        }
    }

    return true;
}

int main() {
    int t;
    int scenario = 0;
    scanf("%d ", &t);
    int v,e;
    int v1, v2;
    while (t--) {
        scenario++;
        scanf("%d %d", &v, &e);
        adj = new list<int>[v+1];
        for (int i = 0; i < e; i++) {
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        bool ans = true;
        for (int vert = 1; vert <= v; vert++) {
            ans = bfs(v, vert);
            if (!ans)
                break;
        }
        printf("Scenario #%d:\n", scenario);
        if (!ans)    //Not Bipartite
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
    }

}
