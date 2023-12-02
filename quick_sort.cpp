
#include <iostream>

using namespace std;

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void three_sort(int *a, int left,int  mid,int right)
{
	if (a[left] > a[right])
	{
		swap(a + left, a + right);
	}
	if (a[left] > a[mid])
	{
		swap(a + left, a + mid);
	}
	if (a[mid] > a[right])
	{
		swap(a + mid, a + right);
	}
}

void quicksort(int *a,int left,int right)
{
	if (right==left)
	{
		return;
	}
	if (right - left == 1)
	{
		if (a[left] > a[right])
		{
			swap(a + left, a + right);
		}
		return;
	}
	if (right - left == 2)
	{
		three_sort(a, left, left + 1, right);
		return;
	}
	int mid = (left + right)/2;
	three_sort(a,left,mid,right);
	swap(a+mid, a+right);
	int i = left;
	int j = right-1;
	while (1)
	{
		while (a[i] < a[right])
		{
			i++;
		}
		while (a[j] > a[right])
		{
			j--;
		}
		if (i > j)
		{
			break;
		}
		if (a[i] > a[right] && a[j] < a[right])
		{
			swap(a + i, a + j);
		}
	}
	mid = i;
	swap(a + mid, a + right);
	quicksort(a, left, mid-1);
	quicksort(a, mid + 1, right);
}

int main()
{
	const int n = 12;
	int a[n] = {3,6,5,11,7,10,4,9,8,12,14,2};
	cout << "Ô­Ê¼£º";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << '\n';
	quicksort(a,0,n-1);
	cout << "ÅÅÐòºó£º";
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}