class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
        for(auto edge : tickets){
            graph[edge[0]].push(edge[1]);
        }
        vector<string> result;
        function<void(string)> solve = [&](string node) -> void {
            auto& pq = graph[node];
            while(!pq.empty()){
                string next = pq.top();pq.pop();
                solve(next);
            }
            result.push_back(node);
        };
        solve("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};