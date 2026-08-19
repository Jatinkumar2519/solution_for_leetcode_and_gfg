class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int,vector<bool>> map;

        for(auto& seat : reservedSeats){
            if(!map.count(seat[0])){
                vector<bool> arr(11,false);
                map[seat[0]] = arr;
            }

            map[seat[0]][seat[1]] = true;
        }

        int count = 0;
        for(auto& [_,arr] : map){
            
            if(!(arr[2] || arr[3] || arr[4] || arr[5] || 
                arr[6] || arr[7] || arr[8] || arr[9])){
                count += 2;
            }
            else if(!(arr[2] || arr[3] || arr[4] || arr[5])){
                count++;
            }
            else if(!(arr[6] || arr[7] || arr[8] || arr[9])){
                count++;
            }
            else if(!(arr[4] || arr[5] || arr[6] || arr[7])){
                count++;
            }
        }

        int empty = n - map.size();
        count += empty * 2;

        return count;
    }
};