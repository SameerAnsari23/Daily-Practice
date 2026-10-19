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
    unordered_map<int, vector<int>>adj;
    void graph(TreeNode* root) {
        if(!root) return;

        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
        }
        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
        }
        graph(root->left);
        graph(root->right);
    }
    int amountOfTime(TreeNode* root, int start) {
        graph(root);

        queue<int>q;
        q.push(start);
        unordered_map<int, bool>vis;
        vis[start] = true;
        int min = -1;

        while (!q.empty()) {
            int level = q.size();
            min++;

            for (int i = 0; i < level; i++) {
                int node = q.front();
                q.pop();

                for (auto &it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
        }
        return min;
    }
};
