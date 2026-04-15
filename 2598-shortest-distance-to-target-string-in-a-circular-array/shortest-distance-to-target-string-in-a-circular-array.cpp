class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int left = startIndex;
        int right = startIndex;

        int n = words.size();
        for(int i = 0;i < n;i++){
            if(target == words[left] || target == words[right]) return i;
            left = (left + n - 1) % n;
            right = (right + 1) % n;
        }

        return -1;
    }
};