class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        // vector<int> limit(n,INT_MAX);

        // for(auto& rest : restrictions){
        //     limit[rest[0] - 1] = rest[1];
        // }

        // limit[0] = 0;

        // for(int i = 1;i < n;i++){
        //     limit[i] = min(limit[i - 1] + 1,limit[i]);
        // }

        // for(int i = n - 2;i >= 0;i--){
        //     limit[i] = min(limit[i + 1] + 1,limit[i]);
        // }

        // return *max_element(limit.begin(),limit.end());

        restrictions.push_back({1,0});
        sort(restrictions.begin(),restrictions.end());

        for(int i = 1;i < restrictions.size();i++){

            auto& prev = restrictions[i - 1];
            auto& curr = restrictions[i];

            int dist = curr[0] - prev[0];

            curr[1] = min(curr[1],prev[1] + dist);
        }

        int maxv = 0;
        for(int i = restrictions.size() - 2;i >= 0;i--){

            auto& prev = restrictions[i + 1];
            auto& curr = restrictions[i];

            int dist = prev[0] - curr[0];

            curr[1] = min(curr[1],prev[1] + dist);

            int peak = (curr[1] + prev[1] + dist) / 2; // did GPT for this 
            maxv = max(maxv, peak);
        }
        

        if(restrictions.back()[0] < n){
            maxv = max(maxv,restrictions.back()[1] + (n - restrictions.back()[0]));
        }

        return maxv;
    }
};