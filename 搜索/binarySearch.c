#include <stdio.h>
#define MAX 1005

int find(int a[], int low, int high, int x)
{
    int mid = (low + high) / 2;
    //printf("%d %d\n", low, high);
    if (low > high)
        return -1;
    if (a[mid] == x)
        return mid;
    else if (a[low] == x)
        return low;
    else if (a[high] == x)
        return high;
    else if (a[mid] > x)
        return find(a, low, mid - 1, x);
    else
        return find(a, mid + 1, high, x);
}

int binarySearch(int A[], int target, int n)
{
    int low = 0, high = n, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (A[mid] == target)
        {
            return mid;
        }
        else if (A[mid] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}