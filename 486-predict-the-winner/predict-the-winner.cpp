class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();

        function<bool(int,int,int,bool)> solve = [&](int i,int j,int sum,bool myTurn){
            if(i > j) return sum >= 0;

            if(myTurn) 
                return solve(i + 1,j,sum + nums[i],false) ||
                       solve(i,j - 1,sum + nums[j],false);

            return solve(i + 1,j,sum - nums[i],true) && solve(i,j - 1,sum - nums[j],true);
        };

        return solve(0,n - 1,0,true);
    }
};