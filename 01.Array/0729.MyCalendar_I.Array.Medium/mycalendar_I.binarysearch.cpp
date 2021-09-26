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
		int left = 0, right = vv.size() - 1, mid = 0;
		while (left <= right)
		{
			mid = (left + right)/2;
            //cout<<"left:"<<left<<"  right:"<<right<<"   mid:"<<mid<<endl;
			if (vv[mid][0] == start)
				return false;
			if (vv[mid][0] < start)
			{
				if (vv[mid][1] <= start)
				{
					left = mid + 1;
				}
				else
					return false;
			}
			else
			{
				if (end <= vv[mid][0])
				{
					right = mid;
                    if(left == right) break;
				}
				else
					return false;

			}
		}
		index = left;
        //cout<<"index:"<<index<<endl;
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
