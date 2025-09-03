class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({nums1[0] + nums2[0],0,0});
        set<pair<int,int>> visit;
        while(k-- && !pq.empty()){
            auto temp = pq.top();pq.pop();
            int i = temp[1];
            int j = temp[2];
            res.push_back({nums1[i],nums2[j]});
            if(i + 1 < nums1.size() && !visit.count({i + 1,j})){
                pq.push({nums1[i + 1] + nums2[j],i + 1,j});
                visit.insert({i + 1,j});
            }
            if(j + 1 < nums2.size() && !visit.count({i,j + 1})){
                pq.push({nums1[i] + nums2[j + 1],i,j + 1});
                visit.insert({i,j + 1});
            }
        }
        return res;
    }
};