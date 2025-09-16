class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        stack<int> s;
        for(int i = 0;i < nums.size();i++){
            if (!s.empty() && __gcd(s.top(),nums[i]) > 1){
                int lcm = s.top() * (nums[i] / __gcd(s.top(),nums[i]));
                s.pop();
                while(!s.empty() && __gcd(s.top(),lcm) > 1){
                    lcm = s.top() * (lcm / __gcd(s.top(),lcm));
                    s.pop();
                }
                s.push(lcm);
            }
            else{
                s.push(nums[i]);
            }
        }
        vector<int> result;
        while(!s.empty()){
            result.push_back(s.top());s.pop();
        }
        reverse(result.begin(),result.end());
        return result;
    }
};