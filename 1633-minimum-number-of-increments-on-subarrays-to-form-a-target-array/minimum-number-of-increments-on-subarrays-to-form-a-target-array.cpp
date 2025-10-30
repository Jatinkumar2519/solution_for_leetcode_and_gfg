class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int count = target[0];
        for(int i = 1;i < target.size();i++){
            count += max(0,target[i] - target[i - 1]);
        }
        return count;
    }
};