class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
        for(auto it:wordList){
            s.insert(it);
        }
        if(!s.count(endWord))return 0;
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        while(!q.empty()){
            auto [word,count] = q.front();
            q.pop();
            if(word == endWord)return count;
            for(int i=0;i<word.size();i++){
                string oldWord = word;
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    if(ch == word[i])continue;
                    word[i] = ch;
                    if(!s.count(word) || visited.count(word))continue;
                    visited.insert(word);
                    q.push({word,count+1});
                }
                word = oldWord;
            }
        }
        return 0;
    }
};
