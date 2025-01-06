/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
*/
//naive brute force:
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
        bool isdone=false;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target){
                    indices.push_back(i);
                    indices.push_back(j);
                    isdone = true;
                    break;
                }

                
            }
            if(isdone==true){
                    break;
                }
        }
        
        return indices;
    }
};
//hashmaps
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> indices;
         unordered_map<int,int> complement;
        for(int i=0;i<nums.size();i++){
            complement[nums[i]] = i;
        }
        for(int i=0;i<nums.size();i++){
            int value = target - nums[i];
            if(i==complement[value]){
                continue;
            }
            if(complement[value]){
                indices.push_back(i);
                indices.push_back(complement[value]);
                break;
            }
        }
        return indices;
    }
};
