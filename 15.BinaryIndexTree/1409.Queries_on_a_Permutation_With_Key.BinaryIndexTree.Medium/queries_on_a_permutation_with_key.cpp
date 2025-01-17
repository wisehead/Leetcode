/*******************************************************************************
 *      file name: queries_on_a_permutation_with_key.cpp                                               
 *         author: hui chen. (c) 25                             
 *           mail: alex.chenhui@gmail.com                                        
 *   created time: 25/01/17- 1:01                                    
 * modified time: 25/01/17- 1:01                                    
 *******************************************************************************/
#include <iostream>
class Solution {
private:
    int querySum(vector<int> &BIT, int x) {
        int sum = 0;
        for (; x > 0; x -= (x & -x))
            sum += BIT[x];
        return sum;
    }
    void update(vector<int> &BIT, int x, const int val) {
        for (; x < BIT.size(); x += (x & -x))
            BIT[x] += val;
    }
public:
    vector<int> processQueries(vector<int>& query, int m) {
        if (m == 1)
            return {0};
        int n = query.size();
        vector<int> ans, tree(m + n + 1, 0), hash(m + 1);
        for (int i = 1; i <= m; ++i) {
            hash[i] = n + i;
            update(tree, n + i, 1);//build binary indexed tree
        }
        for (auto q : query) {
            ans.push_back(querySum(tree, hash[q] - 1));
            update(tree, hash[q], -1);//decrease 1 element to index=hash[q] and after
            update(tree, n, 1);//increase 1 element to index=n and after
            hash[q] = n--;//update hash[q]
        }
        return ans;
    }
};

/*
This solution is inspired by @aravind-kumar's post and the question asked by @JummyEgg here.

Intuition
Instead of deleting & inserting element inP = [1,2,3,...,m]every step, prepare an extra space for insertion. And the maximum number of elements to be inserted is already given by the size ofqueryarray.

Imagine there's avirtualParray which is the originalParray extened by the length ofqueryarray, i.e.,virtualP.size() = P.size() + query.size() = m + n
ThevirtualParray can be separate as the former(new insertion, size n) part and the later(orignal, size m) part.

In each step, find out the postion of target value given byqueryand simply move it from its original position to the former part ofvirtualParray.

Notice thatvirtualParray virtually "grows" from size m to size m + n, so the new position of the target value shall always be in front of the first element of currentvirtualP.

Here, a hash map can help memorizing the index of current position of every value in theParray, and since the value is already given as[1, 2, ..., m], index can be easily used as key(= value). So declaring an array with size (m + 1) would be enough.

Moreover, a binary indexed tree is introduced to optimized the time of index calculation. Index of array can be regared as the total number of elements before this position.
Ex: for index2, there are two elements before position[2], that is[0]and[1].
And for ease, definequerySum(tree, x)= total elements invirtualParray before position[x + 1]

Approach
Initialize the position ofP = [1,2,3,...,m]as[n + 1, n + 2, n + 3,..., n + m]in a hash table and build the binary indexed tree forvirtualParray, i.e., putting elements ofPinto the latter part ofvirtualP.
Notice that thevirtualParray is just in imagination, keep it in mind for better understanding.

Letqbe element given byquery, in each process

Look up current position ofqstored inhashand calculate the total number of elements before this position.
Virtual deleteqinvirtualParray, minus 1 element after current position ofq(included) intree
Virtual insertqin front ofvirtualParray, plus 1 element after positionn(included) intree
Updatehash[q], since step3 putqin front ofvirtualParray
Decreasenby one, because there is one insertion performed, or can be thought as one position taken in the former part ofvirtualParray
Take example1 for demo,P = [1,2,...,5], m = 5,queries = [3,1,2,1], n = 4
After initialization, the extended arrayvirtualPandhashshall be:

+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 | 5 | 
+---+---+---+---+---+---+
|   | 5 | 6 | 7 | 8 | 9 |
+---+---+---+---+---+---+
After process q = 3:

+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 | 5 | 
+---+---+---+---+---+---+
|   | 5 | 6 | 4 | 8 | 9 |
+---+---+---+---+---+---+
After process q = 1:

+---+---+---+---+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
+---+---+---+---+---+---+---+---+---+---+
| 0 | 0 | 0 | 1 | 2 | 0 | 1 | 0 | 4 | 1 |
+---+---+---+---+---+---+---+---+---+---+
After process q = 2:

+---+---+---+---+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
+---+---+---+---+---+---+---+---+---+---+
|   |   | 2 | 1 | 3 |   |   |   | 4 | 5 |
+---+---+---+---+---+---+---+---+---+---+
After process q = 1:

+---+---+---+---+---+---+
| 0 | 1 | 2 | 3 | 4 | 5 | 
+---+---+---+---+---+---+
|   | 1 | 2 | 4 | 8 | 9 |
+---+---+---+---+---+---+
*/
