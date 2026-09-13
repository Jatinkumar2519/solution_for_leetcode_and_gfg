class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int maxv = 0, n = img1.size();

        for(int i = -n + 1;i < n;i++){
            for(int j = -n + 1;j < n;j++){
                
                int count = 0;
                for(int p = 0;p < n;p++){
                    for(int q = 0;q < n;q++){
                        
                        if(p + i < n && p + i >= 0 && q + j < n && q + j >= 0){
                            count += (img1[p + i][q + j] && img2[p][q]);
                        }
                    }
                }

                maxv = max(maxv,count);
            }
        }

        return maxv;
    }
};