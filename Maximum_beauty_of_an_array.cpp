/*
You are given a 0-indexed array nums and a non-negative integer k.

In one operation, you can do the following:

Choose an index i that hasn't been chosen before from the range [0, nums.length - 1].
Replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k].
The beauty of the array is the length of the longest subsequence consisting of equal elements.

Return the maximum possible beauty of the array nums after applying the operation any number of times.

Note that you can apply the operation to each index only once.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the order of the remaining elements.
Hint: active ranges calculated by (lowest range, +1),(highest range+1, -1)
and then sorting apparently this technique is called Sweep Line*/

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        int order = 0;
        vector<pair<int, int>> ranges;

        for(int i=0;i<nums.size();i++){
            ranges.push_back(make_pair(nums[i] - k, 1));
        }
        for(int i=0;i<nums.size();i++){
            ranges.push_back(make_pair(nums[i] + k+1, -1));
        }
    sort(ranges.begin(), ranges.end());
       int temp = 0;
       for(int i=0;i<ranges.size();i++){
        temp += ranges[i].second;
        
        if(order<temp){  
            order = temp;   
        }
       }

        
        return order;
    }
};
