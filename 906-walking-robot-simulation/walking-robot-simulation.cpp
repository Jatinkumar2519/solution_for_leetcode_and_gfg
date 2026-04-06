class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int dir = 0;

        int dirx[4] = {0,1,0,-1};
        int diry[4] = {1,0,-1,0};

        int n = commands.size();

        set<pair<int,int>> obs;
        for(auto& ob : obstacles){
            obs.insert({ob[0],ob[1]});
        }

        int x = 0,y = 0;
        int maxd = 0;

        for(auto& d : commands){
            if(d == -2){
                dir = (dir + 3) % 4;
            }
            else if(d == -1){
                dir = (dir + 1) % 4;
            }
            else{
                int k = d;

                while(!obs.count({x + dirx[dir],y + diry[dir]}) && k > 0){
                    x += dirx[dir];
                    y += diry[dir];
                    k--;
                }
            }

            // cout<< x << " " << y << endl;
            maxd = max(maxd,x * x + y * y);
        }

        return maxd;
    }
};