class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();

        // abc
        auto solve1 = [&]() {
            int a = 0, b = 0, c = 0;
            map<pair<int,int>,int> map;

            map[{0, 0}] = -1;
            int maxlen = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == 'a')
                    a++;
                if (s[i] == 'b')
                    b++;
                if (s[i] == 'c')
                    c++;

                int ab = a - b;
                int ac = a - c;

                if (map.count({ab, ac})) {
                    maxlen = max(maxlen, i - map[{ab, ac}]);
                } else {
                    map[{ab, ac}] = i;
                }
            }
            return maxlen;
        };

        // a
        auto solve2 = [&]() {
            int a = 0;
            int maxlen = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == 'a'){
                    a++;
                }
                else{
                    a = 0;
                }

                maxlen = max(maxlen,a);
            }
            return maxlen;
        };
        
        // b
        auto solve3 = [&]() {
            int b = 0;
            int maxlen = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == 'b'){
                    b++;
                }
                else{
                    b = 0;
                }

                maxlen = max(maxlen,b);
            }
            return maxlen;
        };

        // c
        auto solve4 = [&]() {
            int c = 0;
            int maxlen = 0;

            for (int i = 0; i < n; i++) {
                if (s[i] == 'c'){
                    c++;
                }
                else{
                    c = 0;
                }

                maxlen = max(maxlen,c);
            }
            return maxlen;
        };

        // ab
        auto solve5 = [&]() {
            int maxlen = 0;

            unordered_map<int,int> map;
            map[0] = -1;
            int sum = 0;

            for(int i = 0;i < n;i++){
                if(s[i] == 'a'){
                    sum ++;
                }
                else if(s[i] == 'b'){
                    sum --;
                }
                else{
                    map.clear();
                    
                    map[0] = i;
                    sum = 0;
                    continue;
                }

                if(map.count(sum)){
                    maxlen = max(maxlen,i - map[sum]);
                }
                else{
                    map[sum] = i;
                }
            }
            return maxlen;
        };

        // bc
        auto solve6 = [&]() {
            int maxlen = 0;

            unordered_map<int,int> map;
            map[0] = -1;
            int sum = 0;

            for(int i = 0;i < n;i++){
                if(s[i] == 'c'){
                    sum ++;
                }
                else if(s[i] == 'b'){
                    sum --;
                }
                else{
                    map.clear();

                    map[0] = i;
                    sum = 0;
                    continue;
                }

                if(map.count(sum)){
                    maxlen = max(maxlen,i - map[sum]);
                }
                else{
                    map[sum] = i;
                }
            }
            return maxlen;
        };

        // ac
        auto solve7 = [&]() {
            int maxlen = 0;

            unordered_map<int,int> map;
            map[0] = -1;
            int sum = 0;

            for(int i = 0;i < n;i++){
                if(s[i] == 'a'){
                    sum ++;
                }
                else if(s[i] == 'c'){
                    sum --;
                }
                else{
                    map.clear();

                    map[0] = i;
                    sum = 0;
                    continue;
                }

                if(map.count(sum)){
                    maxlen = max(maxlen,i - map[sum]);
                }
                else{
                    map[sum] = i;
                }
            }
            return maxlen;
        };

        return max({solve1(),solve2(),solve3(),solve4(),solve5(),solve6(),solve7()});
    }
};