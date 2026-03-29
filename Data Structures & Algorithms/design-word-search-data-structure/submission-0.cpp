class Trie{
private: 
    struct TrieNode{
        TrieNode* child[26];
        char data;
        bool isEnd;
        TrieNode(char data){
            this->data = data;
            this->isEnd = false;
            for(int i=0;i<26;i++)
                child[i]=nullptr;
        }
    };
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode('#');
    }

    void insert(string data){
        TrieNode* node = root;
        for(auto it:data){
            int idx = it-'a';
            if(node->child[idx] == nullptr){
                node->child[idx] = new TrieNode(it);
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    bool searchNode(string data,TrieNode* node,int pos){
        if(pos == data.size())return node->isEnd;
        int idx = data[pos] - 'a';
        if(data[pos] == '.'){
            for(int i = 0; i < 26; i++){
                data[pos] = 'a' + i;
                if(searchNode( data, node, pos))return true;
            }
        }
        else if(node->child[idx] != nullptr){
            return searchNode(data,node->child[idx],pos+1);
        }
        return false;
    }
};
class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.searchNode(word,t.root,0);
    }
};
