class Solution {
public:
    void DFS(string search, vector<string>& ans) {
        vector<string> vec = graph[search];
        
        for (int i = 0; i < vec.size(); i++) {
            string neighbor = vec[i];
            
            ans.push_back(neighbor);
            vec.erase(vec.begin() + i);
            graph[search] = vec;
            used++;
            DFS(neighbor, ans);
            if (used == num)
                return;
            
            used--;
            ans.pop_back();
            vec.push_back(neighbor);
            sort(vec.begin(), vec.end());
            graph[search] = vec;
        }
    }

    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        vector<string> ans;
        if (tickets.empty())
            return ans;

        num = tickets.size();
        used = 0;
        for (auto p : tickets) {
            if (graph.find(p.first) == graph.end()) {
                vector<string> vec;
                vec.push_back(p.second);
                graph[p.first] = vec;
            }
            else {
                vector<string> vec = graph[p.first];
                vec.push_back(p.second);
                sort(vec.begin(), vec.end());
                graph[p.first] = vec;
            }
        }
        
        ans.push_back("JFK");
        DFS("JFK", ans);
        return ans;
    }
private:
    unordered_map<string, vector<string> > graph;
    int num;
    int used;
};
