#ifndef HEADER_FILE
#define HEADER_FILE

#define _GNU_SOURCE
#include <stdlib.h> /* exit,  */
#include <stdio.h>  /* io functions */
#include <unistd.h> /* write */
#include <string.h> /* String functions */



/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/* === === === functions === === === */
void checkAndOpenFile(int argc, char *fileName, FILE **file);
void parseAndProcess(char *buff, stack_t **stack, unsigned int line_number);
void (*handle_opcodes(char *func))(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void push(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void sub(stack_t **stack, unsigned int line_no);
void mul(stack_t **stack, unsigned int line_no);
void mod(stack_t **stack, unsigned int line_no);
void division(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pchar(stack_t **stack, unsigned int line_no);
void pstr(stack_t **stack, unsigned int line_no);
void rotl(stack_t **stack, unsigned int line_no);
void rotr(stack_t **stack, unsigned int line_no);
int popFirst(stack_t **h);
void printList(stack_t **h);
void freeStack(stack_t **h);
void appendToList(stack_t **h, int num);
int check_for_digit(char *arg);
void delete_end_node(stack_t **h);

#endif
