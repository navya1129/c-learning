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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        ans.push_back({root->val});
        int prev = 1;
        vector<int> arr;
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp != NULL && temp->left != NULL){
                q.push(temp->left);
                arr.push_back(temp->left->val);
            }
            if(temp != NULL && temp->right != NULL){
                q.push(temp->right);
                arr.push_back(temp->right->val);
            }
            prev--;
            if(prev == 0){
                prev = q.size();
                if(arr.size() != 0) ans.push_back(arr);
                arr.clear();
            }
        }
        return ans;
    }
};