class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> set(nums.begin(),nums.end());
        int minv = *min_element(nums.begin(),nums.end());
        int maxv = *max_element(nums.begin(),nums.end());
        
        while(minv <= maxv){
            if(set.count(minv) == 0){
                result.push_back(minv);
            }
            minv++;
        }
        return result;
    }
};