struct Node{
    int key,value,freq;
    Node(int k,int v):key(k), value(v), freq(1) {}
};

class LFUCache {
    int capacity,minFreq;
    unordered_map<int, Node*>keyMap;
    unordered_map<int, list<Node*>>freqMap;

    void updateFreq(Node* node){
        int freq = node->freq;
        freqMap[freq].remove(node);

        if(freqMap[freq].empty()){
            freqMap.erase(freq);
            if(minFreq == freq)minFreq++;
        }

        node->freq++;
        freqMap[node->freq].push_front(node);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq=0;
    }
    
    int get(int key) {
        if(keyMap.find(key)==keyMap.end())return -1;
        Node* node = keyMap[key];
        updateFreq(node);
        return node->value;      
    }
    
    void put(int key, int value) {
        if(capacity == 0 )return;
        if(keyMap.find(key)!=keyMap.end()){
            Node* node = keyMap[key];
            node->value = value;
            updateFreq(node);
        }else{
            if(keyMap.size()==capacity){
                Node* lfu = freqMap[minFreq].back();
                freqMap[minFreq].pop_back();
                keyMap.erase(lfu->key);
                delete lfu;
            }

            Node* node = new Node(key,value);
            keyMap[key] = node;
            freqMap[1].push_front(node);
            minFreq = 1;
        }
    }
};

