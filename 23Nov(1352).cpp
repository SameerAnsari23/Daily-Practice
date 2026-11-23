class ProductOfNumbers {
    private:
    vector<int> p = {1};
public:
    ProductOfNumbers() {

    }

    void add(int num) {
        if (num == 0) {
            p = {1};
        }
        else {
            p.push_back(p.back()*num);
        }
    }
    
    int getProduct(int k) {
        int n = p.size();
        if (k >= n) return 0;
        return p[n-1] / p[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
