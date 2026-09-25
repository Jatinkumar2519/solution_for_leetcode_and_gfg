class Solution {
public:
    vector<string> braceExpansionII(string expression) {

        stack<set<string>> values;
        stack<char> ops;

        auto apply = [&]() {

            char op = ops.top();
            ops.pop();

            auto right = values.top();
            values.pop();

            auto left = values.top();
            values.pop();

            set<string> result;

            if (op == '+') {
                result = left;
                result.insert(right.begin(), right.end());
            }
            else {
                for (auto &a : left) {
                    for (auto &b : right) {
                        result.insert(a + b);
                    }
                }
            }

            values.push(result);
        };

        bool needConcat = false;

        for (int i = 0; i < expression.size(); i++) {

            char c = expression[i];

            // -------------------------
            // Opening brace
            // -------------------------
            if (c == '{') {

                if (needConcat)
                    ops.push('*');

                ops.push('{');

                needConcat = false;
            }

            // -------------------------
            // Comma
            // -------------------------
            else if (c == ',') {

                while (!ops.empty() && ops.top() != '{')
                    apply();

                ops.push('+');

                needConcat = false;
            }

            // -------------------------
            // Closing brace
            // -------------------------
            else if (c == '}') {

                while (!ops.empty() && ops.top() != '{')
                    apply();

                ops.pop(); // remove '{'

                needConcat = true;
            }

            // -------------------------
            // Word
            // -------------------------
            else {

                if (needConcat)
                    ops.push('*');

                string word;

                while (i < expression.size() &&
                       isalpha(expression[i])) {

                    word += expression[i];
                    i++;
                }

                i--;

                values.push({word});

                needConcat = true;
            }
        }

        while (!ops.empty())
            apply();

        return vector<string>(
            values.top().begin(),
            values.top().end()
        );
    }
};