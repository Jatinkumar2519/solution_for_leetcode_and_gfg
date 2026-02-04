class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string map[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        queue<string> q;
        for(auto& ch : digits){
            int num = ch - '0';
            if(q.empty()){
                for(auto& c : map[num]){
                    q.push(string(1,c));
                }
            }
            else{
                int len = q.size();
                while(len--){
                    string curr = q.front();q.pop();
                    for(auto& c : map[num]){
                        q.push(curr + c);
                    }
                }
            }
        }

        vector<string> result;
        while(!q.empty()){
            result.push_back(q.front());q.pop();
        }
        return result;
    }
};