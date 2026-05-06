class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int n = boxGrid.size();
        int m = boxGrid[0].size();

        for(int i = 0;i < n;i++){
            int j = 0;
            for(int k = 0;k < m;k++){
                if(boxGrid[i][k] == '.'){
                    swap(boxGrid[i][j],boxGrid[i][k]);
                    j++;
                }
                else if(boxGrid[i][k] == '*'){
                    j = k + 1;
                }
            }
        }

        vector<vector<char>> result(m,vector<char>(n));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                result[j][i] = boxGrid[i][j];
            }
        }

        for(auto& arr : result){
            reverse(arr.begin(),arr.end());
        }
        return result;
    }
};