class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s;
        vector<int> pre(n,-1),suf(n,n);
        for(int i = 0;i < n;i++){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                pre[i] = s.top();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n - 1;i >= 0;i--){
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(!s.empty()){
                suf[i] = s.top();
            }
            s.push(i);
        }
        int maxval = 0;
        for(int i = 0;i < n;i++){
            maxval = max(maxval,heights[i] * ((suf[i] - 1) - (pre[i] + 1) + 1));
        }
        return maxval;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxval = 0;
        vector<int> arr(m,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                if(matrix[i][j] == '0'){
                    arr[j] = 0;
                }
                else{
                    arr[j]++;
                }
            }
            maxval = max(maxval,largestRectangleArea(arr));
        }
        return maxval;
    }
};