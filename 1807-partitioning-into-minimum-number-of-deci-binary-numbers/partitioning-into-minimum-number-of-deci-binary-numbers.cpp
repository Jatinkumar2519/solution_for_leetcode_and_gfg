class Solution {
public:
    int minPartitions(string n) {
        int max_v = INT_MIN;
        for(char i : n){
            max_v = max(max_v,i - '0');
        }
        return max_v;
    }
};