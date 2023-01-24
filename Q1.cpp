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
                    arr[front] = val;
                    noOfElements++;
                    rear = noOfElements-1;
                }else{
                	
                arr[++rear] = val;
                noOfElements++;
                
                
                queue q(noOfElements);
                q.front = 0;
				q.rear = noOfElements-1;
                for(int i = front; i <= rear; i++){
                    q.arr[q.rear] =  arr[i];
					q.rear--;  
                }
                q.rear = noOfElements;
                q.print();
                front = 0;

              for(int i = front; i <= rear; i++){
                    arr[i] = q.arr[i];
                }
                
                rear = noOfElements-1;
			}
                
                
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
            bool IsEmpty(){
            	if(noOfElements == 0){
            		return true;
				}else{
					return false;
				}
			}
			
			bool IsFull(){
            	if(noOfElements == size){
            		return true;
				}else{
					return false;
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
	int size = 5;
    queue q1(size), q2(size);
    q1.enqueue(3);
    q1.enqueue(2);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.print();
    
    return 0;
}
