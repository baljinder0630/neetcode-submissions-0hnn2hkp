class TrieNode{
    public:
    unordered_map<char,TrieNode*> child;
    bool isEnd;
    TrieNode(){
        isEnd=false;
    }
};
class PrefixTree {
    void insertHelper(string word,TrieNode* head){
        if(word == ""){
            head->isEnd = true;
            return;
        }
        char val = word[0];
        if(!head->child.count(val)){
            TrieNode* temp = new TrieNode();
            head->child[val] = temp;
        }
        insertHelper(word.substr(1),head->child[val]);
    }

    bool searchHelper(string word,TrieNode* head){
        if(word==""){
            return head->isEnd;
        }
        char val = word[0];
        if(!head->child.count(val))return false;
        return searchHelper(word.substr(1),head->child[val]);
    }

    bool startsWithHelper(string word,TrieNode* head){
        if(word==""){
            return true;
        }
        char val = word[0];
        if(!head->child.count(val))return false;
        return startsWithHelper(word.substr(1),head->child[val]);
    }
public:
    TrieNode* root;
    PrefixTree() {
        root=new TrieNode();
    }
    
    void insert(string word) {
        insertHelper(word,root);
    }
    
    bool search(string word) {
        return searchHelper(word,root);
    }
    
    bool startsWith(string prefix) {
        return startsWithHelper(prefix,root);
    }
};
