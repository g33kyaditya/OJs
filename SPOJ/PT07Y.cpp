#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
using namespace std;
int n,m;
bool ans = false;
list<int>*adj;
void DFSUtility(int , bool*);
inline void DFS (list<int>*adj) {
    bool visited[n+1];
    for (int i=0;i<=n+1;i++)
        visited[i] = false;

    for (int i=0;i<=n;i++) {
        if (!visited[i])
            DFSUtility (i,visited);
    }   
}
void DFSUtility(int v,bool *visited) {
    visited[v] = true;
    list<int>::iterator it;
    for (it = adj[v].begin();it!=adj[v].end();it++) {
        if (!visited[*it])
            DFSUtility(*it,visited);
        else {
            ans = true;
            return;
        }
    }
}
int main() {
    cin >> n;
    cin >> m;
    adj = new list<int>[n+1];
    for (int i=0,j,k;i<m;i++) {
        cin >> j >> k;
        adj[j].push_back(k);
    }
    DFS(adj);
    if (ans)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
