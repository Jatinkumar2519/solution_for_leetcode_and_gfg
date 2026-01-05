class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0;
        int count = 0;
        int maxfar = 0;

        while(maxfar < n - 1){
            int far = maxfar;

            while(i < n && i <= maxfar){
                far = max(far,i + nums[i]);i++;
            }

            if(far == maxfar) return -1;
            maxfar = far;
            count++;
        }

        return count;
    }
};
