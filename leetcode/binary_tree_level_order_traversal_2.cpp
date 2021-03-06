/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while(!nodes.empty()) {
            vector<int> values;
            int num = nodes.size();
            while(num > 0) {
                TreeNode* node = nodes.front();
                nodes.pop();
                values.push_back(node->val);
                
                if (node->left != NULL) {
                    nodes.push(node->left);
                }
                
                if (node->right != NULL) {
                    nodes.push(node->right);
                }
                
                num--;
            }
            
            res.insert(res.begin(), values);
        }
        
        
        return res;
    }
};