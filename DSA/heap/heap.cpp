// max heap
#include <bits/stdc++.h>
using namespace std;
class Heap
{
public:
    int arr[100];
    int size = 0;

    Heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void deletefromheap()
    {
        if (size == 0)
        {
            cout << " nothing to delete";
            return;
        }
        // step1:put last element into 1st element
        arr[1] = arr[size];
        // step2:remove last element
        size--;
        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int left_index = 2 * i;
            int right_index = 2 * i + 1;
            if (left_index < size && arr[i] < arr[left_index])
            {
                swap(arr[i], arr[left_index]);
                i = left_index;
            }
            else if (right_index < size && arr[i] < arr[right_index])
            {
                swap(arr[i], arr[right_index]);
                i = right_index;
            }
            else
            {
                return;
            }
        }
    }
};
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n;
    while (size > 1)
    {
        // step1:swap
        swap(arr[size], arr[1]);
        size--;
        heapify(arr, size, 1);
    }
}
int main()
{
    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromheap();
    h.print();
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    heapsort(arr, 5);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}