class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> arr;

        char curr = s[0];
        int count = 1;

        for(int i = 1;i < s.length();i++){
            if(curr == s[i]){
                count++;
            }
            else{
                arr.push_back(count);
                curr = s[i];
                count = 1;
            }
        }

        arr.push_back(count);

        int total = 0;
        
        for(int i = 0;i + 1 < arr.size();i++){
            total += min(arr[i],arr[i + 1]);
        }

        return total;
    }
};