/*
An array is considered special if every pair of its adjacent elements contains two numbers with different parity.

You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
subarray
 nums[fromi..toi] is special or not.

Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.
*/
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       int n = nums.size();
        vector<int> same_parity(n - 1, 0); 
        
        
        for (int i = 0; i < n - 1; i++) {
            if ((nums[i] % 2 == nums[i + 1] % 2)) {
                same_parity[i] = 1;
            }
        }
        
        
        vector<int> prefix_sum(n, 0);
        for (int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + same_parity[i - 1];
        }
       
        
        vector<bool> is_special;
        for (int i=0;i<queries.size();i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            
            if (prefix_sum[r] - prefix_sum[l] == 0) {
                is_special.push_back(true); 
            } else {
                is_special.push_back(false); 
            }
        }
        
        return is_special;
    }
};
