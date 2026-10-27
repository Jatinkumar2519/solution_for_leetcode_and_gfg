class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> result(m,string(n,'#'));

        for(int i = 0;i < n;i++){
            result[m - 1][i] = '.';
        }
        for(int i = 0;i < m;i++){
            result[i][0] = '.';
        }

        return result;
    }
};