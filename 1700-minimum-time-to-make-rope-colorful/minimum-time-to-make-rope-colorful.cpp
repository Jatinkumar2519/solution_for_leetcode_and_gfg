class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        int maxv = 0;
        char prev = colors[0];
        for(int i = 0;i < colors.length();i++){
            sum += neededTime[i];
            if(prev == colors[i]){
                maxv = max(maxv,neededTime[i]);
            }
            else{
                sum -= maxv;
                prev = colors[i];
                maxv = neededTime[i];
            }
        }
        sum -= maxv;
        return sum;
    }
};