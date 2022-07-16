class LRUCache {
public:
  using PII = pair<int, int>;
  using LI = list<PII>::iterator;

  list<PII> lst;
  unordered_map<int, LI> m1;
  int cap;

  LRUCache(int capacity) : cap(capacity) {
  }

  int get(int key) {
    auto it = m1.find(key);
    if (it == m1.end()) return -1;

    auto val = *(it->second);
    lst.erase(it->second);
    lst.push_front(val);

    m1[key] = lst.begin();

    return val.second;
  }

  void put(int key, int value) {
    auto it = m1.find(key);
    if (it != m1.end()) {
      get(key);
      lst.front().second = value;
      return;
    }

    if (lst.size() == cap) {
      auto v = lst.back().first;
      lst.pop_back();
      m1.erase(v);
    }

    lst.push_front(PII(key, value));
    m1[key] = lst.begin();
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
