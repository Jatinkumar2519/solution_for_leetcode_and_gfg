class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows == 1){
            return {{1}};
        }
        if(numRows == 2){
            return {{1},{1,1}};
        }
        res.push_back({1});
        res.push_back({1,1});
        vector<int> arr = {{1,1}};
        for(int i = 2 ; i < numRows;i++){
            vector<int> list;
            list.push_back(1);
            for(int j = 0; j < arr.size() - 1;j++){
                list.push_back(arr[j] + arr[j + 1]);
            }
            list.push_back(1);
            arr = list;
            res.push_back(list);
        }
        return res;
    }
};