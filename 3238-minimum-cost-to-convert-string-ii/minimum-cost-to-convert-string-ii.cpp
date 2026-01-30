class Solution {
public:

    struct Node{
        bool isend;
        Node* child[26];
        Node(){
            isend = false;
            for(int i = 0;i < 26;i++){
                child[i] = nullptr;
            }
        }
    };
    Node* root = new Node();

    void insert(string word){
        Node* temp = root;

        for(auto& ch : word){
            if(temp->child[ch - 'a'] == nullptr){
                temp->child[ch - 'a'] = new Node();
            }
            temp = temp->child[ch - 'a'];
        }
        temp->isend = true;
    }
    
    long long minimumCost(string source, string target,
                          vector<string>& original, vector<string>& changed,
                          vector<int>& cost) {

        int n = original.size();
        unordered_map<string, int> mp;
        int idx = 0;

        for (auto& s : original){
            insert(s);
            if (!mp.count(s)){
                mp[s] = idx++;
            }
        }
        for (auto& s : changed){
            insert(s);
            if (!mp.count(s)){
                mp[s] = idx++;
            }
        }

        const int INF = 1e9;

        vector<vector<int>> graph(idx, vector<int>(idx, INF));
        for (int i = 0; i < idx; i++)
            graph[i][i] = 0;

        for (int i = 0; i < n; i++) {
            int u = mp[original[i]];
            int v = mp[changed[i]];
            graph[u][v] = min(graph[u][v], cost[i]);
        }

        for(int k = 0;k < idx;k++){
            for(int i = 0;i < idx;i++){
                for(int j = 0;j < idx;j++){
                    if(graph[i][k] != INF && graph[k][j] != INF){
                        graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
                    }
                }
            }
        }

        int m = source.size();
        vector<long long> dp(m + 1, -1);

        function<long long(int)> solve = [&](int pos) -> long long {
            if (pos == m)
                return 0;
            if (dp[pos] != -1)
                return dp[pos];

            long long ans = LLONG_MAX;
            if(source[pos] == target[pos]){
                ans = solve(pos + 1);
            }

            string s1, s2;
            Node* temp1 = root;
            Node* temp2 = root;
            for (int i = pos; i < m; i++) {
                s1.push_back(source[i]);
                s2.push_back(target[i]);
                
                temp1 = temp1->child[source[i] - 'a'];
                temp2 = temp2->child[target[i] - 'a'];

                if(!temp1 || !temp2){
                    break;
                }
                
                if(temp1->isend && temp2->isend){
                    int u = mp[s1], v = mp[s2];
                    if (graph[u][v] == INF)
                        continue; 

                    long long nxt = solve(i + 1);
                    if (nxt == LLONG_MAX)
                        continue;

                    ans = min(ans, nxt + graph[u][v]);
                }
            }
            return dp[pos] = ans;
        };

        long long res = solve(0);
        return (res == LLONG_MAX ? -1 : res);
    }
};
