class SummaryRanges {
    set<int>values;
public:
    SummaryRanges() {
        
    }
    
    void addNum(int value) {
        values.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        if (values.empty()) return {};
        
        vector<vector<int>> res;
        
        auto it = values.begin();
        
        int start1 = *it;
        int end1 = *it;
        it++; // Move to the next 
        
        while (it != values.end()) {
            int currentVal = *it; // The challenger element
            
                if (currentVal == end1 + 1) {
                end1 = currentVal; // Extend 
            } 
            // Gap found
            else {
                res.push_back({start1, end1}); 
                start1 = currentVal; 
                end1 = currentVal;
            }
            it++;
        }
        
        res.push_back({start1, end1});
        
        return res;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */