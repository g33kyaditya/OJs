class Solution {
public:
    double dfs(string vert, string dest, double cur) {
        if (visited.find(vert) == visited.end() || visited.find(dest) == visited.end())
            return double(-1);
        
        if (vert == dest)
            return cur;
    
        visited[vert] = true;
        double ans = -1;
        auto vec = graph[vert];
        for (auto p : vec) {
            if (!visited[p.first]) {
                ans = dfs(p.first, dest, cur*p.second);
                if (ans != -1)
                    return ans;
            }
        }
        
        return ans;
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        vector<double> ans;
        if (equations.empty() || values.empty() || queries.empty())
            return ans;
        
        buildGraph(equations, values);
        
        for (auto query : queries) {
            double val = dfs(query.first, query.second, 1);
            ans.push_back(val);
            
            for (auto it = visited.begin(); it != visited.end(); it++)
                it->second = false;
        }
        
        return ans;
    }
    
    void buildGraph(vector<pair<string, string>>& equations, vector<double>& values) {
        int i = -1;
        for (auto p : equations) {
            i++;
            visited[p.first] = false;
            visited[p.second] = false;
            if (graph.find(p.first) == graph.end()) {
                vector<pair<string, double>> vec;
                vec.push_back(make_pair(p.second, values[i]));
                graph[p.first] = vec;
            }
            else {
                vector<pair<string, double>> vec = graph[p.first];
                vec.push_back(make_pair(p.second, values[i]));
                graph[p.first] = vec;
            }

            if (graph.find(p.second) == graph.end()) {
                vector<pair<string, double>> vec;
                double v = 1.0/double(values[i]);
                vec.push_back(make_pair(p.first, v));
                graph[p.second] = vec;
            }
            else {
                vector<pair<string, double>> vec = graph[p.second];
                double v = 1.0/double(values[i]);
                vec.push_back(make_pair(p.first, v));
                graph[p.second] = vec;
            }
        }
    }
private:
    unordered_map<string, vector<pair<string, double>>> graph;
    unordered_map<string, bool> visited;
};
