#include <algorithm>
#include <iostream>
using namespace std;

int H[50];
int heapSize = -1;

int leftChild(int i)
{
    return (2 * i) + 1;
}

int rightChild(int i)
{
    return (2 * i) + 2;
}

void shiftDown(int i)
{
    int maxIndex = i;
    int l = leftChild(i);

    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }

    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }

    if (i != maxIndex) {
        swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

int extractMax()
{
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

int main()
{
    return 0;
}