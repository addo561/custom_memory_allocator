# custom_memory_allocator
implementations of both Arena and Pool allocator

## Arena allocator
Simpler version of memory allocator requesting block of memory from OS .
You have a simple pointer keeping track of where the free  space starts
pointer is moved forward when you ask for memory also(catch) you can't free individual items.


