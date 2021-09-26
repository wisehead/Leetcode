/*******************************************************************************
 *      file name: decrypt_string_from_alphabet_to_integer_mapping.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/07/31-12:30:38                              
 *  modified time: 2021/07/31-12:30:38                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string freqAlphabets(string s) {
        map<string, string> mm;
        mm["1"] = "a";
        mm["2"] = "b";
        mm["3"] = "c";
        mm["4"] = "d";
        mm["5"] = "e";
        mm["6"] = "f";
        mm["7"] = "g";
        mm["8"] = "h";
        mm["9"] = "i";
        mm["10"] = "j";
        mm["11"] = "k";
        mm["12"] = "l";
        mm["13"] = "m";
        mm["14"] = "n";
        mm["15"] = "o";
        mm["16"] = "p";
        mm["17"] = "q";
        mm["18"] = "r";
        mm["19"] = "s";
        mm["20"] = "t";
        mm["21"] = "u";
        mm["22"] = "v";
        mm["23"] = "w";
        mm["24"] = "x";
        mm["25"] = "y";
        mm["26"] = "z";
        string res;
        int i = s.length()-1;
        string tmp;
        while (i >= 0) {
            if (s[i] == '#') {
                i -= 2;
                tmp = s.substr(i,2);
            } else {
                tmp = s.substr(i,1);
            }
            res = mm[tmp] + res;
            i--;
        }
        return res;
    }
};
int main()
{}
