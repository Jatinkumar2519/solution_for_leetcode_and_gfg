/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();

        function<Node*(int,int,int,int)> solve = [&](int x1,int y1,int x2,int y2)->Node*{

            int one = 0;
            int zero = 0;
            for(int i = x1;i <= x2;i++){
                for(int j = y1;j <= y2;j++){
                    one += grid[i][j];
                    zero += (grid[i][j] == 0);
                }
            }

            Node* newNode = new Node();

            newNode->val = (zero == 0);
            newNode->isLeaf = (one == 0 || zero == 0);

            if(newNode->isLeaf) return newNode;

            int l = x2 - x1 + 1;
            int b = y2 - y1 + 1;

            int mid_l = l/2;
            int mid_b = b/2;

            newNode->topLeft = solve(x1,y1,x1 + mid_l - 1,y1 + mid_b - 1);
            newNode->topRight = solve(x1,y1 + mid_b,x1 + mid_l - 1,y2);
            newNode->bottomLeft = solve(x1 + mid_l,y1,x2,y1 + mid_b - 1);
            newNode->bottomRight = solve(x1 + mid_l,y1 + mid_b,x2,y2);

            return newNode;
        };

        return solve(0,0,n - 1,n - 1);
    }
};