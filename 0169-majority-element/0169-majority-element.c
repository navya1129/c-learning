int majorityElement(int* nums, int numsSize) {
    int max = nums[0];
    int occ = 1;
    for(int i = 1;i < numsSize;i++){
        if(max != nums[i]){
            occ--;
        }
        else{
            occ++;
        }

        if(occ == 0){
            max = nums[i];
            occ = 1;
        }
    }
    return max;
}