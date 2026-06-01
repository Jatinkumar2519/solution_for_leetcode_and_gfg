class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(),cost.end(),greater<>());

        int res = 0;
        for(int i = 0;i < n;){
            res += cost[i];i++;
            if(i < n){
                res += cost[i];i++;
            }
            i++;
        }
        return res;
    }
};