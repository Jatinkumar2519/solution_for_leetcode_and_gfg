class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,unordered_set<int>> map;

        int id = 1;
        for(int i = 0;i + k <= n;i++){
            for(int j = i;j < i + k;j++){
                map[nums[j]].insert(id);
            }
            id++;
        }

        int maxv = -1;
        for(auto& [num,set] : map){
            if(set.size() == 1){
                maxv = max(maxv,num);
            }
        }

        return maxv;
    }
};