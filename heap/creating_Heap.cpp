#include <bits/stdc++.h>
using namespace std;
class heap
{
public:
    int arr[100];
    int size;
    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int i = size;
        arr[i] = val;
        while (i > 1)
        {
            int parent = i / 2;
            if (arr[parent] < arr[i])
            {
                swap(arr[parent], arr[i]);
                i = parent;
            }
            else
            {
                return;
            }
        }
    }
    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "No element present in the heap " << endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;
            if (leftChild < size && arr[i] < arr[leftChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (rightChild < size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
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
    }
};
int main()
{
    heap h;
    h.insert(50);
    h.insert(52);
    h.insert(60);
    h.insert(55);
    h.insert(40);
    h.insert(10);
    h.print();
    cout << endl
         << "After Deleting " << endl;
    h.deleteFromHeap();
    h.print();
}