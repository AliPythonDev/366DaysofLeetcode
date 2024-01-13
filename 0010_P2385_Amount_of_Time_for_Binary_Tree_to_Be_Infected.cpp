/* 
Day: 10
Problem Number: 2385 (https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected)
Date: 10-01-2024 
Description:
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.
Each minute, a node becomes infected if:
* The node is currently uninfected.
* The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Code:  */
/*
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
  int amountOfTime(TreeNode* root, int start) {
    int ans = -1;
    const unordered_map<int, vector<int>> graph = getGraph(root);
    queue<int> q{{start}};
    unordered_set<int> seen{start};

    for (; !q.empty(); ++ans) {
      for (int sz = q.size(); sz > 0; --sz) {
        const int u = q.front();
        q.pop();
        if (!graph.count(u))
          continue;
        for (const int v : graph.at(u)) {
          if (seen.count(v))
            continue;
          q.push(v);
          seen.insert(v);
        }
      }
    }
    return ans;
  }
 private:
  unordered_map<int, vector<int>> getGraph(TreeNode* root) {
    unordered_map<int, vector<int>> graph;
    queue<pair<TreeNode*, int>> q{{{root, -1}}};
    while (!q.empty()) {
      const auto [node, parent] = q.front();
      q.pop();
      if (parent != -1) {
        graph[parent].push_back(node->val);
        graph[node->val].push_back(parent);
      }
      if (node->left)
        q.emplace(node->left, node->val);
      if (node->right)
        q.emplace(node->right, node->val);
    }
    return graph;
  }
};
