class Solution {
public:
    string makeFancyString(string s) {
        int l=s.size();
        for (int i=0;i<l-2;i++){
            if(s[i]!=s[i+1]){
                continue;
            }
            if(s[i]!= s[i+2]){
                continue;
            }
            s[i]='-';
        } 
        s.erase(remove_if(s.begin(), s.end(), [](char c) {return c == '-';}), s.end());
         
       return s;
    }
};
