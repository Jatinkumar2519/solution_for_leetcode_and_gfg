class Solution {
public:
    int minimumDistance(string word) {
        int n = word.length();

        unordered_map<char,pair<int,int>> keyboard;

        keyboard['A'] = {0,0};
        keyboard['B'] = {0,1};
        keyboard['C'] = {0,2};
        keyboard['D'] = {0,3};
        keyboard['E'] = {0,4};
        keyboard['F'] = {0,5};

        keyboard['G'] = {1,0};
        keyboard['H'] = {1,1};
        keyboard['I'] = {1,2};
        keyboard['J'] = {1,3};
        keyboard['K'] = {1,4};
        keyboard['L'] = {1,5};

        keyboard['M'] = {2,0};
        keyboard['N'] = {2,1};
        keyboard['O'] = {2,2};
        keyboard['P'] = {2,3};
        keyboard['Q'] = {2,4};
        keyboard['R'] = {2,5};

        keyboard['S'] = {3,0};
        keyboard['T'] = {3,1};
        keyboard['U'] = {3,2};
        keyboard['V'] = {3,3};
        keyboard['W'] = {3,4};
        keyboard['X'] = {3,5};

        keyboard['Y'] = {4,0};
        keyboard['Z'] = {4,1};

        int dp[6][7][6][7][301];
        function<int(int,int,int,int,int)> solve = [&](int x1,int y1,int x2,int y2,int i)->int{
            if(i == n) return 0;

            if(dp[x1 + 1][y1 + 1][x2 + 1][y2 + 1][i] != -1) return dp[x1 + 1][y1 + 1][x2 + 1][y2 + 1][i];

            int minv = INT_MAX;
            int nx = keyboard[word[i]].first;
            int ny = keyboard[word[i]].second;

            if(x1 == -1 && y1 == -1){
                minv = solve(nx,ny,x2,y2,i + 1);
            }
            else{
                int d = abs(nx - x1) + abs(ny - y1);
                minv = min(minv,d + solve(nx,ny,x2,y2,i + 1));
            }

            if(x2 == -1 && y2 == -1){
                minv = min(minv,solve(x1,y1,nx,ny,i + 1));
            }
            else{
                int d = abs(nx - x2) + abs(ny - y2);
                minv = min(minv,d + solve(x1,y1,nx,ny,i + 1));
            }

            return dp[x1 + 1][y1 + 1][x2 + 1][y2 + 1][i] = minv;
        };

        memset(dp,-1,sizeof(dp));
        return solve(-1,-1,-1,-1,0);
    }
};