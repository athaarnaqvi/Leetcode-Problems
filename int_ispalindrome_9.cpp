
class Solution {
public:
    bool isPalindrome(int x) {
      string x_s = to_string(x);
      reverse(x_s.begin(), x_s.end());
      return (stol(x_s) == x);  
    }
};

//not using strings
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int revertedNumber = 0;
        while (x > revertedNumber) {
            revertedNumber = revertedNumber * 10 + x % 10;
            x /= 10;
        }
        return x == revertedNumber || x == revertedNumber / 10;
    }
};
