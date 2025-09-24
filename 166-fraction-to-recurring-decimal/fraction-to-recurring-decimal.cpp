class Solution {
public:
    string fractionToDecimal(int n, int d) {
        if(n == 0) return "0"; 
        int neg_n = false,neg_d = false;
        if(n < 0){
            neg_n = true;
        }
        if(d < 0){
            neg_d = true;
        }
        string result;
        if(neg_n ^ neg_d){
            result.push_back('-');
        }
        long long num1 = n;num1 = abs(num1);
        long long num2 = d;num2 = abs(num2);
        result += to_string(num1/num2);
        num1 = num1 % num2;
        if(num1 == 0) return result;
        result.push_back('.');
        unordered_map<long long,int> visit;
        while(num1 > 0){
            visit[num1] = result.size();
            num1 *= 10;
            result += to_string(num1/num2);
            num1 = num1 % num2;
            if(visit.find(num1) != visit.end()){
                result.insert(visit[num1],"(");
                result.push_back(')');
                return result;
            }
        }
        return result;
    }
};