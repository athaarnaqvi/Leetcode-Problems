//minimum number of changes to make binary strings beautiful
class Solution {
public:
    int minChanges(string s) {
        int count0 = 0;
        int count1 = 0;
        int itr=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                count0++;
            }else{
                count1++;
            }
        }
        if(count0 == s.size() || count1 == s.size()){
            return 0;
        }
        
        for(int i=0;i<s.size();i+=2){
            if(s[i]!=s[i+1]){
                itr++;
            }
        }
        return itr;
    }
};
