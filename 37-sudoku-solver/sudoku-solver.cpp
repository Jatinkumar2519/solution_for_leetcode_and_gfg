class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowmap(10,vector<int>(10,0)),colmap(10,vector<int>(10,0)),boxmap(10,vector<int>(10,0));
        function<bool(int,int)> solve = [&](int i,int j) -> bool{
            if(i == 9) return true;
            if(j == 9) return solve(i + 1,0);
            if(board[i][j] != '.') return solve(i,j + 1);
            for(int num = 1;num < 10;num++){
                int key = (i / 3) * 3 + (j / 3); 
                if(rowmap[i][num] == 0 && colmap[j][num] == 0 && boxmap[key][num] == 0){
                    rowmap[i][num]++;
                    colmap[j][num]++;
                    boxmap[key][num]++;
                    board[i][j] = '0' + num;
                    if(solve(i,j + 1)) return true;
                    board[i][j] = '.';
                    rowmap[i][num]--;
                    colmap[j][num]--;
                    boxmap[key][num]--;
                }
            }
            return false;
        };
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                if(board[i][j] == '.') continue;
                int key = (i / 3) * 3 + (j / 3); 
                rowmap[i][board[i][j] - '0']++;
                colmap[j][board[i][j] - '0']++;
                boxmap[key][board[i][j] - '0']++;
            }
        }
        solve(0,0);
    }
};