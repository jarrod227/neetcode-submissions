#include <string>
#include <vector>

class Solution {
public:
    std::string encode(const std::vector<std::string>& strs) {
        std::string res = "";
        for (const std::string& s : strs) {
            res += std::to_string(s.length()) + "#" + s;
        }
        return res;
    }

    std::vector<std::string> decode(const std::string& s) {
        std::vector<std::string> res;
        int i = 0;
        int n = s.length();

        while (i < n) {
            int j = s.find('#', i);
            int length = std::stoi(s.substr(i, j - i));
            int start = j + 1;
            res.push_back(s.substr(start, length));
            i = start + length;
        }

        return res;
    }
};