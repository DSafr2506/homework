#pragma once

#include <string>
#include <vector>
#include <unordered_map>

namespace template_library {

    class AutoComplete {
        struct Node {
            std::unordered_map<char, Node*> children;
            bool is_end = false;
        };

        Node* root = new Node();

        void dfs(Node* node, const std::string& path, std::vector<std::string>& result);

    public:
        void insert(const std::string& word);
        std::vector<std::string> suggest(const std::string& prefix);
    };
}