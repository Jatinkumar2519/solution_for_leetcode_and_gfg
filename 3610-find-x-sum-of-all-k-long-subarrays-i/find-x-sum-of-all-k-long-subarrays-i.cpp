class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> result;
        int n = nums.size();
        for(int i = 0;i <= n - k;i++){
            unordered_map<int,int> map;
            for(int j = i;j < k + i;j++){
                map[nums[j]]++;
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
            for(auto& [num,freq] : map){
                pq.push({freq,num});
                if(pq.size() > x) pq.pop();
            }
            int sum = 0;
            while(!pq.empty()){
                sum += pq.top().second * pq.top().first;pq.pop();
            }
            result.push_back(sum);
        }
        return result;
    }
};