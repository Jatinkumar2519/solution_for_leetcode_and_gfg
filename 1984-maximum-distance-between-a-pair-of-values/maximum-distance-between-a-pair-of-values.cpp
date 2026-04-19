class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int maxv = 0;
        for(int i = 0;i < n;i++){
            int left = i;
            int right = m - 1;

            int indx = -1;
            while(left <= right){
                int mid = (left + right)/2;

                if(nums1[i] <= nums2[mid]){
                    indx = mid;
                    left = mid + 1;
                }
                else{
                    right = mid - 1;
                }
            }

            if(indx != -1){
                maxv = max(maxv,indx - i);
            }
        }

        return maxv;
    }
};