class StockSpanner {
    stack<pair<int, int>>record;
public:
    StockSpanner() {
       
    }
    
    int next(int price) {
        int span = 1;

        while(!record.empty() &&  record.top().first<= price){
            span += record.top().second;
            record.pop();
        }
        record.push({price , span});

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */