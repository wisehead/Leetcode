/*******************************************************************************
 *      file name: design_underground_system.cpp                                               
 *         author: Hui Chen. (c) 2020                             
 *           mail: chenhui13@baidu.com                                        
 *   created time: 2020/10/17-09:20:17                              
 *  modified time: 2020/10/17-09:20:17                              
 *******************************************************************************/
#include <iostream>
#include <map>
using namespace std;
struct Node {
    string station;
    int time;
    Node(string s, int t) {
        station = s;
        time = t;
    }
    Node() {
        station = string("");
        time = 0;
    }
};

struct Order {
    int n;
    int sum;
    double avg;
    Order() {
        n = 0; sum  = 0; avg = 0.0;
    }
};

class UndergroundSystem {
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        Node node(stationName, t);
        travels[id] = node;
    }
    
    void checkOut(int id, string stationName, int t) {
        if (!travels.count(id)) return;
        Node node = travels[id];
        travels.erase(id);
        string str = node.station + stationName;
        
        Order order;
        if (ht.count(str)) order = ht[str];
        order.n++;
        order.sum += (t - node.time);
        order.avg = (double)order.sum/order.n;
        ht[str] = order;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string str = startStation + endStation;
        Order o = ht[str];
        //cout<<"sum:"<<o.sum<<"  n:"<<o.n<<" avg:"<<o.avg<<endl;
        return ht[str].avg;
    }
private:
    map<string, Order> ht;
    map<int, Node> travels;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
int main()
{}
