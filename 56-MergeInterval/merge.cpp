    vector<vector<int>> merge(vector<vector<int>>& intervals) {
          vector<vector<int>> retVec;
  sort(intervals.begin(), intervals.end(),
          [](const std::vector<int>& a, const std::vector<int>& b) {
    return a[0] < b[0];
  });
  
  
  int start = -1, end = -1;
  start=intervals[0][0];
  end=intervals[0][1];


  for (int i = 0; i < intervals.size(); i++) {
      auto currInterval = intervals[i];
      if (end>=currInterval[0])
        end = max(end, currInterval[1]);
      else {
        retVec.push_back({start, end});
        start = currInterval[0];
        end = currInterval[1];
      }
  }
  retVec.push_back({start, end});
  return retVec;      
  
}