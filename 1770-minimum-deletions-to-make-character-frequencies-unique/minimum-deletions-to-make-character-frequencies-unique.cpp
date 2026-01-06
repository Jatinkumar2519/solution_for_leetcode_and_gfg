class Solution {
public:
    int minDeletions(string str) {
        vector<int> arr(26, 0);

        for (auto& ch : str) {
            arr[ch - 'a']++;
        }
        sort(arr.begin(), arr.end());

        int count = 0;
        unordered_set<int> visited;

        for (int i = 25; i >= 0; i--) {
            while (arr[i] > 0 && visited.find(arr[i]) != visited.end()) {
                count++;
                arr[i]--;
            }
            if (arr[i] > 0) {
                visited.insert(arr[i]);
            }
        }
        return count;
    }
};