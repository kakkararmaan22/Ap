class ProductOfNumbers {
public:
    ProductOfNumbers() {
        
    }
    vector<int> nums;
    int curr=0;
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int n = nums.size();
        int ans = 1;
        if(k<=n){
            for(int i = n-k; i<n; i++){
                ans = ans*nums[i];
            }
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */