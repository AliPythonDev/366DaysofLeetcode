/*
Day: 267
Problem Number: 2707 (https://leetcode.com/problems/extra-characters-in-a-string)
Date: 23-09-2024
Description:
You are given a 0-indexed string s and a dictionary of words dictionary. You have to break s into one or more non-overlapping substrings such that each substring is present in dictionary. There may be some extra characters in s which are not present in any of the substrings.
Return the minimum number of extra characters left over if you break up s optimally.
 
Example 1:
Input: s = "leetscode", dictionary = ["leet","code","leetcode"]
Output: 1
Explanation: We can break s in two substrings: "leet" from index 0 to 3 and "code" from index 5 to 8. There is only 1 unused character (at index 4), so we return 1.

Example 2:
Input: s = "sayhelloworld", dictionary = ["hello","world"]
Output: 3
Explanation: We can break s in two substrings: "hello" from index 3 to 7 and "world" from index 8 to 12. The characters at indices 0, 1, 2 are not used in any substring and thus are considered as extra characters. Hence, we return 3.
 
Constraints:
* 1 <= s.length <= 50
* 1 <= dictionary.length <= 50
* 1 <= dictionary[i].length <= 50
* dictionary[i] and s consists of only lowercase English letters
* dictionary contains distinct words

Code:  */
class Node {
public:
    Node* children[26];
    bool isEnd = false;
    Node() {
        fill(children, children + 26, nullptr);
    }
};

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        Node* root = new Node();
        for (const string& w : dictionary) {
            Node* node = root;
            for (int k = w.length() - 1; k >= 0; --k) {
                int i = w[k] - 'a';
                if (node->children[i] == nullptr) {
                    node->children[i] = new Node();
                }
                node = node->children[i];
            }
            node->isEnd = true;
        }

        int n = s.size();
        int f[n + 1];
        f[0] = 0;
        for (int i = 1; i <= n; ++i) {
            f[i] = f[i - 1] + 1;
            Node* node = root;
            for (int j = i - 1; ~j; --j) {
                node = node->children[s[j] - 'a'];
                if (node == nullptr) {
                    break;
                }
                if (node->isEnd && f[j] < f[i]) {
                    f[i] = f[j];
                }
            }
        }
        return f[n];
    }
};
