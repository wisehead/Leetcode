/*******************************************************************************
 *      file name: walking_robot_simulation.cpp                                               
 *         author: Hui Chen. (c) 2019                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2019/01/07-10:07:12                              
 *  modified time: 2019/01/07-10:07:12                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
enum Direction { EAST, NORTH, WEST, SOUTH } d;

class Solution {
public:
    bool is_blocked(vector<vector<int> >& obstacles, int x, int y) {
        cout<<"is_blocked() x:"<<x<<"   y:"<<y<<endl;
		for (int i=0; i<obstacles.size(); i++)
		{
			vector<int> vec = obstacles[i];
			if (x== vec[0] && y == vec[1]) return true;
		}
		return false;
		
	}

	int move(vector<vector<int> >& obstacles, int x, int y, Direction d, int steps) {
        cout<<"move() x:"<<x<<"   y:"<<y<<endl;
		int size = obstacles.size();
		int min_block = 0;
		int max_block = 0;
		switch (d) {
			case EAST:
				min_block = x + steps + 1; 
				for (int i=0; i<size; i++)
				{
					vector<int> vec = obstacles[i];
					cout<<"vec[0]:"<<vec[0]<<"	vec[1]:"<<vec[1]<<endl;
					if (vec[1] == y && vec[0] > x && vec[0] <= x + steps)  
					{
						min_block = min(min_block, vec[0]);
						cout<<"min_block:"<<min_block<<endl;
					}
				}
				return min_block - 1;
			case NORTH:
				min_block = y + steps + 1;
				for (int i=0; i<size; i++)
				{
					vector<int> vec = obstacles[i];
					cout<<"vec[0]:"<<vec[0]<<"	vec[1]:"<<vec[1]<<endl;
					if (vec[0] == x && vec[1] > y && vec[1] <= y + steps)  
					{
						min_block = min(min_block, vec[1]);
						cout<<"min_block:"<<min_block<<endl;
					}
				}
				return min_block - 1;
			case WEST:
				max_block = x - steps - 1; 
				for (int i=0; i<size; i++)
				{
					vector<int> vec = obstacles[i];
					cout<<"vec[0]:"<<vec[0]<<"	vec[1]:"<<vec[1]<<endl;
					if (vec[1] == y && vec[0] < x && vec[0] >= x - steps)  
					{
						max_block = max(max_block, vec[0]);
						cout<<"max_block:"<<max_block<<endl;
					}
				}
				return max_block + 1;
			case SOUTH:
				max_block = y -steps - 1; 
				for (int i=0; i<size; i++)
				{
					vector<int> vec = obstacles[i];
					cout<<"vec[0]:"<<vec[0]<<"	vec[1]:"<<vec[1]<<endl;
					if (vec[0] == x && vec[1] < y && vec[1] >= y - steps)  
					{
						max_block = max(max_block, vec[1]);
						cout<<"max_block:"<<max_block<<endl;
					}
				}
				return max_block + 1;
			defaultT:
				return 0;
		}
		return 0;
	}
	
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
		int x = 0, y = 0;
		d = NORTH;
        int max_distance = 0;
		int size = commands.size();
		for (int i=0; i<size; i++)
		{
			int steps = commands[i];
            cout<<"=======commands["<<i<<"]:"<<commands[i]<<endl;
			if (commands[i] == -2)
			{
				//int temp = d;
				d = Direction((d+1) % 4);
                cout<<"robotSim() direction is:"<<d<<endl;
			}
			else if (commands[i] == -1)
			{
				d = Direction((d-1+4) % 4);
                cout<<"robotSim() direction is:"<<d<<endl;
			}
			else if (commands[i] >= 1 && commands[i] <= 9)
			{
                cout<<"robotSim() direction is:"<<d<<endl;
                int k = 1;
				switch (d) {
					case EAST:
                        x = move(obstacles, x, y, d, steps);
                        cout<<"robotSim() EAST x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case NORTH:
                        y = move(obstacles, x, y, d, steps);
                        cout<<"robotSim() NORTH x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case WEST:
                        x = move(obstacles, x, y, d, steps);
                        cout<<"robotSim() WEST x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case SOUTH:
                        y = move(obstacles, x, y, d, steps);
                        cout<<"robotSim() SOUTH x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					default:
						break;
				}
			}
			else
			{
				cout<<"error! commond["<<i<<"]"<<commands[i]<<endl;
				break;
			}

		}
		return max_distance;
    }
};
int main()
{
	Solution sol;
	int arr[] = {4,-1,4,-2,4};
	//int arr[] = {1,2,-2,5,-1,-2,-1,8,3,-1,9,4,-2,3,2,4,3,9,2,-1,-1,-2,1,3,-2,4,1,4,-1,1,9,-1,-2,5,-1,5,5,-2,6,6,7,7,2,8,9,-1,7,4,6,9,9,9,-1,5,1,3,3,-1,5,9,7,4,8,-1,-2,1,3,2,9,3,-1,-2,8,8,7,5,-2,6,8,4,6,2,7,2,-1,7,-2,3,3,2,-2,6,9,8,1,-2,-1,1,4,7};
	vector<int> commands(arr, arr+5);
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vector<vector<int> >obstacles;
	obstacles.push_back(vec);
	int ret = sol.robotSim(commands, obstacles);
	cout<<"ret:"<<ret<<endl;

}

