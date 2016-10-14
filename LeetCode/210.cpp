class Solution {

public:

    void DFS(int v, bool * visited, vector<int>& ans, bool * onStack) {

        visited[v] = true;

        onStack[v] = true;

        auto it = adj[v].begin();

        for (it; it != adj[v].end(); it++) {

            if (!visited[*it]) {

                DFS(*it, visited, ans, onStack);

            }

            else if (onStack[*it]) {

                ans.clear();

                return;

            }

        }

        onStack[v] = false;

        ans.push_back(v);

    }

    vector<int> findOrder(int n, vector<pair<int, int>>& pre) {

        vector<int> ans;

        if (n == 0)

            return ans;

        

        buildGraph(n, pre);

        bool visited[n] = {false};

        bool onStack[n] = {false};

        for (int i = 0; i < n; i++) {

            if (!visited[i])

                DFS(i, visited, ans, onStack);

        }

        if (ans.size() != n) {

            ans.clear();

            return ans;

        }



        reverse(ans.begin(), ans.end());

        return ans;

    }

    

    void buildGraph(int n, vector<pair<int, int>>& edges) {

        adj = new list<int>[n];

        

        for (int i = 0; i < edges.size(); i++) {

            pair<int,int> cur = edges[i];

            adj[cur.second].push_back(cur.first);

        }

    }

private:

    list<int> *adj;

};


===========================================================================================================================================

//Using DFS


class Solution {
public:
    void DFS(int v, bool * visited, vector<int>& ans, bool * onStack) {
        visited[v] = true;
        onStack[v] = true;
        auto it = adj[v].begin();
        for (it; it != adj[v].end(); it++) {
            if (!visited[*it]) {
                DFS(*it, visited, ans, onStack);
            }
            else if (onStack[*it]) {
                ans.clear();
                return;
            }
        }
        onStack[v] = false;
        ans.push_back(v);
    }
    vector<int> findOrder(int n, vector<pair<int, int>>& pre) {
        vector<int> ans;
        if (n == 0)
            return ans;
        
        buildGraph(n, pre);
        bool visited[n] = {false};
        bool onStack[n] = {false};
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                DFS(i, visited, ans, onStack);
        }
        if (ans.size() != n) {
            ans.clear();
            return ans;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    void buildGraph(int n, vector<pair<int, int>>& edges) {
        adj = new list<int>[n];
        
        for (int i = 0; i < edges.size(); i++) {
            pair<int,int> cur = edges[i];
            adj[cur.second].push_back(cur.first);
        }
    }
private:
    list<int> *adj;
};
