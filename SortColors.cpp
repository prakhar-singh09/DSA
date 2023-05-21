class Solution {
public:
    void sortColors(vector<int>& nums) {
       //something called dutch algo to solve this problem

       //basically we have to place three values in three position i.e, lower middle and last

       

       int low = 0;
       int mid =0;
       int high = nums.size()-1;
      while(mid<=high){
          if(nums[mid]==0)
          {
              swap(nums[low],nums[mid]);
              low++;
              mid++;
          }
          else if(nums[mid]==1)
          mid++;
          
          else if(nums[mid]==2){
              swap(nums[mid],nums[high]);
              high--;
          }
      }


  }
};
