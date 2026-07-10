class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ids(n);

        int id = 0;
        ids[0] = id;

        for(int i = 1;i < n;i++){
            if(nums[i] - nums[i - 1] > maxDiff) id++;
            ids[i] = id;
        }

        vector<bool> result;
        for(auto& q : queries){
            result.push_back(ids[q[0]] == ids[q[1]]);
        }

        return result;
    }
};