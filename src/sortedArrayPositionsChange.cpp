/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j, k, l, k1, l1, t,c=0;
	if (Arr == NULL)   return NULL;
	if (len < 0) return NULL;
	for (i = 0; i < len; i++)
	{
		if (Arr[i] < Arr[i + 1])
			c++;
	}
	if (c == len - 1) return Arr;
	for (i = 0; i<len; i++)
	{
		if (Arr[i]>Arr[i + 1])
			k = i;
		else
			continue;
		for (j = len - 1; j >= 0; j--)
		{
			if (Arr[j]<Arr[j - 1])
			{
				l = j;
				break;
			}
			else
				continue;
		}
		break;
	}
	k1 = Arr[k];
	Arr[k] = Arr[l];
	Arr[l] = k1;
	return Arr;
}