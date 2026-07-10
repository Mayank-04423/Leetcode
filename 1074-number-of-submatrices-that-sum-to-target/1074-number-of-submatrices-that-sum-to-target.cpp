class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        //horizontal prefix sum:
        for(int r = 0; r< rows ;r++){
            for(int c =1; c< cols ; c++){
                matrix[r][c]+=matrix[r][c-1];
            }
        }

        int count = 0;
        for(int c1 = 0; c1<cols ; c1++){
            for(int c2 = c1; c2< cols ; c2++){

                unordered_map<int , int> prefixMap;
                prefixMap[0] = 1;

                int currSum = 0;

                for(int r= 0; r < rows; r++){
                    int rowSum = matrix[r][c2];
                    if(c1>0){
                        rowSum -= matrix[r][c1-1];
                    }
                    currSum += rowSum;

                    if(prefixMap.find(currSum - target)!=prefixMap.end()){
                        count += prefixMap[currSum - target];
                    }
                    prefixMap[currSum]++;
                }
            }
        }
        return count;
    }
};