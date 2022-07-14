#include<iostream>
using namespace std;

struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

struct ArrayStack *CreateStack(){
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));

    if(!S){
        return null;
    }
    S->capacity = 1;
    s->top = -1;
    S->array = malloc(S->capacity * sizeof(int));

    if(!S->array){
        return null;
    }
    return S;
}

int IsEmptyStack(struct ArrayStack *S){
    return (S->top == -1);
}
int IsFullStack(struct ArrayStack *S){
    return (S->top == S->capacity - 1);
}
void Push(struct ArrayStack *S,int data){
    if(isFullStack(S)){
        cout << "Stack Overflow" << endl;
    }
    else{
        S->array[++S->top] = data;
    }
}
int Pop(struct ArrayStack *S){
    if(IsEmptyStack(S)){
        cout << "Stack is empty" << endl;
        return 0;
    }
    else{
        return (S->array[S->top--]);
    }
}

void DeleteStack(struct DynArrayStack *S){
    if(S){
        if(S->array){
            free(S->array);
        }
        free(S);
    }
}

int main(){

}