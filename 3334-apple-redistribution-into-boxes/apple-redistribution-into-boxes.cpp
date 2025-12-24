class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<int>());
        int target = accumulate(apple.begin(),apple.end(),0);
        int sum = 0;
        int i = 0;
        while(i < capacity.size()){
            sum += capacity[i++];
            if(sum >= target) return i;
        }
        return -1;
    }
};