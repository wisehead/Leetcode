/*******************************************************************************
 *      file name: employee_importance.cpp                                               
 *         author: Hui Chen. (c) 2018                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2018/09/19-21:49:57                              
 *  modified time: 2018/09/19-21:49:57                              
 *******************************************************************************/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
class Solution {
public:
	int getImportance(map<int, Employee*>* mm,int id) {
		Employee* temp = (*mm)[id];
		if (!temp) return 0;
		vector<int> subs = temp->subordinates;
		if (subs.size() == 0) return temp->importance;
		int sum = temp->importance;
		for (int i=0; i<subs.size(); i++)
		{
			sum += getImportance(mm, subs[i]);
		}
		return sum;
	}
    int getImportance(vector<Employee*> employees, int id) {
		int len = employees.size();
		map<int, Employee*> mm;
		for (int i=0; i<len; i++)
		{
			Employee* emp = employees[i];
			mm[emp->id] = emp;
		}
		int sum = getImportance(&mm, id);
		return sum;
    }
};
int main()
{}
