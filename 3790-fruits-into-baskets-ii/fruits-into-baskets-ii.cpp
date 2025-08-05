class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count = 0;
        int n = fruits.size();
        vector<int> visit(n,0);
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(visit[j]) continue;
                if(fruits[i] <= baskets[j]){
                    visit[j] = 1;
                    count++;
                    break;
                }
            }
        }
        return n - count;
    }
};