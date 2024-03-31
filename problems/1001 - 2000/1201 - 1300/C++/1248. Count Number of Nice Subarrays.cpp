class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int sz = nums.size();

        int l = 0, r = 0, tmp = 0, res = 0;
        queue<int> q;
        
        while(r != sz) {
            if(nums[r] & 1) {
                q.push(r); ++tmp;
            }
            
            if(tmp == k) res += max(0, q.front() - l + 1);
            else if(tmp > k) {
                --tmp;
                l = q.front() + 1;
                q.pop();
                res += max(0, q.front() - l + 1);
            }
            ++r;
        }
        
        return res;    
    }
};
