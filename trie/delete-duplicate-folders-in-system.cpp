class Solution {
private:
    struct TrieNode {
        map<string, TrieNode*> children;
    };

    unordered_map<string, int> signature_counts;
    unordered_map<TrieNode*, string> node_to_signature;

    TrieNode* buildTrie(const vector<vector<string>>& paths) {
        TrieNode* root = new TrieNode();
        for (const auto& path : paths) {
            TrieNode* curr = root;
            for (const string& folder : path) {
                if (curr->children.find(folder) == curr->children.end()) {
                    curr->children[folder] = new TrieNode();
                }
                curr = curr->children[folder];
            }
        }
        return root;
    }

    string serialize(TrieNode* node) {
        string signature = "";
        if (!node->children.empty()) {
            for (auto const& [name, child] : node->children) {
                signature += name + "(" + serialize(child) + ")";
            }
            signature_counts[signature]++;
        }
        node_to_signature[node] = signature;
        return signature;
    }

    void buildResult(TrieNode* node, vector<string>& current_path,
                     vector<vector<string>>& result) {
        for (auto const& [name, child] : node->children) {
            const string& child_signature = node_to_signature.at(child);

            if (!child_signature.empty() &&
                signature_counts.at(child_signature) > 1) {
                continue;
            }

            current_path.push_back(name);
            result.push_back(current_path);
            buildResult(child, current_path, result);
            current_path.pop_back();
        }
    }

public:
    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        TrieNode* root = buildTrie(paths);
        serialize(root);

        vector<vector<string>> result;
        vector<string> current_path;
        buildResult(root, current_path, result);

        return result;
    }
};