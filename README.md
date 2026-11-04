# custom_memory_allocator
implementations of both Arena and Pool allocator

## Arena allocator
Simpler version of memory allocator requesting block of memory from OS.

You have a simple pointer keeping track of the free space starts.
Pointer is moved forward when you ask for memory also(catch) you can't free individual items.

## Pool allocator
Request a block of memory and divide  it  into chunks.
memory can be freed by users individually.
