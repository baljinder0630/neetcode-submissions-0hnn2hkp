class Node{
public:
    int val;
    int key;
    Node* next;
    Node* prev;
    Node(int key,int val){
        this->val=val;
        this->key=key;
        next = NULL;
        prev = NULL;
    }    
};

class DoublyLL{
public:
    Node* head, *tail;
    DoublyLL(){
        head=NULL;
        tail=NULL;
    }
    Node* insert(int k,int v){
        Node* node = new Node(k,v);
        if(tail == NULL){
            head = tail = node;
        }
        else{
            tail->next=node;
            node->prev=tail;
            tail=node;
        }
        return node;
    }
    void remove(Node* node){
        if(node == head && node == tail){
            head = NULL;
            tail = NULL;
        }
        else if(node == head){
            head = head->next;
            head->prev = NULL;
        }
        else if(node == tail){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            node->next->prev=node->prev;
            node->prev->next=node->next;
            node->next=NULL;
            node->prev=NULL;
        }
    }
};

class LRUCache {
public:
    unordered_map<int,Node*> mapping;
    DoublyLL root;
    int availableSize;
    LRUCache(int capacity) {
        availableSize = capacity;
    }
    
    int get(int key) {
        if(mapping.find(key) != mapping.end()){
            Node* node = mapping[key];
            root.remove(node);
            node = root.insert(key,node->val);
            mapping[key] = node;
            return node->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mapping.find(key) != mapping.end()){
            Node* node = mapping[key];
            root.remove(node);
            node = root.insert(key,value);
            mapping[key] = node;
            return;
        }
        if(availableSize == 0){
            mapping.erase(root.head->key);
            root.remove(root.head);
            availableSize++;
        }
        Node* node = root.insert(key,value);
        mapping[key]=node;
        availableSize--;
    }
};
