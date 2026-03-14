class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        for(int j = 0;j < n;j++) {
            int len = q.size();
            for (int _ = 0; _ < len; _++) {
                string str = q.front();q.pop();
                if(str.length() == n){
                    if(--k == 0){
                        return str;
                    }
                }
                char ch = str.back();
                if(ch == 'a'){
                    q.push(str + 'b');
                    q.push(str + 'c');
                }
                else if(ch == 'b'){
                    q.push(str + 'a');
                    q.push(str + 'c');
                }
                else{
                    q.push(str + 'a');
                    q.push(str + 'b');
                }
            }
        }
        return "";
    }
};
