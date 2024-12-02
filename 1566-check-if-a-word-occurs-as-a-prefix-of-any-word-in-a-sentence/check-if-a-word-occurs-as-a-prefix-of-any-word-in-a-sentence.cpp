class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        string word = "";
     vector<string> words;
     
        for(int i = 0; i<sentence.size(); i++){
            if(sentence[i] == ' '){
                words.push_back(word);
                // cout<<word<<endl;
                word = "";
            }
            if(sentence[i] != ' '){
                word = word + sentence[i];
            }
            if(sentence.size()-1 == i ){
                 words.push_back(word);
                // cout<<word<<',';
                 
            }
        }
        
        int resIdx = -1;
        int idx = 0;
        for(auto word: words){
            idx++;
            if(word[0] == searchWord[0]){
                string newWord = "";
                for(int i= 0; i<searchWord.size(); i++){
                    newWord += word[i];
                }
                if(newWord == searchWord){
                    resIdx = idx;
                    // cout<<resIdx;
                    return resIdx;
                }
                
            }
        }
        return resIdx;
    }
};