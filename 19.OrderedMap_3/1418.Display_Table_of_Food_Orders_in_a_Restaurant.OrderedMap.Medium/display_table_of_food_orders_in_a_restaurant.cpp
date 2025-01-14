/*******************************************************************************
 *      file name: display_table_of_food_orders_in_a_restaurant.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/14- 1:01                                    
 * modified time: 25/01/14- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<int, map<string, int>> ht;
        set<string> fs;
        vector<vector<string>> res;
        for (auto o : orders) {
            int table_id = stoi(o[1]);
            string food = o[2];
            ht[table_id][food]++;
            fs.insert(food);
        }
        vector<string> header;
        header.push_back("Table");
        for (auto food: fs) {
            header.push_back(food);
        }
        res.push_back(header);
        for (auto it : ht) {
            int table_id = it.first;
            auto food_map = it.second;
            vector<string> items;
            items.push_back(to_string(table_id));
            for (auto food : fs) {
                if (food_map.count(food)) {
                    items.push_back(to_string(food_map[food]));
                } else {
                    items.push_back("0");
                }
            }
            res.push_back(items);
        }
        return res;
    }
};
