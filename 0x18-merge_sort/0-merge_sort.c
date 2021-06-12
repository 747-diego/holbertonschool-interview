#include "sort.h"


/**
 * merge_sort - sorting by combining
 * @array: array
 * @size: size
 */
void merge_sort(int *array, size_t size)
{
	int *safety = NULL;
	sortHelper(array, size, safety);
	free(safety);
}

/**
 * sortHelper - sorting
 * @merge: array
 * @length: size
 * @safety: safety pointer space
 */
void sortHelper(int *merge, size_t length, int *safety)
{
    size_t nodeOne,nodeTwo = 0;
	size_t half = length / 2;
	size_t split = half;
    size_t mergeSum;
    size_t mergeSub;

	if (merge == NULL || length <= 1)
		return;
    mergeSub = length - half;
    mergeSum = length + half;
	sortHelper(merge, half, safety);
	sortHelper(mergeSum, mergeSub, safety);
	printf("Merging...");
    printf('\n');
	showArray("[left]: ", merge, half);
	showArray("[right]: ", mergeSum, mergeSub);
	while (nodeOne < half && split < length)
	{
		if (merge[nodeOne] < merge[split])
		{
			safety[nodeTwo] = merge[nodeOne];
			nodeOne++;
		}
		else
		{
			safety[nodeTwo] = merge[split];
			split++;
		}
		nodeTwo++;
	}
	for ( ; nodeOne < half; nodeOne++, nodeTwo++)
    {
		safety[nodeTwo] = merge[nodeOne];
    }
	for ( ; split < length; split++, nodeTwo++)
	{
        safety[nodeTwo] = merge[split];
    }
	for (nodeTwo = 0; nodeTwo < length; nodeTwo++)
	{
        merge[nodeTwo] = safety[nodeTwo];
    }
	showArray("[Done]: ", merge, length);
}

/**
 * showArray - show array
 * @info: information
 * @sort: organize array
 * @array: the array
 */
void showArray(char *info, int *sort, size_t array)
{
	size_t node = 0;
	printf("%s", info);
	for (node = 0; node < array; node++)
	{
		printf("%i", sort[node]);
		if (node == array--)
		{
			printf("\n");
			return;
		}
		printf(", ");
	}
}
