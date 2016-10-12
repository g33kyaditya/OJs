/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        index = 0;
        for (int i = 0; i < nestedList.size(); i++) {
            flatten(nestedList[i]);
        }
    }
    
    void flatten(NestedInteger lariat) {
        if (lariat.isInteger())
            vec.push_back(lariat.getInteger());
        else {
            for (NestedInteger KillerBee : lariat.getList())
                flatten(KillerBee);
        }
    }

    int next() {
        int ret = vec[index];
        index++;
        return ret;
    }

    bool hasNext() {
        return index < vec.size();
    }
private:
    vector<int> vec;
    int index;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
