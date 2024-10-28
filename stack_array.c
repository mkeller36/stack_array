#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxStackLength 256
#define EMPTY -1
#define E_OK 1

typedef struct {
  int values[maxStackLength];   /*Array holding the stack*/
  int count;                    /*Index of head*/
} stack;

int push(stack *myStack, int x);
int pop(stack *myStack);

int push(stack *myStack, int x) {
  if(myStack->count == maxStackLength){
    fprintf(stderr,"ERROR: The stack is full\n");
    return -1;
  }
  myStack->values[myStack->count] = x;
  myStack->count++;
  return E_OK;
}

int pop(stack *myStack) {
  if(myStack->count == 0){
    fprintf(stderr, "Stack is empty\n");
    return -1;
  }

  int out = myStack->values[myStack->count - 1];
  myStack->count--;
  return out;
}

int main(int argc, char* argv[]) {
  stack s1, s2;
  s1.count = EMPTY;
  s2.count = EMPTY;
  push(&s1, 1);
  push(&s1, 2);
  push(&s1, 3);
  push(&s2, 5);
  
  int numElements = 4;
  for(int i = 0; i < numElements; i++){
    printf("%d \n", pop(&s1));
  }
  
  return 0;
}