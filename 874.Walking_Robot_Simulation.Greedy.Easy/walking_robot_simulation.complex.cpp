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
	
    int robotSim(vector<int>& commands, vector<vector<int> >& obstacles) {
		int x = 0, y = 0;
		d = NORTH;
        int max_distance = 0;
		int size = commands.size();
		for (int i=0; i<size; i++)
		{
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
						for (k=1; k<= commands[i]; k++)
						{
							if (is_blocked(obstacles, x+k, y))
							{
								x = x + k -1;
                                cout<<"robotSim() x:"<<x<<"   y:"<<y<<endl;
								break;
							}
						}
                        if (k > commands[i])
                            x += commands[i];
                        cout<<"robotSim() EAST x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case NORTH:
						for (k=1; k<= commands[i]; k++)
						{
							if (is_blocked(obstacles, x, y+k))
							{
								y = y + k -1;
                                cout<<"robotSim() x:"<<x<<"   y:"<<y<<endl;
								break;
							}
						}
                        if (k > commands[i])
                            y += commands[i];
                        cout<<"robotSim() NORTH x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case WEST:
						for (k=1; k<= commands[i]; k++)
						{
							if (is_blocked(obstacles, x-k, y))
							{
								x = x - k +1;
                                cout<<"robotSim() x:"<<x<<"   y:"<<y<<endl;
								break;
							}
						}
                        if (k > commands[i])
                            x -= commands[i];
                        cout<<"robotSim() WEST x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					case SOUTH:
						for (k=1; k<= commands[i]; k++)
						{
							if (is_blocked(obstacles, x, y-k))
							{
								y = y - k +1;
                                cout<<"robotSim() x:"<<x<<"   y:"<<y<<endl;
								break;
							}
						}
                        if (k > commands[i])
                            y -= commands[i];
                        cout<<"robotSim() SOUTH x:"<<x<<"   y:"<<y<<endl;
                        max_distance = max(max_distance, x*x + y*y);
						break;
					default:
						break;
				}
			}
			else
			{
				cout<<"error!"<<endl;
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
	vector<int> commands(arr, arr+100);
	vector<int> vec;
	vec.push_back(2);
	vec.push_back(4);
	vector<vector<int> >obstacles;
	obstacles.push_back(vec);
	int ret = sol.robotSim(commands, obstacles);
	cout<<"ret:"<<ret<<endl;

}

