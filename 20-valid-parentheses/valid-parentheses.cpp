class Solution {
public:
    bool isValid(string s) {
        vector<char> arr;
        for(char i : s){
            if (arr.size() != 0 && i == ')' && arr[arr.size()-1] == '('){
                arr.erase(arr.begin() + (arr.size()-1));
            }
            else if (arr.size() != 0 && i == ']' && arr[arr.size()-1] == '['){
                arr.erase(arr.begin() + (arr.size()-1));
            }
            else if (arr.size() != 0 && i == '}' && arr[arr.size()-1] == '{'){
                arr.erase(arr.begin() + (arr.size()-1));
            }
            else{
                arr.push_back(i);
            }
        }
        if (arr.size() != 0){
            return false;
        }
        return true;
    }
};