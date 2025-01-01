/*
Given a string s of zeros and ones, return the maximum score after splitting the string into two non-empty substrings (i.e. left substring and right substring).

The score after splitting a string is the number of zeros in the left substring plus the number of ones in the right substring.

Example 1:

Input: s = "011101"
Output: 5 
Explanation: 
All possible ways of splitting s into two non-empty substrings are:
left = "0" and right = "11101", score = 1 + 4 = 5 
left = "01" and right = "1101", score = 1 + 3 = 4 
left = "011" and right = "101", score = 1 + 2 = 3 
left = "0111" and right = "01", score = 1 + 1 = 2 
left = "01110" and right = "1", score = 2 + 1 = 3
*/

class Solution {
public:
    int maxScore(string s) {
        vector<int> zeros;
        vector<int> ones;
        int counter = 0;
        for(int i=0;i<size(s);i++){
           
            if(s[i]=='0'){
                counter++;
                
            }
            zeros.push_back(counter);
            
        }
        
        
        counter = 0;
        for(int i=size(s)-1;i>=0;i--){
            
            if(s[i]=='1'){
                counter++;
                
            }
            ones.push_back(counter);
           
        }
        
        reverse(ones.begin(), ones.end());
       
        int result = 0;
       
        for (int i = 0; i < size(s) - 1; i++) {
            int score = zeros[i] + ones[i + 1];
            result = max(result, score);
        }
        return result;
    }
};
