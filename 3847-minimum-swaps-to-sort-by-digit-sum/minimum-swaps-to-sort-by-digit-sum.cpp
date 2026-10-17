class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp = nums;

        unordered_map<int,int> map;
        for(int i = 0;i < n;i++) map[nums[i]] = i;

        auto getSum = [&](int num)->int{

            int sum = 0;
            while(num > 0){
                sum += num % 10;
                num /= 10;
            }

            return sum;
        };

        sort(temp.begin(), temp.end(), [&](int num1 ,int num2){

            int sum1  = getSum(num1);
            int sum2  = getSum(num2);

            if(sum1 == sum2) return num1 < num2;
            return sum1 < sum2;
        });

        vector<int> next(n);
        for(int i = 0;i < n;i++){

            next[i] = map[temp[i]];
        }

        int count = 0;
        vector<bool> visited(n);

        for(int node = 0;node < n;node++){
            if(visited[node]) continue;

            int len = 0;
            int u = node;
            unordered_map<int,int> dist;

            for(u = node;!visited[u];u = next[u]){

                visited[u] = true;
                dist[u] = len;len++;
            }

            count += len - dist[u] - 1;
        }

        return count;
    }
};