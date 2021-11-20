/*******************************************************************************
 *      file name: design_parking_system.cpp                                               
 *         author: Hui Chen. (c) 2021                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 2021/08/10-07:37:56                              
 *  modified time: 2021/08/10-07:37:56                              
 *******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;
class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        slots[0] = big;
        slots[1] = medium;
        slots[2] = small;
    }
    
    bool addCar(int carType) {
        if (slots[carType-1]) {
            --slots[carType-1];
            return true;
        }
        return false;
    }
private:
    int slots[3];
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
int main()
{}
