//
// Created by Larry on 11/4/26.
//
#include <iostream>

class PoolAllocator {
private:
    struct FreeNode {
        FreeNode* next;
    };

    size_t total_size;
    size_t block_size;
    char* start_ptr;
    FreeNode* head; // first available block

public:
    PoolAllocator(size_t block,size_t total) {
        total_size =  total;
        block_size = block;
        start_ptr = new char[total_size];
        // memory address at i-th block
        for (size_t i = 0; i<(total_size/block_size)-1;++i) {
            //  get  current block and next  block as  freenode
            FreeNode* curr = reinterpret_cast<FreeNode*>(start_ptr + i * block_size);
            FreeNode* next_node = reinterpret_cast<FreeNode*>(start_ptr + (i+1) * block_size);

            //link them
            curr->next = next_node;
        }
        // set  last index to nullptr
        size_t last_index = (total_size/block_size)-1;
        FreeNode* last_node = reinterpret_cast<FreeNode*>(start_ptr + last_index * block_size);
        last_node->next = nullptr;
        //set to  very  first  block of newly created list
        head = reinterpret_cast<FreeNode*>(start_ptr);
    }
    void* allocate() {
        if (head == nullptr) {
            return nullptr;
        }
        // block to handout
        FreeNode* block_return = head;
        //update head
        head= head->next;
        return reinterpret_cast<void*>(block_return);
    }
    void dellocate(void* ptr) {
        FreeNode* to_free = reinterpret_cast<FreeNode*>(ptr);
        to_free->next = head;
        head = to_free;
        std::cout<< "done\n";

    }

};

int main() {
    PoolAllocator alloc(32,1024);
    void* ptr = alloc.allocate();
    int* my_ptr = static_cast<int*>(ptr);
    if (my_ptr==nullptr) {
        std::cout <<"null"<<std::endl;
        return 1;
    }
    *my_ptr = 3;
    std::cout<<*my_ptr<<std::endl;
    alloc.dellocate(my_ptr);
    return 0;
}
