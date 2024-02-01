class Solution {
  vector<vector<int>> list;

  void createAdjList(TreeNode *node) {
    if (!node)
      return;

    if (node->left) {
      list[node->left->val].push_back(node->val);
      list[node->val].push_back(node->left->val);
      createAdjList(node->left);
    }

    if (node->right) {
      list[node->right->val].push_back(node->val);
      list[node->val].push_back(node->right->val);
      createAdjList(node->right);
    }
  }

  // longest distance from the target node will be the total time needed to
  // infect the entire tree
  int longestDistFromTarget(int target, int prev, int cDist) {
    if (list[target].size() == 1 &&
        list[target][0] == prev) // means it was originally a leaf node
    {
      return cDist;
    }

    int ans = 0;

    // loop through all the connected paths and check for the longest value
    // except the path that we came from
    for (int idx = 0; idx < list[target].size(); idx++) {
      if (list[target][idx] != prev)
        ans = max(ans,
                  longestDistFromTarget(list[target][idx], target, cDist + 1));
    }

    return ans;
  }

public:
  int amountOfTime(TreeNode *root, int start) {
    // initializing the adj list
    list = vector<vector<int>>(1e5 + 1, vector<int>(0));

    createAdjList(root);

    for (int idx = 0; idx < 6; idx++) {
      cout << idx << ": ";
      for (int jdx = 0; jdx < list[idx].size(); jdx++) {
        cout << list[idx][jdx] << " ";
      }
      cout << endl;
    }

    return longestDistFromTarget(start, start, 0);
  }
};class Solution {
  vector<vector<int>> list;

  void createAdjList(TreeNode *node) {
    if (!node)
      return;

    if (node->left) {
      list[node->left->val].push_back(node->val);
      list[node->val].push_back(node->left->val);
      createAdjList(node->left);
    }

    if (node->right) {
      list[node->right->val].push_back(node->val);
      list[node->val].push_back(node->right->val);
      createAdjList(node->right);
    }
  }

  // longest distance from the target node will be the total time needed to
  // infect the entire tree
  int longestDistFromTarget(int target, int prev, int cDist) {
    if (list[target].size() == 1 &&
        list[target][0] == prev) // means it was originally a leaf node
    {
      return cDist;
    }

    int ans = 0;

    // loop through all the connected paths and check for the longest value
    // except the path that we came from
    for (int idx = 0; idx < list[target].size(); idx++) {
      if (list[target][idx] != prev)
        ans = max(ans,
                  longestDistFromTarget(list[target][idx], target, cDist + 1));
    }

    return ans;
  }

public:
  int amountOfTime(TreeNode *root, int start) {
    // initializing the adj list
    list = vector<vector<int>>(1e5 + 1, vector<int>(0));

    createAdjList(root);

    for (int idx = 0; idx < 6; idx++) {
      cout << idx << ": ";
      for (int jdx = 0; jdx < list[idx].size(); jdx++) {
        cout << list[idx][jdx] << " ";
      }
      cout << endl;
    }

    return longestDistFromTarget(start, start, 0);
  }
};
