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
    int mod = 1e9+7;
    long  long sum = 0;
    long  long maxi = 0;
    void fun_sum(TreeNode* root){
        if(root == NULL) return;
        if(root->left != NULL) fun_sum(root->left);
        if(root->right != NULL) fun_sum(root->right);
        sum = sum%mod + (root->val)%mod;
    }
    void fun_pro(TreeNode* root){
        if(root== NULL) return;
        if(root->left != NULL) fun_pro(root->left);
        if(root->right != NULL) fun_pro(root->right);
        if(root->left == NULL && root->right == NULL){
            maxi = max(maxi,(sum-root->val)*root->val);
        }
        else if(root->left == NULL && root->right != NULL){
            root->val = root->val+root->right->val;
            maxi = max(maxi,(sum-root->val)*root->val);
        }
        else if(root->left != NULL && root->right == NULL){
            root->val = root->val+root->left->val;
            maxi = max(maxi,(sum-root->val)*root->val);
        }
        else {
            root->val = root->val+root->left->val;
            root->val = root->val+root->right->val;
            maxi = max(maxi,(sum-root->val)*root->val);
        }
        cout << root->val << " " << maxi << "\n";
    }
    int maxProduct(TreeNode* root) {
        fun_sum(root);
        fun_pro(root);
        return maxi % mod;
    }
};