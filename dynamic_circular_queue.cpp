/*
Based on the Circular Queue implementation on Geeks for Geeks by Akash Gupta

found here:
https://www.geeksforgeeks.org/circular-queue-set-1-introduction-array-implementation/
*/

/* C or C++ program for insertion and deletion in Dynamic Circular Queue */
#include<iostream>
using namespace std;
 
struct Queue
{
    // Values:
    int rear, front, occup, size;
    // Constants:
    int beta;
    double alpha;
    // Pointers:
    int *arr;
    int *arr2;
 
    Queue(int s)
    {
       front = rear = -1;
       occup = 0;
       size = s;
       arr = new int[s];
       beta = 4;
       alpha = (beta + 1.0)/2.0
    }
 
    void push(int value);
    int pull();
    void displayQueue();
};
 
// Function to add an element to the queue
void Queue::push(int value)
{
    if (front == 0 && rear == size-1)
    {
        printf("\nQueue is Full");
        arr2 = new int[(int)size*alpha];

        for (int i = front; i <= rear; ++i)
        {
            arr2[i] = arr[i];
        }
        
        rear++;
        arr2[rear] = value;
        size = (int)size*alpha;

        delete[] arr;
        arr = arr2;
    }

    else if (rear == front-1)
    {
        printf("\nQueue is Full");
        arr2 = new int[(int)size*alpha];

        for (int i = 0; i < size-front; ++i)
        {
            arr2[i] = arr[i+front];
        }
        for (int i = 0; i <= front; ++i)
        {
            arr2[size-front+i] = arr[i];   
        }

        front = 0;
        rear = occup;
        arr2[rear] = value;
        size = (int)size*alpha;
        
        delete[] arr;
        arr = arr2;
    }
 
    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }
 
    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }
 
    else
    {
        rear++;
        arr[rear] = value;
    }

    occup++;
}
 
// Function to delete element from Queue
int Queue::pull()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return INT_MIN;
    }
 
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    occup--;

    // Check if there is a lot of empty space
    if (occup*beta <= size)
    {
        arr2 = new int[occup*alpha];

        if (front <= rear)
        {
            for (int i = 0; i <= rear - front; ++i)
            {
                arr2[i] = arr[front + i];
            }
            rear = rear - front;
            front = 0;
        }
        else
        {
            for (int i = front; i < size; ++i)
            {
                arr2[i-front] = arr[i];
            }
            int start = size - front;
            for (int i = 0; i <=rear; ++i)
            {
                arr2[start + i] = arr[i];
            }
            rear = occup - 1;
            front = 0;
        }
        delete[] arr;
        arr = arr2;
        size = occup*alpha;
    }
 
    return data;
}
 
// Function displaying the elements of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        printf("\nQueue is Empty");
        return;
    }
    printf("\nElements in Circular Queue are: ");
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            printf("%d ",arr[i]);
    }
    else
    {
        for (int i = front; i < size; i++)
            printf("%d ", arr[i]);
 
        for (int i = 0; i <= rear; i++)
            printf("%d ", arr[i]);
    }
}