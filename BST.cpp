 #include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class TreeNode {
public:
    string word;
    TreeNode* left;
    TreeNode* right;
    TreeNode(const string& key) : word(key), left(nullptr), right(nullptr) {}
};
class BinarySearchTree {
private:
    TreeNode* root;
    void insert(TreeNode*& node, const string& word) {
        if (node == nullptr) {
            node = new TreeNode(word);
        } else if (word < node->word) {
            insert(node->left, word);
        } else {
            insert(node->right, word);
        }
    }
    void suggestWords(TreeNode* node, const string& prefix, vector<string>& suggestions) {
        if (node) {
            if (node->word.find(prefix) == 0) { 
                suggestions.push_back(node->word);
            }
            suggestWords(node->left, prefix, suggestions);
            suggestWords(node->right, prefix, suggestions);
        }
    }
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const string& word) {
        insert(root, word);
    }
    vector<string> autocomplete(const string& prefix) {
        vector<string> suggestions;
        suggestWords(root, prefix, suggestions);
        sort(suggestions.begin(), suggestions.end()); 
        return suggestions;
    }
};
int main() {
    BinarySearchTree bst;
    bst.insert("apple");
    bst.insert("app");
    bst.insert("application");
    bst.insert("banana");
    bst.insert("bat");
    bst.insert("ball");
    bst.insert("car");
    bst.insert("cat");
    bst.insert("dog");
    string prefix;
    cout << "Enter a prefix for autocomplete: ";
    cin >> prefix;
    vector<string> suggestions = bst.autocomplete(prefix);
    if (suggestions.empty()) {
        cout << "No suggestions found for '" << prefix << "'." << endl;
    } else {
        cout << "Suggestions for '" << prefix << "':" << endl;
        for (const string& word : suggestions) {
            cout << "- " << word << endl;
        }
    }
    return 0;
}
