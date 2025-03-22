#include "library.hpp"

namespace template_library {

    void AutoComplete::insert([[maybe_unused]]const std::string& word) {
        Node* tec_node = this->root;
        for (char c : word) {
            if (tec_node->children.find(c) == tec_node->children.end()) {
                tec_node->children[c] = new Node();
            }
            tec_node = tec_node->children[c];
        }
        tec_node->is_end = true;
    }

    std::vector<std::string> AutoComplete::suggest([[maybe_unused]] const std::string& prefix) {
        std::vector<std::string> result;
        Node* tec_node = root;
        int flag = 0;
        for (size_t i = 0; i < prefix.size(); ++i) {
            if (tec_node->children.find(prefix[i]) == tec_node->children.end()) {
                flag = 1;
                break;
            }
            tec_node = tec_node->children[prefix[i]];
        }
        if (flag != 1) {
            if (tec_node->is_end == true) {
                result.push_back(prefix);
            }
            dfs(tec_node, prefix, result);
        }
        return result;
    }

    void AutoComplete::dfs(
            [[maybe_unused]] Node* node,
            [[maybe_unused]] const std::string& path,
            [[maybe_unused]] std::vector<std::string>& result) {

            for (const auto& [key, value] : node->children) {
                std::string prefix = path;
                prefix.push_back(key);
                if (node->children[key]->is_end == true) {
                    result.push_back(prefix);
                }
                dfs(node->children[key], prefix, result);
            }
        }
}