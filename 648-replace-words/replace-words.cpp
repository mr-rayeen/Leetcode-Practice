#include <regex>
class Solution {
public:

    string findRoot(string &word, unordered_set<string> &st){
        //  Yaha hum check kar rhe hai ki dictionay ka word exist kar rh hai sentence ke word me ya nahi.
        //  Hum ek ek letter ko check kar rhe hai fir uske baad usko mila kar next letter se sub string banakar check kar rhe hai 
        for(int l = 1; l<word.length(); l++ ){
            string root = word.substr(0,l);
            //  root me humari substring ayegi fir usko hashset st me check karenge agar exist karega toh root ko return kar denge warna as it is word ko return kar denge.
            if(st.count(root)){
                return root;
            }
        }
        return word;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        
        // for(auto word: dictionary){
        //     regex r(word+"[a-z]+");
        //     sentence = regex_replace(sentence, r, word);
        // }
        // return sentence;
        //  Hashset ka use kiya qki humko constant time me search karna hai
        //  jisse time kam lage
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        // stringstream use kiya hai jisse hum sentences ko words me break kar sakte hai asani se.
        stringstream ss(sentence);
        //  Is word me hum sentence se todhe hue words ko store karenge
        string word;
        //  Isko modified string ko store kar rhe hai har ek iteration ke baad
        string result;
        //  yaha ss cin ki tarah kaam kar raha hai or space se hum break kar rhe hai or word me ek ek word ko store kar rhe hai
        while(getline(ss, word, ' ')){
            //  findRoot humko sentence ka word match karke lakar dega agar dictionary se match hoga toh humko root return karega jo dictionary me hoga warna sentence ka as it is word lakar dega.
            result += findRoot(word, st) + ' ';
        }
        //  Yaha pop is liye kar rhe hai qki ek extra space ajaega jab b last word add hoga.
        result.pop_back();
        return result;
    }
};