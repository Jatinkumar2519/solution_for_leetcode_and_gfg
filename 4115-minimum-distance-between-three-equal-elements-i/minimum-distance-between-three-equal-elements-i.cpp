class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int,vector<int>> map;

        for(int i = 0;i < nums.size();i++){
            map[nums[i]].push_back(i);
        }

        int minv = -1;

        for(auto [_,arr] : map){
            for(int i = 0;i + 2 < arr.size();i++){
                int d = (arr[i + 1] - arr[i]) + (arr[i + 2] - arr[i + 1]) + (arr[i + 2] - arr[i]);
                if(minv == -1){
                    minv = d;
                }
                else{
                    minv = min(minv,d);
                }
            }
        }

        return minv;
    }
};