void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
   int num1Idx = m-1, num2Idx = n-1;

  for (int i=nums1.size()-1;i>=0;i--){
    //cout<<num1Idx<<" "<<num2Idx<<" "<<i<<endl;
     if(num2Idx < 0) {
       break;
     }
     if(num1Idx < 0) {
       while(i >=0) {
         nums1[i] = nums2[num2Idx];
         num2Idx-=1;
         i-=1;
       }
       break;
     }
     if(nums1[num1Idx] > nums2[num2Idx]) {
       nums1[i] = nums1[num1Idx];
       num1Idx-=1;
     }
      else{
        nums1[i] = nums2[num2Idx];
         num2Idx-=1;
      }
    
  }
  
  
  
}