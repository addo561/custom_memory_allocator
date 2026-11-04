# custom_memory_allocator

Implementations of both Arena and Pool allocator.

## Arena allocator

A simpler version of a memory allocator that requests a block of memory from the OS.

A single pointer keeps track of where the free space starts. The pointer moves forward each time you ask for memory. The catch: you can't free individual items.

## Pool allocator

Requests a block of memory and divides it into fixed-size chunks. Memory can be freed by the user individually.

## Try it

Clone the repo:

```bash
git clone https://github.com/addo561/custom_memory_allocator.git
cd custom_memory_allocator
```

### Arena allocator (`main.cpp`)

Build the binary:

```bash
g++ -o arena main.cpp
```

Run it:

```bash
./arena <size_in_bytes> <bytes>
```

Example:

```bash
./arena 100 10
```

### Pool allocator (`pool_allocator.cpp`)

Build the binary:

```bash
g++ -o pool pool_allocator.cpp
```

Run it:

```bash
./pool <block_size> <total_size>
```

Example:

```bash
./pool 64 1024
```
