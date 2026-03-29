class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node* root1 = head;
        Node* root2;
        while(root1 != NULL){
            Node* temp = new Node(root1->val);
            Node* next = root1->next;
            root1->next = temp;
            temp->next = next;
            root1=next;
        }
        root1=head;
        while(root1 != NULL){
            Node* random = root1->random;
            Node* next = root1->next;
            next->random = random ? random->next : NULL;
            root1=root1->next->next;
        }
        root1=head;
        root2=head->next;
        while(root1 != NULL){
            Node* next = root1->next;
            root1->next=next->next;
            root1=root1->next;
            next->next=root1?root1->next:NULL;
        }
        return root2;
    }
};
