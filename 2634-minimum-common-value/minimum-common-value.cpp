class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums2.begin(),nums2.end());

        int minv = INT_MAX;
        for(int num : nums1){
            if(set.count(num)){
                minv = min(minv,num);
            }
        }

        return (minv == INT_MAX ? -1 : minv);
    }
};