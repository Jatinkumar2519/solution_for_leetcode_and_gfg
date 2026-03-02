class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> arr;

        for(int i = 0;i < n;i++){
            for(int j = n - 1;j >= 0;j--){
                if(grid[i][j] == 1){
                    arr.push_back(j);
                    break;
                }
            }
            if(arr.size() != (i + 1)){
                arr.push_back(0);
            }
        }
        
        int ans = 0;

        for(int i = 0;i < n;i++){
            int k = -1;
            for(int j = i;j < n;j++){
                if(arr[j] <= i){
                    ans += j - i;
                    k = j;
                    break;
                }
            }
            if(~k){
                for(int j = k;j > i;j--){
                    swap(arr[j],arr[j - 1]);
                }
            }
            else{
                return -1;
            }
        }

        return ans;
    }
};