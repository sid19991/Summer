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
private:
    void traverse(TreeNode *root, map<int, vector<pair<int, int>>> &m, int x, int y) {
        if(root) {
            m[x].push_back({y, root->val});
            traverse(root->left, m, x - 1, y + 1);
            traverse(root->right, m, x + 1, y + 1);
        }
    }
    static bool comparator(pair<int, int> a, pair<int, int> b) {
        if(a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> m;
        traverse(root, m, 0, 0);
        vector<vector<int>> ans;
        for(auto it : m) {
            vector<pair<int, int>> v = it.second;
            sort(v.begin(), v.end(), comparator);
            vector<int> t;
            for(auto it : v)
                t.push_back(it.second);
            ans.push_back(t);
        }
        return ans;
    }
};