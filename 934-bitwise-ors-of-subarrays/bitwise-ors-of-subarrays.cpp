class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> res;
        unordered_set<int>* prev = new unordered_set<int>();
        for(int i = 0;i < n;i++){
            unordered_set<int>* curr = new unordered_set<int>();
            curr->insert(arr[i]);
            for(int num : *prev){
                curr->insert(num | arr[i]);
            }
            prev = curr;
            for(int num : *curr){
                res.insert(num);
            }
        }
        return res.size();
    }
};