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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int maxi = INT_MIN;
        int lev = 0;
        int res = 0;
        while(!q.empty()){
            int n = q.size();
            int sum = 0;
            lev++;
            for(int i = 0;i < n;i++){
                TreeNode *temp = q.front();
                sum += temp->val;
                q.pop();
                if(temp->left != NULL) q.push(temp->left);
                if(temp->right != NULL) q.push(temp->right);
            }
            if(sum > maxi){
                res = lev;
                maxi = sum;
            }
        }
        return res;
    }
};