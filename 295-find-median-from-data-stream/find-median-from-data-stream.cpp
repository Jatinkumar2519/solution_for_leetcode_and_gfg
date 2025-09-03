class MedianFinder {
public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        right.push(num);
    }
    
    double findMedian() {
        while(!right.empty() && !left.empty() && left.top() > right.top()){
            left.push(right.top());right.pop();
        }
        while(left.size() > right.size()){
            right.push(left.top());left.pop();
        }
        while(left.size() < right.size()){
            left.push(right.top());right.pop();
        }
        if((left.size() + right.size()) % 2 == 1){
            return left.top();
        }
        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */