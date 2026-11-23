class ProductOfNumbers {
public:
    vector<int> preProduct;
    ProductOfNumbers() {
        preProduct.push_back(1);
    }
    
    void add(int num) {
        if(!num){
            preProduct.clear();
            preProduct.push_back(1);
        }
        else preProduct.push_back(preProduct.back() * num);
    }
    
    int getProduct(int k) {
        int n = preProduct.size();
        if(k >= n) return 0;
        return preProduct[n - 1] / preProduct[n - 1 - k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */