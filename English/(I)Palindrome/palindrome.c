 /** 
  * Problem: 
  * http://www.spoj.com/problems/PALIN/ 
  */
 
 #include <stdio.h>

/* STACK */

typedef struct {
  stackElementT *contents;
  int top;
  int maxSize;
} stackT;

void StackInit(stackT *stackP, int maxSize)
{
  stackElementT *newContents;

  /* Allocate a new array to hold the contents. */

  newContents = (stackElementT *)malloc(sizeof(stackElementT)
                                        * maxSize);

  stackP->contents = newContents;
  stackP->maxSize = maxSize;
  stackP->top = -1;  
}

void StackDestroy(stackT *stackP){
  /* Get rid of array. */
  free(stackP->contents);

  stackP->contents = NULL;
  stackP->maxSize = 0;
  stackP->top = -1;  /* I.e., empty */
}

int StackIsEmpty(stackT *stackP)
{
  return stackP->top < 0;
}

int StackIsFull(stackT *stackP)
{
  return stackP->top >= stackP->maxSize - 1;
}

void StackPush(stackT *stackP, stackElementT element)
{
  if (StackIsFull(stackP)) {
    fprintf(stderr, "Can't push element on stack: stack is full.\n");
    exit(1);  /* Exit, returning error code. */
  }

  stackP->contents[++stackP->top] = element;
}

stackElementT StackPop(stackT *stackP)
{
  if (StackIsEmpty(stackP)) {
    fprintf(stderr, "Can't pop element from stack: stack is empty.\n");
    exit(1);  /* Exit, returning error code. */
  }

  return stackP->contents[stackP->top--];
}



/* http://www.spoj.com/problems/PALIN/ */

int main() {
	
	int i;
	int input = 0;
	
	scanf("%d", &t);
	for (i=1; i<=t;i++){
		scanf("%d", &t);
	}
	
	scanf("%d", &input);
	while (input != 42) {
		printf("%d\n", input);
		scanf("%d", &input);
	}
	
	return 0;
}

int is_palindrome(long int x) {
    int number_cases = decimal_digits(x);
}

int decimal_digits(long int x) {
	int counter = 0;
	while (x > 0) {
		x = x/10;
		counter++;
	}
	return counter;
}
