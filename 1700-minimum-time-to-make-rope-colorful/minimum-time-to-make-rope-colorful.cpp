class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int sum = 0;
        priority_queue<int> pq;
        char prev = colors[0];
        pq.push(neededTime[0]);
        for(int i = 1;i < colors.length();i++){
            if(prev == colors[i]){
                pq.push(neededTime[i]);
            }
            else{
                pq.pop();
                while(!pq.empty()){
                    sum += pq.top();pq.pop();
                }
                prev = colors[i];
                pq.push(neededTime[i]);
            }
        }
        pq.pop();
        while(!pq.empty()){
            sum += pq.top();pq.pop();
        }
        return sum;
    }
};