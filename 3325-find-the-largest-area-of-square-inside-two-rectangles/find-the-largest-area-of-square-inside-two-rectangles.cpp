class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {

        int n = bottomLeft.size();
        auto getArea = [&](vector<int>& a1, vector<int>& b1, vector<int>& a2,
                           vector<int>& b2) {
            int a10 = a1[0];
            int a11 = a1[1];
            int b10 = b1[0];
            int b11 = b1[1];

            int a20 = a2[0];
            int a21 = a2[1];
            int b20 = b2[0];
            int b21 = b2[1];

            long long maxv = 0;
            if(a10 <= a20 && a20 <= b10 || a10 <= b20 && b20 <= b10 || a20 <= a10 && b10 <= b20){
                if(a11 <= a21 && a21 <= b11 || a11 <= b21 && b21 <= b11){
                    int c10 = max(a10,a20);
                    int c11 = max(a21,a11);
                    int d10 = min(b10,b20);
                    int d11 = min(b21,b11);

                    long long side = min(d10 - c10,d11 - c11);
                    maxv = max(maxv,1LL * side * side);
                }
            }
            return maxv;
        };

        long long val = 0;
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                val = max(val,getArea(bottomLeft[i],topRight[i],
                bottomLeft[j],topRight[j]));
                val = max(val,getArea(bottomLeft[j],topRight[j],
                bottomLeft[i],topRight[i]));
            }
        }

        return val;
    }
};