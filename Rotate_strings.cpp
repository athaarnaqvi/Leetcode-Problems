class Solution {
public:
    bool rotateString(string s, string goal) {
        int l=s.size();
        for(int j=0;j<l;j++){
            char init = s[0];
            
            for(int i=0;i<l-1;i++){
                s[i] = s[i+1];
            } 
            s[l-1]=init;
            
            if(s == goal){
                    return true;
            }
        }
        return false;
    }
        
};
