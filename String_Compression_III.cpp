class Solution {
public:
    string compressedString(string word) {
        char letter = '\0';
        int counter = 0;
        string comp = "";
        for(int i=0;i<word.size();i++){
            letter = word[i];
            if(word[i] == word[i+1]){
                counter++;
                
            }
            else {
               string counts = to_string(counter+1);
               comp+=counts;
               comp+= letter;
               counter = 0;
               
            }
            if(counter == 8){
               string counts = to_string(counter+1);
               comp+=counts;
               comp+= letter;
               counter = 0;
               
               i++;
            }
            

        }
        return comp;
    }
};
