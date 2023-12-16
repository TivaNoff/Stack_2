#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    stack<TreeNode*> s;
    TreeNode* current = root;

    while (current != nullptr || !s.empty()) {
        while (current != nullptr) {
            s.push(current);
            current = current->left;
        }

        current = s.top();
        s.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}


int main() {
    TreeNode* root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->right->left = new TreeNode(3);
    vector<int> result1 = inorderTraversal(root1);
    for (int val : result1) {
        cout << val << " ";
    }
    cout << endl;

    TreeNode* root2 = nullptr;
    vector<int> result2 = inorderTraversal(root2);
    for (int val : result2) {
        cout << val << " ";
    }
    cout << endl;

    TreeNode* root3 = new TreeNode(1);
    vector<int> result3 = inorderTraversal(root3);
    for (int val : result3) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
