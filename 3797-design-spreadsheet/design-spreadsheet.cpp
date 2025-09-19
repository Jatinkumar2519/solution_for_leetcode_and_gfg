class Spreadsheet {
public:
    vector<vector<int>> grid;
    Spreadsheet(int rows) {
        grid.resize(26,vector<int>(rows + 1,0));
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        int num = 0;
        for(int i = 1;i < cell.size();i++){
            num = num * 10 + (cell[i] - '0');
        }
        grid[col - 'A'][num] = value; 
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        int num = 0;
        for(int i = 1;i < cell.size();i++){
            num = num * 10 + (cell[i] - '0');
        }
        grid[col - 'A'][num] = 0;
    }
    
    int getValue(string formula) {
        bool flag = true;
        string left,right;
        for(int i = 1;i < formula.size();i++){
            if(formula[i] == '+'){
                flag = false;
            }
            else if(flag){
                left.push_back(formula[i]);
            }
            else{
                right.push_back(formula[i]);
            }
        }
        int sum = 0;
        char col1 = left[0];
        int num1 = 0;
        if(isalpha(col1)){
            for(int i = 1;i < left.size();i++){
                num1 = num1 * 10 + (left[i] - '0');
            }
            sum += grid[col1 - 'A'][num1];
        }
        else{
            for(int i = 0;i < left.size();i++){
                num1 = num1 * 10 + (left[i] - '0');
            }
            sum += num1;
        }
        char col2 = right[0];
        int num2 = 0;
        if(isalpha(col2)){
            for(int i = 1;i < right.size();i++){
                num2 = num2 * 10 + (right[i] - '0');
            }
            sum += grid[col2 - 'A'][num2];
        }
        else{
            for(int i = 0;i < right.size();i++){
                num2 = num2 * 10 + (right[i] - '0');
            }
            sum += num2;
        }
        return sum;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */