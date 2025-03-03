#include <stdio.h>

#define MAX 100

typedef struct
{
    int items[MAX];
    int size;
} PriorityQueue;

// Define swap function to swap two integers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(PriorityQueue* pq, int index)
{
    if (index && pq->items[index] < pq->items[(index - 1) / 2])
    {
        swap(&pq->items[index], &pq->items[(index - 1) / 2]);
        heapify_up(pq, (index - 1) / 2);
    }
}

void enqueue(PriorityQueue* pq, int item)
{
    if (pq->size == MAX)
    {
        printf("Queue is full\n");
        return;
    }

    pq->items[pq->size++] = item;
    heapify_up(pq, pq->size - 1);
}

void heapify_down(PriorityQueue* pq, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->items[left] < pq->items[smallest])
        smallest = left;

    if (right < pq->size && pq->items[right] < pq->items[smallest])
        smallest = right;

    if (smallest != index)
    {
        swap(&pq->items[index], &pq->items[smallest]);
        heapify_down(pq, smallest);
    }
}

int dequeue(PriorityQueue* pq)
{
    if (!pq->size)
    {
        printf("Priority queue is empty\n");
        return -1;
    }

    int item = pq->items[0];
    pq->items[0] = pq->items[--pq->size];
    heapify_down(pq, 0);
    return item;
}

// This function assumes start times are sorted in ascending order with their corresponding end times
int interval_partitioning(int* start, int* end, int n)
{
    PriorityQueue pq = { { 0 }, 0 };

    for (int i = 0; i < n; ++i)
    {
        if (pq.size && pq.items[0] <= start[i])
            dequeue(&pq);

        enqueue(&pq, end[i]);
    }

    return pq.size;
}

int main()
{
    int start[] = { 1, 3, 0, 5, 8, 5 };
    int end[] = { 2, 4, 6, 7, 9, 9 };
    int n = sizeof(start) / sizeof(start[0]);

    printf("Minimum number of rooms required: %d\n", interval_partitioning(start, end, n));

    return 0;
}