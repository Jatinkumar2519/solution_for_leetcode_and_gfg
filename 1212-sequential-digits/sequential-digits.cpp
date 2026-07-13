class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result; 
        queue<int> q;

        for(int i = 1;i < 10;i++) q.push(i);
        while(!q.empty()){
            int num = q.front();q.pop();

            if(low <= num && num <= high) result.push_back(num);
            if((num % 10) < 9 && (num * 10 + (num % 10 + 1)) <= high) q.push(num * 10 + (num % 10 + 1));
        }
        
        return result;
    }
};