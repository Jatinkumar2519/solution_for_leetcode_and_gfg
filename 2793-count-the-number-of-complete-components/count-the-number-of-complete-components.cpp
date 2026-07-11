class Solution {
public:
    vector<int> parent, rank;

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (auto& edge : edges) {
            Union(edge[0], edge[1]);
        }
        vector<int> componentSize(n, 0);  
        vector<int> edgeCount(n, 0);      
        for (int i = 0; i < n; ++i) {
            int root = find(i);
            componentSize[root]++;
        }
        for (auto& edge : edges) {
            int root = find(edge[0]);
            edgeCount[root]++;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (componentSize[i] > 0) {
                if (edgeCount[i] == componentSize[i] * (componentSize[i] - 1) / 2) {
                    res++;
                }
            }
        }

        return res;
    }

private:
    int find(int num) {
        if (parent[num] != num) {
            parent[num] = find(parent[num]);
        }
        return parent[num];
    }

    void Union(int num1, int num2) {
        int par1 = find(num1);
        int par2 = find(num2);
        if (par1 != par2) {
            if (rank[par1] > rank[par2]) {
                parent[par2] = par1;
            } else if (rank[par1] < rank[par2]) {
                parent[par1] = par2;
            } else {
                parent[par2] = par1;
                rank[par1]++;
            }
        }
    }
};
