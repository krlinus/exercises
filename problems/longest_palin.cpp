#include <string>
#include <iostream>
using namespace std;
    string get_palin_at(const string &s, int start, int end) {
      int st=start,e=end;
      while(start <= end) {
        if (s[start] != s[end]) return string("");
        start++;
        end--;
      }
      string res = s.substr(st, e - st + 1);
      return res;
    }
class Solution {
public:
/* Testing some solutions from elsewhere ..... (they are good) */
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int len = s.size(), max_left = 0, max_len = 1, left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
    string longestPalindrome2(string s) {
      if (s.empty()) return "";
      if (s.size() == 1) return s;
      int min_start = 0, max_len = 1;
      for (int i = 0; i < s.size();) {
  if (s.size() - i <= max_len / 2) break;
  int j = i, k = i;
  while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
  i = k+1;
  while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
  int new_len = k - j + 1;
  if (new_len > max_len) { min_start = j; max_len = new_len; }
      }
      return s.substr(min_start, max_len);
    }
/* end: other solutions; start of mine (doesn't work yet, or look as good!) */
    string longestPalindrome1(string s) {
      const int sz = s.size();
      int curr_max=0;
      string longest;
      for(int j = 0; j < sz; ++j) {
        int inc=0;
        for(int i = j; i-inc >= 0 && i+inc < sz;++inc) {
          string palin = get_palin_at(s, i - inc, i);
          if (palin.size() > curr_max) {
            curr_max = palin.size();
            longest = palin;
          }
          palin = get_palin_at(s, i, i + inc);
          if (palin.size() > curr_max) {
            curr_max = palin.size();
            longest = palin;
          }
          palin = get_palin_at(s, i - inc, i + inc);
          if (palin.size() > curr_max) {
            curr_max = palin.size();
            longest = palin;
          }
        }
      }
      return longest;
    }
};

int main() {
  Solution s;
  const char *tests0_results1[] = {"babad", "bab", "cbbd", "bb",
      "abcbassss", "abcba", "ssssabcba", "abcba", "sssabcbannnn", "abcba",
      "abccbassss", "abccba", "ssssabccba", "abccba",
      "sssabccbannnnn", "abccba", "abcbatrabccba", "abccba",
      "cccabcbaabccbasss", "abccba", "abcbaabccbabccbaabcba", "abcbaabccbabccbaabcba",
      "nnnnabcbaabccbabccbaabcbawww", "abcbaabccbabccbaabcba",
      "tttabcbaabccbabccbaabcba", "abcbaabccbabccbaabcba",
      "abcbaabccbabccbaabcbawwqqq", "abcbaabccbabccbaabcba",
      "abcbaabccbaabccbaabcba", "abcbaabccbaabccbaabcba",
      "nnnnabcbaabccbaabccbaabcbawww", "abcbaabccbaabccbaabcba",
      "tttabcbaabccbaabccbaabcba", "abcbaabccbaabccbaabcba",
      "abcbaabccbaabccbaabcbawwqqq", "abcbaabccbaabccbaabcba" };
  const int test_count = (sizeof(tests0_results1) / sizeof(char*)) / 2;
  for(int i = 0; i < test_count; i += 2) {
    string res = s.longestPalindrome(string(tests0_results1[i]));
    if(res != tests0_results1[i+1]) {
      cerr << "FAIL: Input - " << tests0_results1[i] <<
              "\n\texpected output: " << tests0_results1[i+1] <<
              "\n\treceived: " << res << endl;
    } else {
      cout << "PASS: Received " << res << " for " << tests0_results1[i] << endl;
    }
  }
}
#if 0
Current status:
PASS: Received bab for babad
PASS: Received bb for cbbd
PASS: Received abcba for abcbassss
PASS: Received abcba for ssssabcba
PASS: Received abcba for sssabcbannnn
FAIL: Input - abccbassss
  expected output: abccba
  received: bccb
FAIL: Input - ssssabccba
  expected output: abccba
  received: ssss
PASS: Received abccba for sssabccbannnnn
PASS: Received abccba for abcbaabccba

#endif
