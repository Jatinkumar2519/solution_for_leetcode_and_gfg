class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int len = nums.size();
        vector<int> res(len);
        int left = 0;
        int right = len - 1;
        for (int i = 0, j = len - 1; i < len; i++, j--) {
            if (nums[i] < pivot) {
                res[left++] = nums[i];
            }
            if (nums[j] > pivot) {
                res[right--] = nums[j];
            }
        }
        while (left <= right) {
            res[left++] = pivot;
        }
        return res;
    }
};