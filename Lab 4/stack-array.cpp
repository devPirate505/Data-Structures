#include <iostream>
using namespace std;

class Stack{
    private:
        int * arr;
        int size;
        int length;
        int top;
        public:
            Stack(int size){
                this->size = size;
                arr = new int [size];
                top = -1;
            }

            ~Stack(){
                delete []arr;
            }
            void push(int val){
                if(top == size-1){
                    cout << " Stack oveflow" << endl;
                    return;
                }
                arr[++top] = val;
            }
            int pop(){
                if(top == -1){
                    cout << " Stack underflow" << endl;
                    return 0;
                }
                else{
                    return arr[top--];
                }
            }
            int peek(){
                if(top == -1){
                    cout<< " Stack Under flow" << endl;
                    return 0;
                }
                else{
                    return arr[top];
                }
            }
            void display(){
                for(int i = top; i >= 0 ; i--){
                    cout << "Item: " << i+1<<" : " << arr[i] << endl;
                }
            }
};

int main(){
    Stack stack1(5);
    stack1.push(1);
    stack1.push(2);
    stack1.push(3);
    stack1.push(4);
    stack1.push(5);
    cout << stack1.pop() << endl;
    stack1.display();
}