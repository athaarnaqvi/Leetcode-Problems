class Solution {
public:
    bool isCircularSentence(string sentence) {
       int l = sentence.length();
       if(sentence[0]!=sentence[l-1]){
            return false;
       }
       for(int i=0;i<l;i++){
            if(sentence[i+1]==' '){
                if(sentence[i] != sentence[i+2]){
                    return false;
                }
            }
       }
       return true; 
    }
};
