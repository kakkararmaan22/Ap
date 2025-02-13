class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue <long long, vector<long long>, greater<long long> > pq;
        for(int i =0; i<n; i++) {
            pq.push(nums[i]); 
        }
        int cnt = 0;
        while(pq.top()<k && pq.size()>1) {
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            cnt++;
        }
        return cnt;
    }
};