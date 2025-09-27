#include <vector>
#include <unordered_map>

struct MyListNode {
    MyListNode() : val(-42) {
        next = this;
        prev = this;
    }

    MyListNode(int answer) : val(answer) {
        next = this;
        prev = this;
    }

    MyListNode(int answer, MyListNode * next_) : val(answer), next(next_) {
        next_->prev = this;
        prev = this;
    }

    MyListNode(int answer, MyListNode * prev_, MyListNode * next_) : val(answer), next(next_), prev(prev_) {
        next_->prev = this;
        prev_->next = this;
    }

    MyListNode(MyListNode * cur) : val(cur->val), next(cur->next), prev(cur->prev) {}

    int val;
    MyListNode * next;
    MyListNode * prev;
};

class LRUCache {
public:
    LRUCache(int capacity) : cap(capacity) {
        dummyTail = new MyListNode();
        dummyHead = new MyListNode(-42, dummyTail);
    }
    
    int get(int key) {
        if (!mp.contains(key)) {
            return -1;
        }
        MyListNode * cur = mp[key];
        int answer = cur->val;
        
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        mpReversed.erase(cur);
        mp.erase(key);

        cur = new MyListNode(answer, dummyHead, dummyHead->next);
        mp[key] = cur;
        mpReversed[cur] = key;

        return answer;      
    }
    
    void put(int key, int value) {
        if (!mp.contains(key)) {
            if (cap == 0) {
                MyListNode * forDelete = dummyTail->prev;

                forDelete->next->prev = forDelete->prev;
                forDelete->prev->next = forDelete->next;

                mp.erase(mpReversed[forDelete]);
                mpReversed.erase(forDelete);
            }

            MyListNode * cur = new MyListNode(value, dummyHead, dummyHead->next);
            mp[key] = cur;
            mpReversed[cur] = key;

            if (cap > 0) {
                --cap;
            }
            return;
        }

        MyListNode * cur = mp[key];

        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;

        mpReversed.erase(cur);

        cur = new MyListNode(value, dummyHead, dummyHead->next);
        mp[key] = cur;
        mpReversed[cur] = key;
        return;
    }

    int cap;
    MyListNode * dummyHead;
    MyListNode * dummyTail;
    std::unordered_map<int, MyListNode *> mp;
    std::unordered_map<MyListNode *, int> mpReversed;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */