class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        function<double(int ,int)> gain = [&](int a,int b) -> double{
            return (double) (a + 1)/(b + 1) - (double)a/b;
        };
        priority_queue<pair<double,int>>pq;
        for(int i = 0;i < n;i++){
            pq.push({gain(classes[i][0],classes[i][1]),i});
        }
        for(int i = 0;i < extraStudents;i++){
            auto [_,indx] = pq.top();pq.pop();
            classes[indx][0]++;
            classes[indx][1]++;
            pq.push({gain(classes[indx][0],classes[indx][1]),indx});
        }
        double res = 0.0;
        for(int i = 0;i < n;i++){
            res += (double)classes[i][0]/classes[i][1];
        }
        return res / n;
    }
};