class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        
        int n = deck.size();
        vector<int> res(n);
        
        sort(deck.begin(), deck.end());
        
        queue<int> ind;
        for(int i = 0; i < n; i += 1){
            ind.push(i);
        }
        
        for(int i = 0; i < n; i += 1){
            
            res[ind.front()] = deck[i];
            ind.pop();
            
            if(ind.size() != 0){
                //Now push the index from front to the back and pop from front
                ind.push(ind.front());    
                ind.pop();
            }
            
        }
        
        return res;
    }
};