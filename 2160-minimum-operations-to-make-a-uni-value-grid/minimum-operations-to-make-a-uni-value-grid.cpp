class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> arr;
        for(auto & i : grid){
            for(auto & j : i){
                arr.push_back(j);
            }
        }
        int result = 0,n = arr.size();
        int rem = arr[0] % x;
        for(int i : arr){
            if(i % x != rem){
                return -1;
            }
        }
        for(int & i : arr){
            i /= x;
        }
        sort(arr.begin(),arr.end());
        int median = arr[n/2];
        for(int i : arr){
            result += abs(i - median);
        }
        return result;
    }
};