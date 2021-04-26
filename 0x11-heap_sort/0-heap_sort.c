#include "sort.h"

/**
 * sort - sort heap
 * @array: array
 * @size: size of array
 * @num: number
 * @finalSize: final size of the array
 * Return: nothing
 */
void sort(int *array, int size, int num, int finalSize)
{
	int left, right, switchNum;
    int numTwo = num;

	left = num * 2 + 1;
	right = num * 2 + 2;

	if (left < size && array[left] > array[numTwo])
    {
		numTwo = left;
    }
	if (right < size && array[right] > array[numTwo])
    {
		numTwo = right;
    }
	if (numTwo != num)
	{
		switchNum = array[numTwo];
		array[numTwo] = array[num];
		array[num] = switchNum;
		print_array(array, finalSize);
		heapify(array, size, numTwo, finalSize);
	}
}


/**
 * heap_sort - algo
 * @array: array
 * @size: size
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
    int switchNum;
	int num;

    checkOne = num = size / 2 - 1;
    checkTwo = num = size - 1;
	for (checkOne; num >= 0; num--)
    {
		sort(array, size, num, size);
    }
	for (checkTwo; num > 0; num--)
	{
		if (array[0] >= array[num])
		{
			switchNum = array[0];
			array[0] = array[num];
			array[num] = switchNum;
			print_array(array, size);
		}
		sort(array, num, 0, size);
	}
}
