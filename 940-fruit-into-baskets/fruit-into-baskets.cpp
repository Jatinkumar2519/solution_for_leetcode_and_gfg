class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int maxlen = 0;
        int n = fruits.size();
        unordered_map<int,int> map;
        for(int i = 0;i < n;i++){
            map[fruits[i]]++;
            while(map.size() > 2){
                if(--map[fruits[left]] == 0){
                    map.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen,i - left + 1);
        }
        return maxlen;
    }
};