/*******************************************************************************
 *      file name: rolling_hash.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/21- 1:01                                    
 * modified time: 25/01/21- 1:01                                    
 *******************************************************************************/
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

class RollingHash {
private:
    static const long long base = 256;
    static const long long mod = 1e9 + 7;
    long long window_size;
    long long power;
    long long hash_value;
    std::string text;

    long long mod_add(long long a, long long b) const {
        return ((a % mod) + (b % mod)) % mod;
    }

    long long mod_sub(long long a, long long b) const {
        return ((a % mod) - (b % mod) + mod) % mod;
    }

    long long mod_mul(long long a, long long b) const {
        return ((a % mod) * (b % mod)) % mod;
    }

public:
    RollingHash(const std::string& str, long long window) : window_size(window), hash_value(0), text(str) {
        power = 1;
        for (long long i = 0; i < window_size; ++i) {
            hash_value = mod_add(mod_mul(hash_value, base), str[i]);
            if (i < window_size - 1) {
                power = mod_mul(power, base);
            }
        }
    }

    long long getHash() const {
        return hash_value;
    }

    void roll() {
        if (text.size() <= window_size) return;
        hash_value = mod_sub(mod_mul(base, hash_value), mod_mul(power, text[0]));
        hash_value = mod_add(hash_value, text[window_size]);
        text = text.substr(1);
    }

    std::vector<long long> getRollingHashes() {
        std::vector<long long> hashes;
        hashes.push_back(hash_value);
        while (text.size() > window_size) {
            roll();
            hashes.push_back(hash_value);
        }
        return hashes;
    }
};

int main() {
    std::string text = "ABABDABACDABABCABAB";
    std::string pattern = "ABABC";
    RollingHash pattern_roll(pattern, pattern.size());
    long long pattern_hash = pattern_roll.getHash();
    RollingHash text_roll(text, pattern.size());
    std::vector<long long> text_hashes = text_roll.getRollingHashes();
    for (size_t i = 0; i < text_hashes.size(); ++i) {
        if (text_hashes[i] == pattern_hash) {
            if (text.substr(i, pattern.size()) == pattern) {
                std::cout << "Pattern found at index " << i << std::endl;
            }
        }
    }
    return 0;
}
