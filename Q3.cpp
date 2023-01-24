#include <iostream>
using namespace std;

class node{
	public:
		int id;
		string pState;
		int time;
};

class queue {
    private:
        node *arr;
        int size;
        int rear, front;
        int noOfElements;
        public:
            queue(int size){
                this->size = size;
                arr = new node[size];
                rear = -1, front = -1, noOfElements = 0;
            }
            ~queue(){
                delete []arr;
            }
            void enqueue(node val){
                if(rear == size-1){
                    cout << " Stack overflow" << endl;
                    return;
                }
                if(front == -1){
                    front = 0;
                }
                arr[++rear].id = val.id;
                arr[++rear].pState = val.pState;
                arr[++rear].time = val.time;
                noOfElements++;
            }
            void print(){
                if(front == -1){
                    cout << " Queue is empty" << endl;
                }
                else{
                    cout << "Processing...\n";
                    for(int i = front; i<=rear; i++ ){
                        cout << arr->id << "completed in " << arr->time << "s and state is: " << arr->pState;
                    }
                    cout << endl;
                }
                

            }
};
int main(){
	int x;
	do{
		cout << "Enter Queue Size: ";
		cin >> x;
		queue *q;
		for(int i = 0; i < x; i++){
			cout << "Enter process Id, process state and time: \n";
			node n;
			cin >> n.id;
			cin >> n.pState;
			cin >> n.time;
//			q->enqueue(n);
			q->print();
			
		}
	}while(x != -1);
    return 0;
}
