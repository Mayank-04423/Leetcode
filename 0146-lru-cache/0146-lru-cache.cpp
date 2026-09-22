struct Node {
    int key, value;
    Node* prev;
    Node* next;
    Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
};


class LRUCache {
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    void addToFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addToFront(node);
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (mp.size() == capacity) {
                Node* lru = tail->prev;
                removeNode(lru);
                mp.erase(lru->key);
                delete lru;
            }
            Node* node = new Node(key, value);
            addToFront(node);
            mp[key] = node;
        }
    }
};