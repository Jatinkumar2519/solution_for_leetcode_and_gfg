class ProductOfNumbers {
public:
    vector<int> prefix;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        if(num == 0){
            prefix.clear();
        }
        else{
            if(prefix.empty()){
                prefix.push_back(num);
            }
            else{
                prefix.push_back(prefix.back() * num);
            }
        }
    }
    
    int getProduct(int k) {
        if(prefix.size() < k) return 0;

        int l = prefix.size() - k;
        return prefix.back()/((l > 0) ? prefix[l - 1] : 1);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */