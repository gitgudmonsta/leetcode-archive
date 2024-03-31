class Solution {
    using i64 = long long;

public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int sz = nums.size();
        i64 ans = 0;
        
        int l = 0, r = 0, pmin = -1, pmax = -1;
        
        while(r != sz) {
            if(nums[r] < minK || nums[r] > maxK) {
                l = r + 1;
                pmin = pmax = -1; 
            }
            else {
                pmin = (nums[r] == minK)? r: pmin;
                pmax = (nums[r] == maxK)? r: pmax;
                ans += max(0, min(pmin, pmax) - l + 1); 
            }
            ++r;
        }
        
        return ans;
    }
};
