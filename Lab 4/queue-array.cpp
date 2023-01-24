#include <iostream>
using namespace std;

class queue {
    private:
        int *arr;
        int size;
        int rear, front;
        int noOfElements;
        public:
            queue(int size){
                this->size = size;
                arr = new int[size];
                rear = -1, front = -1, noOfElements = 0;
            }
            ~queue(){
                delete []arr;
            }
            void enqueue(int val){
                if(rear == size-1){
                    cout << " Stack overflow" << endl;
                    return;
                }
                if(front == -1){
                    front = 0;
                }
                arr[++rear] = val;
                noOfElements++;
            }
            int dequeue(){
                if(front == -1){
                    cout <<"Queue Underflow";
                    return -1;
                }
                else{
                    cout << "Element deleted from queue is: " << arr[front] << endl;
                    return arr[front++];
                }
            }
            void print(){
                if(front == -1){
                    cout << " Queue is empty" << endl;
                }
                else{
                    cout << "Queue elements are: ";
                    for(int i = front; i<=rear; i++ ){
                        cout << arr[i] << " ";
                    }
                    cout << endl;
                }
                

            }
};
int main(){
    queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.print();
    q1.dequeue();
    q1.print();
    return 0;
}
