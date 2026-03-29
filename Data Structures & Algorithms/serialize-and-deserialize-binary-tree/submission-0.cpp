/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(root==NULL)return "#";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(ans != "")ans+=",";
            if(front){
                ans += to_string(front->val);
            }
            else{
                ans += "#";
                continue;
            }
            q.push(front->left);
            q.push(front->right);
        }
        cout<<ans<<" ";
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string str;
        TreeNode* root; 
        queue<TreeNode*> q;
        getline(ss,str,',');
        TreeNode* temp = str == "#" ? NULL : new TreeNode(stoi(str));
        if(temp)q.push(temp);
        root=temp;
        while(getline(ss,str,',')){
            if(!q.front()){
                q.pop();
                continue;
            }
            TreeNode* left = str == "#" ? NULL : new TreeNode(stoi(str));
            if(left){
                q.front()->left = left;
                q.push(left);
            }
            getline(ss,str,',');
            TreeNode* right = str == "#" ? NULL : new TreeNode(stoi(str));
            if(right){
                q.front()->right = right;
                q.push(right);
            }
            q.pop();
        }
        return root;
    }
};
