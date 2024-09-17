/*******************************************************************************
 *      file name: mycalendar_I.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/05/20-09:53:04                              
 *  modified time: 2019/05/20-09:53:04                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class MyCalendar {
public:
    MyCalendar() {
    }
    
	bool check_ok(int start, int end, int& index) {
		index = 0;
		if (vv.empty()) return true;
		while (index < vv.size() )
		{
			if (vv[index][0] < start)
			{
				if (vv[index][1] <= start)
				{
					index++;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (end <= vv[index][0])
				{
					return true;
				}
				else
					return false;
			}
		}
		return true;
	}
    bool book(int start, int end) {
		int index = 0;
		if (!check_ok(start, end, index))
			return false;
		vector<int> vec;
		vec.push_back(start);
		vec.push_back(end);
		vv.insert(vv.begin()+index, vec);
		return true;
    }
private:
	vector<vector<int> > vv;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
int main()
{}
