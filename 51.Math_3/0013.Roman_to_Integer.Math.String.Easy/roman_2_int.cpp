/*******************************************************************************
 *      File Name: roman_2_int.cpp                                               
 *         Author: Hui Chen. (c) 2017                             
 *           Mail: chenhui13@baidu.com                                        
 *   Created Time: 2017/10/01-23:01                                    
 * Modified Time: 2017/10/01-23:01                                    
 *******************************************************************************/
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef std::map<char, int> UDT_MAP_CHAR_INT; 
class Solution {
public:
	Solution()
	{
		enumMap['I'] = 1;
		enumMap['V'] = 5;
		enumMap['X'] = 10;
		enumMap['L'] = 50;
		enumMap['C'] = 100;
		enumMap['D'] = 500;
		enumMap['M'] = 1000;
	}
	int romanToInt(string s) {
		cout<<"Input s is:"<<s<<endl;
		const char* ptr = s.c_str();
		int i = 0;
		int sum = 0;
		for (i = 0; i< s.length(); i++)
		{
			if (i > 0 && enumMap[ptr[i]] >  enumMap[ptr[i-1]])
			{
				sum = sum + enumMap[ptr[i]] - 2*enumMap[ptr[i-1]];
				int j = 0;
				for (j = i - 1; j-1 >0 && j >=0 && enumMap[ptr[j]] == enumMap[ptr[j-1]] ; j--)
				{
					sum = sum - 2*enumMap[ptr[j]];
				}
			}
			else
			{
				sum = sum + enumMap[ptr[i]];
			}

		}

		cout<<"Output is: "<<sum<<endl;
		return sum;
   	};
private:
	UDT_MAP_CHAR_INT enumMap;
};
int main()
{
	Solution solution;
	solution.romanToInt("I");
	solution.romanToInt("II");
	solution.romanToInt("III");
	solution.romanToInt("IV");
	solution.romanToInt("V");
	solution.romanToInt("VI");
	solution.romanToInt("VII");
	solution.romanToInt("VIII");
	solution.romanToInt("IX");
	solution.romanToInt("X");
	solution.romanToInt("XI");
	solution.romanToInt("XII");
	solution.romanToInt("XIII");
	solution.romanToInt("XIV");
	solution.romanToInt("XV");
	solution.romanToInt("XVI");
	solution.romanToInt("XVII");
	solution.romanToInt("XVIII");
	solution.romanToInt("XIX");
	solution.romanToInt("XX");
	solution.romanToInt("XXI");
	solution.romanToInt("XXII");
	solution.romanToInt("XXIII");
	solution.romanToInt("XXIV");
	solution.romanToInt("XXV");
	solution.romanToInt("XXVI");
	solution.romanToInt("XXVII");
	solution.romanToInt("XXVIII");
	solution.romanToInt("XXIX");
	solution.romanToInt("XXX");
	solution.romanToInt("XXXI");
	solution.romanToInt("XXXII");
	solution.romanToInt("XXXIII");
	solution.romanToInt("XXXIV");
	solution.romanToInt("XXXV");
	solution.romanToInt("XXXVI");
	solution.romanToInt("XXXVII");
	solution.romanToInt("XXXVIII");
	solution.romanToInt("XXXIX");
	solution.romanToInt("XL");
	solution.romanToInt("XLI");
	solution.romanToInt("XLII");
	solution.romanToInt("XLIII");
	solution.romanToInt("XLIV");
	solution.romanToInt("XLV");
	solution.romanToInt("XLVI");
	solution.romanToInt("XLVII");
	solution.romanToInt("XLVIII");
	solution.romanToInt("XLIX");
	solution.romanToInt("L");
	solution.romanToInt("LI");
	solution.romanToInt("LII");
	solution.romanToInt("LIII");
	solution.romanToInt("LIV");
	solution.romanToInt("LV");
	solution.romanToInt("LVI");
	solution.romanToInt("LVII");
	solution.romanToInt("LVIII");
	solution.romanToInt("LIX");
	solution.romanToInt("LX");
	solution.romanToInt("LXI");
	solution.romanToInt("LXII");
	solution.romanToInt("LXIII");
	solution.romanToInt("LXIV");
	solution.romanToInt("LXV");
	solution.romanToInt("LXVI");
	solution.romanToInt("LXVII");
	solution.romanToInt("LXVIII");
	solution.romanToInt("LXIX");
	solution.romanToInt("LXX");
	solution.romanToInt("LXXI");
	solution.romanToInt("LXXII");
	solution.romanToInt("LXXIII");
	solution.romanToInt("LXXIV");
	solution.romanToInt("LXXV");
	solution.romanToInt("LXXVI");
	solution.romanToInt("LXXVII");
	solution.romanToInt("LXXVIII");
	solution.romanToInt("LXXIX");
	solution.romanToInt("LXXX");
	solution.romanToInt("LXXXI");
	solution.romanToInt("LXXXII");
	solution.romanToInt("LXXXIII");
	solution.romanToInt("LXXXIV");
	solution.romanToInt("LXXXV");
	solution.romanToInt("LXXXVI");
	solution.romanToInt("LXXXVII");
	solution.romanToInt("LXXXVIII");
	solution.romanToInt("LXXXIX");
	solution.romanToInt("XC");
	solution.romanToInt("XCI");
	solution.romanToInt("XCII");
	solution.romanToInt("XCIII");
	solution.romanToInt("XCIV");
	solution.romanToInt("XCV");
	solution.romanToInt("XCVI");
	solution.romanToInt("XCVII");
	solution.romanToInt("XCVIII");
	solution.romanToInt("XCIX");
	solution.romanToInt("C");
	solution.romanToInt("DI");
	solution.romanToInt("DL");
	solution.romanToInt("DXXX");
	solution.romanToInt("DCCVII");
	solution.romanToInt("DCCCXC");
	solution.romanToInt("MD");
	solution.romanToInt("MDCCC");
	solution.romanToInt("CM");
}
