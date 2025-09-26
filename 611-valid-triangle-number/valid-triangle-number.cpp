class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                int left = j;
                int indx = left;
                int right = n - 1;
                int sum = nums[i] + nums[j];
                while(left <= right){
                    int mid = (left + right)/2;
                    if(sum > nums[mid]){
                        indx = mid;
                        left = mid + 1;
                    }
                    else{
                        right = mid - 1;
                    }
                }
                count += (indx - j);
            }
        }
        return count;
    }
};