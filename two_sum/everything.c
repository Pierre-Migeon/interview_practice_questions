
void swap(int * const a, int * const b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// Partition indexes that map to nums, without changing nums values or ordering
int partition_indexes(const int* const nums, int* const indexes, int lo, int hi) {
  int pivot = lo++;
  int pivot_val = nums[indexes[pivot]];
  int idx = pivot;

  for (; lo < hi; ++lo) {
    if (nums[indexes[lo]] <= pivot_val) {
      swap(indexes + lo, indexes + ++idx);
    }
  }
 
  // Swapt the pivot (which is at the front) with the last value less or equal to the pivot
  swap(indexes + pivot, indexes + idx);
  
  return idx;
}

// Sort indexes that map to nums, without changing nums values or ordering
void sort_indexes(const int* const nums, int* const indexes, int lo, int hi) {
  if (lo < hi) {
    int pivot = partition_indexes(nums, indexes, lo, hi);
    sort_indexes(nums, indexes, lo, pivot);
    sort_indexes(nums, indexes, pivot + 1, hi);
  }
}


int* twoSum(int* nums, int numsSize, int target) {
  int* ret = (int*)malloc(2 * sizeof(int));
  
  // Build index mapping to nums that is sorted assendingly
  int* indexes = (int *)malloc(numsSize * sizeof(int));
  for (int i = 0; i < numsSize; ++i) {
    indexes[i] = i;
  }
  sort_indexes(nums, indexes, 0, numsSize);

  // Move in from either side, if the pair is below target, then left index must increase
  // to increase the sum, while right must decrease if the sum is over
  int lo = 0;
  int hi = numsSize - 1;
  while (nums[indexes[lo]] + nums[indexes[hi]] != target) {
    if (nums[indexes[lo]] + nums[indexes[hi]] < target) {
      ++lo;
    } else {
      --hi;
    }
  }
  
  ret[0] = indexes[lo];
  ret[1] = indexes[hi];
  
  free(indexes);

  return ret;
}
