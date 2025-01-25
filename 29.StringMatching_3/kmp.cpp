/*******************************************************************************
 *      file name: kmp.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/25- 1:01                                    
 * modified time: 25/01/25- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <vector>

// 构建部分匹配表（前缀函数）
void computeLPSArray(const std::string& pattern, std::vector<int>& lps) {
    int m = pattern.length();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len!= 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP搜索函数
void KMPSearch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    std::vector<int> lps(m);
    computeLPSArray(pattern, lps);
    int i = 0;
    int j = 0;
    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }
        if (j == m) {
            std::cout << "Pattern found at index " << i - j << std::endl;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j]!= text[i]) {
            if (j!= 0) {
                j = lps[j - 1];
            }
            else {
                i++;
            }
        }
    }
}


int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABCABAB";
    KMPSearch(text, pattern);
    return 0;
}
