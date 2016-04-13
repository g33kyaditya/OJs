#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

#define MIN(a,b) (a < b ? a : b)

struct point {
    int x;
    int y;
};

queue<point>q;

void solve(vector< vector<int> >&graph, int n, int m, vector< vector<int> > &ans, 
        vector< vector<bool> > &visited, queue<point> &q) {

        while(!q.empty()) {
            point a = q.front();
            q.pop();
            int k = a.x;
            int l = a.y;
            visited[k][l] = true;
 //           ans[k][l] = 0;
            //Add nodes to queue that can be visited from this node
                
            //Left
            if (l-1 >= 0) {
                if (!visited[k][l-1]) {
                    point b;
                    b.x = k;
                    b.y = l-1;
                    q.push(b);
                    visited[k][l-1] = true;
                    ans[k][l-1] = MIN(ans[k][l-1], ans[k][l] + 1);
                }
            }

            //Right
            if (l+1 < m) {
                if (!visited[k][l+1]) {
                    point b;
                    b.x = k;
                    b.y = l+1;
                    q.push(b);
                    visited[k][l+1] = true;
                    ans[k][l+1] = MIN(ans[k][l+1], ans[k][l] + 1);
                }
            }

            //Up
            if (k-1 >= 0) {
                if (!visited[k-1][l]) {
                    point b;
                    b.x = k-1;
                    b.y = l;
                    q.push(b);
                    visited[k-1][l] = true;
                    ans[k-1][l] = MIN(ans[k-1][l], ans[k][l] + 1);
                }
            }

            //Down
            if (k+1 < n) {
                if (!visited[k+1][l]) {
                    point b;
                    b.x = k+1;
                    b.y = l;
                    q.push(b);
                    visited[k+1][l] = true;
                    ans[k+1][l] = MIN(ans[k+1][l], ans[k][l] + 1);
                }
            }
    }
}

int main() {
    int t;
    cin >> t;
    int n, m;
    while (t--) {
        cin >> n >> m;
        
        vector< vector<int> > graph(n, vector<int>(m));
        vector< vector<int> > ans(n, vector<int>(m));
        vector< vector<bool> > visited(n, vector<bool>(m));
        
        char ch;

        //Input Graph
        string str;
        for (int i = 0; i < n; i++) {
            cin >> str;
            for (int j = 0; j < m; j++) {
                ch = str[j];
                if(ch == '0')
                    graph[i][j] = 0;
                else
                    graph[i][j] = 1;
                
                if (graph[i][j] == 1) {
                    point a;
                    a.x = i;
                    a.y = j;
                    q.push(a);
                }

                visited[i][j] = false;
                ans[i][j] = INT_MAX;
                if (graph[i][j] == 1)
                    ans[i][j] = 0;
            }
        }

        //Solve
        
        solve(graph, n, m, ans, visited, q);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cout << ans[i][j] << " ";

            cout << "\n";
        }
    }
}
