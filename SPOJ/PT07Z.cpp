#include <iostream>
#include <iterator>
#include <queue>
#include <list>
#include <algorithm>
#include <vector>
using namespace std;
int n;
list<int>*adj;
queue<pair<int,int> > q;
vector<int> maxWt(10009);
int answer = 0;
void bfs (list<int>*adj,int z) {
    bool visited[n+1] ;
    for (int i=0;i<=n+1;i++)
	visited[i] = false;
    
    int v;
    q.push(make_pair(z,0));
    int weight ;
    while (!q.empty()) {
      v = q.front().first;
      weight = q.front().second;
      visited[v] = true;
      q.pop();
      //cout << "v = " << v << endl;
      for (list<int>::iterator it = adj[v].begin() ;it!=adj[v].end(); ++it) {
	    if (!visited[*it]) {
	     // cout << "Pushing " << *it << endl;
         // cout << "Weight of " << *it << " = " << weight+1 << endl;
          q.push(make_pair(*it,weight+1));
	    }
      }
      //cout << "maxWt["<<v<<"] = " << weight << endl;
      maxWt[v]=weight;
    }
}

int main() {
    cin >> n;
    adj = new list<int>[n+1];
    for (int i=0,j,k;i<n-1;i++) {
        cin >> j >> k;
        adj[j].push_back(k);
        adj[k].push_back(j);
    }
      bfs(adj,1);
      vector<int>::iterator it;
      it = max_element(maxWt.begin(),maxWt.end());
      //cout << "*it = " << *it << endl;
      int bar;
      for (int i=0;i<=n;i++) {
        if (*it == maxWt[i]) {
            bar = i;
            break;
        }
      }
      for (int i=0;i<=n;i++) {
        maxWt[i] = 0;
      }
      bfs(adj,bar);
      it = max_element(maxWt.begin(),maxWt.end());
      answer = *it;
      cout << answer << endl;
}
