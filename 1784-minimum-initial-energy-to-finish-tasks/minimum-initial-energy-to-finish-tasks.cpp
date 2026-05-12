class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[](vector<int>& a,vector<int>& b){
            return (a[1] - a[0]) > (b[1] - b[0]);
        });

        int n = tasks.size();

        auto feasible = [&](int energy){
            for(int i = 0;i < n;i++){
                if(energy < tasks[i][1]) return false;
                energy -= tasks[i][0];
            }
            return true;
        };
        
        int left = 0;
        int right = 0;
        for(auto& task : tasks){
            left = max(left,max(task[0],task[1]));
            right += max(task[0],task[1]);
        }

        int res = 0;

        while(left <= right){
            int mid = (left + right)/2;

            if(feasible(mid)){
                res = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }

        return res;
    }
};