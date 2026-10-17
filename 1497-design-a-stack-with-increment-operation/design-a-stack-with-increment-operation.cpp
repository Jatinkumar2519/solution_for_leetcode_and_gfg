class CustomStack {
public:
    int limit;
    stack<int> s;
    vector<int> temp, result;
    CustomStack(int limit): limit(limit){ temp.resize(limit); }

    void push(int x) {
        if (s.size() < limit) {
            s.push(x);
        }
    }

    int pop() {
        int len = s.size();
        if (len == 0) {
            return -1;
        }

        int res = s.top() + temp[len - 1];

        if (len == 1) {
            temp[len - 1] = 0;
        } else {
            temp[len - 2] += temp[len - 1];
            temp[len - 1] = 0;
        }

        s.pop();

        return res;
    }

    void increment(int k, int val) {
        if (s.empty())
            return;

        k = min(k, (int)s.size());
        temp[k - 1] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */