class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxdia = 0;
        int maxarea = 0;
        for(auto arr : dimensions){
            int dia = arr[0] * arr[0] + arr[1] * arr[1];
            if(maxdia < dia)
            {
                maxdia = dia;
                maxarea = arr[0] * arr[1];
            }
            else if(maxdia == dia){
                maxarea = max(maxarea,arr[0] * arr[1]);
            }
        }
        return maxarea;
    }
};