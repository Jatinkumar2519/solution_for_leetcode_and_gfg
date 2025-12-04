class Solution {
public:
    int countCollisions(string directions) {
        int result = 0;
        stack<pair<char,int>> s;
        for(auto&ch : directions){
            if(!s.empty()){
                char d = s.top().first;
                if(d == ch){
                    s.top().second++;
                }
                else if(d == 'S' && ch == 'L'){
                    int c_r = 1;
                    s.top().second++;
                    result += c_r;
                }
                else if(d == 'R' && ch == 'L'){
                    int r_l = 2;
                    int r_s = s.top().second - 1;
                    s.pop();
                    s.push({'S',r_l + r_s});
                    result += r_l + r_s;
                }
                else if(d == 'R' && ch == 'S'){
                    int r_s = s.top().second;
                    s.pop();
                    s.push({'S',r_s});
                    result += r_s;
                }
                else{
                    s.push({ch,1});
                }
            }
            else{
                s.push({ch,1});
            }
        }
        return result;
    }
};
// 2 + 