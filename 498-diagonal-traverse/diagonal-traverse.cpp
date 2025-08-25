class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        int count = 0;
        int n = mat.size();
        int m = mat[0].size();
        for(int row = 0;row < n;row++){
            int i = row,j = 0;
            vector<int> dia;
            while(i >= 0 && j < m){
                dia.push_back(mat[i--][j++]);
            }
            if(count % 2 == 0){
                for(int k = 0;k < dia.size();k++){
                    result.push_back(dia[k]);
                }
            }
            else{
                for(int k = dia.size() - 1;k >= 0;k--){
                    result.push_back(dia[k]);
                }
            }
            count++;
        }
        for(int col = 1;col < m;col++){
            int i = n - 1,j = col;
            vector<int> dia;
            while(i >= 0 && j < m){
                dia.push_back(mat[i--][j++]);
            }
            if(count % 2 == 0){
                for(int k = 0;k < dia.size();k++){
                    result.push_back(dia[k]);
                }
            }
            else{
                for(int k = dia.size() - 1;k >= 0;k--){
                    result.push_back(dia[k]);
                }
            }
            count++;
        }
        return result;
    }
};