/**
 * 146. LRU Cache
 * Difficulty: Medium
 * Link: https://leetcode.com/problems/lru-cache/description/
 */

#include <algorithm>
#include <iostream>
#include <list>
#include <print>
#include <string>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

struct Node {
    int key;
    int value;
};

class LRUCache {
public:
    int capacity;
    list<Node> l;
    unordered_map<int, list<Node>::iterator> m;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (m.contains(key)) {
            l.splice(l.end(), l, m[key]);
            return m[key]->value;
        }

        return -1;
    }

    void put(int key, int value) {
        if (!m.contains(key)) {
            if (m.size() >= this->capacity) {
                m.erase((*l.begin()).key);
                this->l.erase(l.begin());
            }

            l.push_back({key, value});
            m[key] = prev(l.end());

        } else {
            l.splice(l.end(), l, m[key]);
            m[key]->value = value;
        }
    }
};

int main() {
    // Example 1
    {
        LRUCache lRUCache(2);
        lRUCache.put(1, 1);
        lRUCache.put(2, 2);
        int out1 = lRUCache.get(1);
        println("get(1) -> Output: {}, Expected: 1", out1);

        lRUCache.put(3, 3);
        int out2 = lRUCache.get(2);
        println("get(2) -> Output: {}, Expected: -1", out2);

        lRUCache.put(4, 4);
        int out3 = lRUCache.get(1);
        println("get(1) -> Output: {}, Expected: -1", out3);

        int out4 = lRUCache.get(3);
        println("get(3) -> Output: {}, Expected: 3", out4);

        int out5 = lRUCache.get(4);
        println("get(4) -> Output: {}, Expected: 4", out5);
    }

    return 0;
}
