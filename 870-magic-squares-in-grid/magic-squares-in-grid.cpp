class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid.size();
        int m = grid[0].size();

        int target = 0;
        for(int i = 1;i < 10;i++){
            target |= (1 << i);
        }

        auto check = [&](int i,int j){
            int mask = 0;
            int d1 = 0;
            int d2 = 0;

            unordered_set<int> sums;

            for(int p = i;p <= i + 2;p++){
                int row = 0;
                for(int q = j;q <= j + 2;q++){
                    mask |= (1 << grid[p][q]);
                    row += grid[p][q];
                }
                sums.insert(row);
            }

            for(int q = j;q <= j + 2;q++){
                int col = 0;
                for(int p = i;p <= i + 2;p++){
                    col += grid[p][q];
                }
                sums.insert(col);
            }

            int p = i;
            int q = j;

            while(p <= i + 2 && q <= j + 2){
                d1 += grid[p][q];
                p++;q++;
            }
            sums.insert(d1);

            p = i + 2;
            q = j;

            while(p >= i && q <= j + 2){
                d2 += grid[p][q];
                p--;q++;
            }
            sums.insert(d2);

            return (mask == target && sums.size() == 1);
        };

        for(int i = 0;i + 2 < n;i++){
            for(int j = 0;j + 2 < m;j++){
                count += check(i,j);
            }
        }
        return count;
    }
};