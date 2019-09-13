#include <stdio.h>

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
void sort_indexes(int *nums, int *indexes, int lo, int hi) {
  if (lo < hi) {
    int pivot = partition_indexes(nums, indexes, lo, hi);
    sort_indexes(nums, indexes, lo, pivot);
    sort_indexes(nums, indexes, pivot + 1, hi);
  }
}


int	main()
{
	int nums[10] = {10,9,8,7,6,5,4,3,2,1};
	int index[10] = {0,1,2,3,4,5,6,7,8,9};
	sort_indexes(nums, index, 0, 9);

	for ( int i = 0; i < 10; i++)
	{
		printf("num is %i\n", nums[i]);
	}
	return (0);
}
