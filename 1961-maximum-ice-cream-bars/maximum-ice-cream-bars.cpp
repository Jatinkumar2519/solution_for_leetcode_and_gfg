class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {

        sort(costs.begin(),costs.end());

        int sum = 0;
        int count = 0;

        for(int num : costs){
            if(sum + num > coins) break;
            sum += num;
            count++;
        }

        return count;
    }
};