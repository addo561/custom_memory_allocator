#include <iostream>

class ArenaAllocator{
private:
    size_t total_size; // size to  hand out
    char* start_ptr; // stating pointer
    size_t offset; // keep track of starting  memory for  handouts
public:
    ArenaAllocator(size_t s) {
        total_size =  s;
        offset = 0;
        start_ptr = new char[total_size]; // allocate a block(Array) of bytes
    }
    ~ArenaAllocator() {
        std::cout << "memory released\n";
        delete[] start_ptr;
    }
    void* allocator(size_t bytes) {
        //take number of bytes user wants and return pointer  to start  of that block
        //returns a void*(generic pointer) that can be cast to any type
        //1. check for space
        if (bytes < total_size - offset) {
            // 2. calculate  pointer to give
            auto pos = start_ptr + offset;
            // 3. update offset
            offset += bytes;
            // 4. return address
            return pos;

        }
        std::cout << "memory allocated\n";
        return nullptr;

    }
};
int main(int argc,char* argv[]) {
    int arg1  = std::stoi(argv[1]);
    ArenaAllocator alloc(arg1);
    auto ptr = alloc.allocator(4);
    int* my_ptr = static_cast<int*>(ptr);
    *my_ptr = 3;
    std::cout<<my_ptr;
    return 0;
}