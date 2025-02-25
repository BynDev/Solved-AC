#include <iostream>
using namespace std;

const int MAX_SIZE = 100001;  // 문제 제한에 따라 최대 연산 수

int heap[MAX_SIZE];
int heapSize = 0;

// 절댓값 비교 함수: 
// 만약 절댓값이 같다면 실제 값이 작은 것을 우선시한다.
bool compare(int a, int b) {
    int absA = (a < 0 ? -a : a);
    int absB = (b < 0 ? -b : b);
    if (absA == absB) return a < b;
    return absA < absB;
}

// 힙에 값 x를 삽입하는 함수
void push(int x) {
    heap[++heapSize] = x;
    int cur = heapSize;
    // 부모 노드와 비교하며 위로 올라간다.
    while (cur > 1) {
        int parent = cur / 2;
        if (compare(heap[cur], heap[parent])) {
            int temp = heap[cur];
            heap[cur] = heap[parent];
            heap[parent] = temp;
            cur = parent;
        } else {
            break;
        }
    }
}

int pop() {
    if (heapSize == 0) return 0;
    int ret = heap[1];
    heap[1] = heap[heapSize--];
    int cur = 1;
    while (cur * 2 <= heapSize) {
        int child = cur * 2;
      
        if (child + 1 <= heapSize && compare(heap[child + 1], heap[child])) {
            child++;
        }
        if (compare(heap[child], heap[cur])) {
            int temp = heap[child];
            heap[child] = heap[cur];
            heap[cur] = temp;
            cur = child;
        } else {
            break;
        }
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    while(N--) {
        int x;
        cin >> x;
        if (x == 0) {
            cout << pop() << "\n";
        } else {
            push(x);
        }
    }
    return 0;
}
