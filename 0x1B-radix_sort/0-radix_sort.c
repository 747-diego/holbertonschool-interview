#include "sort.h"


/**
 * sortINradixForm - Task 0. Redix sort
 * @intList: array to sort
 * @length: size of array
 * @sigDigit: significant digit to increase
 */
void sortINradixForm(int *intList, size_t length, size_t sigDigit)
{
	size_t moduloIndex, tempNode = 0, nodeIndex = 0, sigDigits[10] = {0};
	int moduloTemp, currentIndex, nodeToken, *nodesINmemory[10], divi = sigDigit / 10;

	while (tempNode < length)
	{
		moduloTemp = intList[tempNode] % sigDigit;
		currentIndex = (moduloTemp) / (divi);
		sigDigits[currentIndex] = sigDigits[currentIndex] + 1;
		tempNode++;
	}
	if (sigDigits[0] == length)
	{
		return;
	}
	tempNode = 0; while (tempNode < 10)
	{
		nodesINmemory[tempNode] = malloc(sigDigits[tempNode] * sizeof(int));
		tempNode++;
	}
	tempNode = 0; while (tempNode < 10)
	{
		nodeToken = 0;
		nodeIndex = 0;
		while (nodeIndex < length)
		{
			moduloIndex = intList[nodeIndex] % sigDigit;
			if (((moduloIndex) / (divi)) == tempNode)
			{
				nodesINmemory[tempNode][nodeToken] = intList[nodeIndex];
				nodeToken++;
			}
		nodeIndex++;
		}
	tempNode++;
	}
	nodeToken = 0;
	tempNode = 0;
	while (tempNode < 10)
	{
		nodeIndex = 0;
		while (nodeIndex < sigDigits[tempNode])
		{
			intList[nodeToken] = nodesINmemory[tempNode][nodeIndex];
			nodeToken++;
			nodeIndex++;
		}
		tempNode++;
	}
	print_array((const int *)intList, length);
	tempNode = 0;
	while (tempNode < 10)
	{
		free(nodesINmemory[tempNode]);
		tempNode++;
	}
	sortINradixForm(intList, length, sigDigit * 10);
}

/**
 * radix_sort - TASK 0. Redix sort
 * @array: only integers greater than zero
 * @size: length of array
 */
void radix_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	if (array == NULL)
	{
		return;
	}
	sortINradixForm(array, size, 10);
}
