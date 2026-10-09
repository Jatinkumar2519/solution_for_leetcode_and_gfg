class Solution {
public:
    int minInsertions(string str) {

        // stack<pair<char,bool>> s;
        // for(auto& ch : str){
        //     if(!s.empty() && s.top().first == '(' && ch == ')'){
        //         if(s.top().second) s.pop();
        //         else s.top().second = true;
        //     }
        //     else{
        //         s.push({ch,false});
        //     }
        // }

        // int count = 0;
        // while(!s.empty()){

        //     if(s.top().first == '('){
        //         if(s.top().second) count += 1;
        //         else count += 2;

        //         s.pop();
        //     }
        //     else{
        //         char top = s.top().first;s.pop();
        //         if(s.empty()) count += 2;
        //         else{
        //             if(s.top().first == ')'){
        //                 s.pop();
        //                 count += 1;
        //             }
        //             else{
        //                 count += 2;
        //             }
        //         }
        //     }
        // }

        // return count;/

        string curr;
        int count = 0;
        int n = str.length();

        for(int i = 0;i < n;){
            if(str[i] == '('){
                curr += '(';i++;
            }
            else{
                if(i + 1 < n && str[i + 1] == ')'){
                    curr += ')';i += 2;
                }
                else{
                    curr += ')';
                    count += 1;i++;
                }
            }
        }

        stack<char> s;
        for(auto& ch : curr){
            if(!s.empty() && s.top() == '(' && ch == ')') s.pop();
            else s.push(ch);
        }

        while(!s.empty()){
            if(s.top() == '(') count += 2;
            else count += 1;

            s.pop();
        }

        return count;
    }
};