#include <iostream>
using namespace std;

const int MAX_SIZE = 100001;
int heap[MAX_SIZE];
int heapSize = 0;

void pushHeap(int x) {
    heap[++heapSize] = x;
    int i = heapSize;

    while(i > 1 && heap[i/2] > heap[i]){
        int temp = heap[i];
        heap[i] = heap[i/2];
        heap[i/2] = temp;
        i /= 2;
    }
}

int popHeap() {
    if (heapSize == 0) return 0;
    int result = heap[1]; 
    heap[1] = heap[heapSize--];
    int i = 1;
    
    while(true)
    {
        int smallest = i;
        int left = i * 2;
        int right = (i * 2) + 1;
        
        if(left <= heapSize && heap[left] < heap[smallest])
        {
            smallest = left;
        }
        if(right <= heapSize && heap[right] < heap[smallest])
        {
            smallest = right;
        }
        if(smallest == i)
        {
            break;
        }
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        i = smallest;
    }
    return result;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    while (N--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << popHeap() << '\n';
        } else {
            pushHeap(x);
        }
    }
    
    return 0;
}
