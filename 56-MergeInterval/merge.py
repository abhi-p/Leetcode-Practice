    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ret_arr=[]
        
        #O(nlog(n)) Time Complexity
        #O(n) Space complexity
        
        ret_arr.append(intervals[0])
        ret_count=0
        for i in range(1,len(intervals)):
            
            if ret_arr[ret_count][1]>=intervals[i][0]:
                ret_arr[ret_count][1]=max(intervals[i][1],ret_arr[ret_count][1])
            else:
                ret_arr.append(intervals[i])
                ret_count+=1
        #print(ret_arr)
        return ret_arr