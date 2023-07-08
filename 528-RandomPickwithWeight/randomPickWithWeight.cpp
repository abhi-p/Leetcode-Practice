class Solution {
public:    
    vector<float> arr;
    Solution(vector<int>& w) {
      int counter = 0;
      float sum = accumulate(w.begin(), w.end(), 0);
      for (auto num: w){
          arr.push_back(((float)num)/sum);

      }
      
    }
    
    int pickIndex() {
      
      float randNum = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
      float cumSum = 0.0;
      
      for(int i = 0; i < arr.size(); i++){
        cumSum += arr[i];
        if(cumSum >= randNum)
          return i;
      }
		return 0;
    }
};

