class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        bool even = 0;
        even = (nums[0]%2 == 0)?1:0;
        if(even) {
            for(int i = 0; i<nums.size(); i++) {
                if((i%2==0 && nums[i]%2!=0) || (i%2!=0 && nums[i]%2==0)) return false;
            }
        }
        else {
            for(int i = 0; i<nums.size(); i++) {
                if((i%2==0 && nums[i]%2==0) || (i%2!=0 && nums[i]%2!=0)) return false;
            }
        }
        return true;
    }
};