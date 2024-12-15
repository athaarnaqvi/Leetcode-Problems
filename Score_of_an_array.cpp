/*
You are given an array nums consisting of positive integers.

Starting with score = 0, apply the following algorithm:

Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
Add the value of the chosen integer to score.
Mark the chosen element and its two adjacent elements if they exist.
Repeat until all the array elements are marked.
Return the score you get after applying the above algorithm.

 
*/
//this is the naive method

class Solution {
public:
    long long findScore(vector<int>& nums) {
        int count = 0;
        int min = INT_MAX;
        int min_idx = -1;
        vector<int> scores;

        while (count < nums.size()) {
            
            min = INT_MAX;
            min_idx = -1;

           
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != -1 && nums[i] < min) {
                    min = nums[i];
                    min_idx = i;
                }
            }

           
            if (min_idx == -1) {
                break;
            }

            
            scores.push_back(nums[min_idx]);

            
            nums[min_idx] = -1;
            if (min_idx > 0) {
                nums[min_idx - 1] = -1;
            }
            if (min_idx < nums.size() - 1) {
                nums[min_idx + 1] = -1;
            }

            count++;
        }

        
        long long score = 0;
        for (int i = 0; i < scores.size(); i++) {
            score += scores[i];
        }
        return score;
    }
};


// and this is the solution in O(n)
// i am using a vector pair to store the elements and their initial indices. This vector is sorted and being traversed.. so for every index it changes nums 
class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        vector<std::pair<int, int>> sorted;
        for (int i = 0; i < nums.size(); ++i) {
            sorted.emplace_back(nums[i], i); // Store the value and its index
        }
        sort(sorted.begin(), sorted.end());

        for (const auto& p : sorted) {
           
            if(nums[p.second] == -1){
                continue;
            }
            
            nums[p.second] = -1;
            
            score += p.first;
            if (p.second > 0) {
                nums[p.second - 1] = -1; 
            }
            if (p.second < nums.size() - 1) {
                nums[p.second + 1] = -1;
            }
        }


        return score;
    }
};

