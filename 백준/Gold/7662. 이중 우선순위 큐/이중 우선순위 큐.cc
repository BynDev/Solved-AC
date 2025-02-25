#include <iostream>
using namespace std;

struct Node {
    int value; 
    int id;   
};

const int MAX_OP = 1000001; 
Node minHeap[MAX_OP]; 
Node maxHeap[MAX_OP]; 
bool visited[MAX_OP]; 

int minHeapSize = 0, maxHeapSize = 0;

void swapNode(Node &a, Node &b) {
    Node temp = a;
    a = b;
    b = temp;
}

void pushMin(Node node) {
    minHeap[++minHeapSize] = node;
    int cur = minHeapSize;
    while (cur > 1) {
        int parent = cur / 2;
        if (minHeap[cur].value < minHeap[parent].value ||
            (minHeap[cur].value == minHeap[parent].value && minHeap[cur].id < minHeap[parent].id)) {
            swapNode(minHeap[cur], minHeap[parent]);
            cur = parent;
        } else break;
    }
}

void pushMax(Node node) {
    maxHeap[++maxHeapSize] = node;
    int cur = maxHeapSize;
    while (cur > 1) {
        int parent = cur / 2;
        if (maxHeap[cur].value > maxHeap[parent].value ||
            (maxHeap[cur].value == maxHeap[parent].value && maxHeap[cur].id < maxHeap[parent].id)) {
            swapNode(maxHeap[cur], maxHeap[parent]);
            cur = parent;
        } else break;
    }
}

Node popMin() {
    Node ret = minHeap[1];
    minHeap[1] = minHeap[minHeapSize--];
    int cur = 1;
    while (cur * 2 <= minHeapSize) {
        int child = cur * 2;
        if (child + 1 <= minHeapSize &&
            (minHeap[child+1].value < minHeap[child].value ||
             (minHeap[child+1].value == minHeap[child].value && minHeap[child+1].id < minHeap[child].id))) {
            child++;
        }
        if (minHeap[child].value < minHeap[cur].value ||
            (minHeap[child].value == minHeap[cur].value && minHeap[child].id < minHeap[cur].id)) {
            swapNode(minHeap[child], minHeap[cur]);
            cur = child;
        } else break;
    }
    return ret;
}

Node popMax() {
    Node ret = maxHeap[1];
    maxHeap[1] = maxHeap[maxHeapSize--];
    int cur = 1;
    while (cur * 2 <= maxHeapSize) {
        int child = cur * 2;
        if (child + 1 <= maxHeapSize &&
            (maxHeap[child+1].value > maxHeap[child].value ||
             (maxHeap[child+1].value == maxHeap[child].value && maxHeap[child+1].id < maxHeap[child].id))) {
            child++;
        }
        if (maxHeap[child].value > maxHeap[cur].value ||
            (maxHeap[child].value == maxHeap[cur].value && maxHeap[child].id < maxHeap[cur].id)) {
            swapNode(maxHeap[child], maxHeap[cur]);
            cur = child;
        } else break;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        minHeapSize = 0;
        maxHeapSize = 0;
        for (int i = 0; i < k + 1; i++) {
            visited[i] = false;
        }
        
        int idCounter = 0; 
        for (int i = 0; i < k; i++) {
            char op;
            int num;
            cin >> op >> num;
            if (op == 'I') { 
                idCounter++;
                Node newNode;
                newNode.value = num;
                newNode.id = idCounter;
                pushMin(newNode);
                pushMax(newNode);
                visited[idCounter] = true;
            } else if (op == 'D') { 
                if (num == 1) { 
                    while (maxHeapSize > 0 && !visited[maxHeap[1].id])
                        popMax();
                    if (maxHeapSize > 0) {
                        Node delNode = popMax();
                        visited[delNode.id] = false;
                    }
                } else if (num == -1) { 
                    while (minHeapSize > 0 && !visited[minHeap[1].id])
                        popMin();
                    if (minHeapSize > 0) {
                        Node delNode = popMin();
                        visited[delNode.id] = false;
                    }
                }
            }
        }
        
        while (minHeapSize > 0 && !visited[minHeap[1].id])
            popMin();
        while (maxHeapSize > 0 && !visited[maxHeap[1].id])
            popMax();
        
        if (minHeapSize == 0 || maxHeapSize == 0)
            cout << "EMPTY" << "\n";
        else
            cout << maxHeap[1].value << " " << minHeap[1].value << "\n";
    }
    
    return 0;
}