namespace std {
    template <> struct hash<pair<int, int>> {
        inline size_t operator()(const pair<int, int> &v) const {
            hash<int> int_hasher;
            return int_hasher(v.first) ^ int_hasher(v.second) * 63;
        }
    };
}

class MyCalendar {
public:
    set<pair<int, int>> books;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (pair<int, int> elem : books){
            if (start < elem.second && elem.first < end)
                return false;
        }
        books.insert({start, end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */