class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> st;
        int index = 0;
        for (int num : nums) {
            if (st.find(num) == st.end()) {
                st.insert(num);
                nums[index++] = num;
            }
        }
        return index;
    }
};