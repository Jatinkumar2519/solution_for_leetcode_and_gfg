class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;int right = n - 1;
        int maxval = 0;
        while(left < right){
            int widht = right - left;
            int heigt = min(height[left],height[right]);
            maxval = max(maxval,widht * heigt);
            if(height[left] < height[right]) left++;
            else right --;
        }
        return maxval;
    }
};