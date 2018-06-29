/*
 * Write a function that determines if one string is an anagram of another (in C++).
 */
#include <string>
#include <map>
#include <cassert>
using std::string;
using std::map;

/*
 * Say whether the two input strings are anagrams of each
 * other or not
 */
bool is_anagram(const string &word1, const string &word2) {
    if(word1.size() != word2.size()) {
        return false;
    }
    map<char, int> char_counts;
    for(size_t i = 0;i < word1.size(); ++i) {
        char_counts[word1[i]]++;
        char_counts[word2[i]]--;
    }
    for(map<char,int>::iterator i=char_counts.begin();
            i != char_counts.end();++i) {
        if(i->second != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    assert(is_anagram("cat", "tac") == true);
    assert(is_anagram("cot", "tac") == false);
    assert(is_anagram("cata", "tac") == false);
    assert(is_anagram("tac", "tac") == true);
    assert(is_anagram("taca", "tac") == false);
    assert(is_anagram("cat", "xyz") == false);
    assert(is_anagram("cat", "catcat") == false);
    assert(is_anagram("", "") == true);
    assert(is_anagram("cat", "") == false);
    assert(is_anagram("", "tac") == false);
    return 0;
}

