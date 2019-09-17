#include "a1.h"
#include <stdio.h>
#include <stdlib.h>
int n;
char *memory;
void allocate(int x){
	memory = (char *)malloc(sizeof(char) *  x);
	*(memory) = '0';
	*(int *)(memory + 1) =  x - 5;
	n =  x;
}
void* mymalloc(int size){
	char * current = memory;
	char * minimum = NULL;
	char *position = NULL;
	int rem_mem;
	int count = 0;
	int min = n ;
	while(current - memory < n){
        if(*(current) == '0' && (*(int *)(current + 1) - size) < min && (*(int *)(current + 1) > size + 6)){
        	min = *(int *)(current + 1);
        	minimum = current;
        }
        current = current + *(int *)(current + 1) + 5;
	}
	if((minimum != NULL) && (*(int *)(minimum + 1) > size + 6))//check if minimum block has size greater than our user requested
	    {
		rem_mem = *(int *)(minimum + 1) - size - 5;
		position = minimum;
		*(minimum) = '1';
		*(int *)(minimum + 1) = size;
        minimum = minimum + *(int *)(minimum + 1) + 5;
        *(minimum) = '0';
        *(int *)(minimum + 1) = rem_mem;
        return (void *)(position + 5);
		}
    else {
		printf("memory block not found\n");
		return (void *)NULL;
		}
}
void myfree(void *p){
	*(char *)(p - 5) = '0';
	int count = 0;
	int size = 0;
	char *ptr1 = memory;
	char *ptr2 = NULL;
	char * current = memory;
	while( ptr1 - memory < n){
        if(*(ptr1) == '0'){
        	size = *(int *)(ptr1 + 1);
        	ptr2 = ptr1 + (*(int *)(ptr1 + 1)) + 5;
            if(ptr2 - memory >= n){
            	break;// if ptr2 goes out of the our memory break the loop
            }
        	else
        	{
        	    while(*(ptr2) == '0'){
        		size += *(int *)(ptr2 + 1) + 5;
        		ptr2 = ptr2 + (*(int *)(ptr2 + 1)) + 5;
        		if(ptr2 - memory >= n){
        			break;//if our free block goes out of the memory i have to break the loop
        		   }
        	    }
	        }
        	*(int *)(ptr1 + 1) = size; 
        }
        ptr1 = ptr1 + *(int *)(ptr1 + 1) + 5;
	}
}
void print_book(){
	printf("%d\n",5);
	printf("%d\n",5);
}
void display_mem_map(){
	int count = 0;
	char * current = memory;
	char *book = memory;
	char* temp = NULL;
	int index = 0;
	while(count < n){
		temp = current + 5;
		count += 5;
		count += *(int *)(current + 1);
		printf("%d %d book\n",index,5);
		if(*current == '0')
			printf("%d %d free\n",index+5,*(int *)(current + 1));
		else 
			printf("%d %d allocated\n",index+5,*(int *)(current + 1));

        index += 5 + *(int *)(current + 1);
 		current = current + *(int *)(current + 1) + 5;
	}
}
void free_memory(char * memory){
	free(memory);
}