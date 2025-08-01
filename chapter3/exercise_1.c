#include <stdio.h>

#define SIZE 10

int binsearch(int x, int v[], int n);
int short_binsearch(int x, int v[], int n);

int main()
{
    int v[SIZE];
    int i, x;

    for (i = 0; i < SIZE; ++i)
    {
        v[i] = i+1;
    }
    
    printf("Enter num to find: ");
    scanf("%d", &x);
    printf("binsearch: %d\n", binsearch(x, v, SIZE));
    printf("short_binsearch: %d", short_binsearch(x, v, SIZE));

    return 0;
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;
	
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		mid = (low+high) / 2;

		if (x < v[mid])
		{
			high = mid - 1;
		}
		else if (x > v[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
	}

	return -1;
}

int short_binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high)
    {
        mid = (low + high) / 2;

        if (x <= v[mid])
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return (v[low] == x) ? low : -1;
}
