# Memory-manager
Memory manager with first,best,worst fit
Allocation policy implemeted - Best fit

Bookkeeping - my implementation takes five bytes for bookkeeping.It has two fields.First field is to indicate whether given block is free or not and second field indicates the size of block.First field is of char type and second field is of int type so char and int both takes 5 bytes.

managing bookkeeping:In each block we have 5 bytes of bookkeeping.In free function if i have any adjacent free blocks i will combine those two free blocks to single free block using two pointers ptr1 and ptr2.

if user request for more memory than whatever the remaining memory block,then our allocator prints "memory block not found".
Two if conditions inside main while loop of free function is to check our ptr2 is not going beyond our memory.If those if conditions are not present then ptr2 becomes dangling pointer and we are dereferencing dangling pointer inside inner for loop which is dangerous.I

compilation - gcc client.c 0949_A1.c a1.h
