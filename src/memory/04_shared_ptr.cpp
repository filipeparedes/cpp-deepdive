#include <memory>
#include <iostream>

struct Item {
    int id;

    Item(int i) : id(i){}

    ~Item() {
        std::cout << "Item nº" << id << " destroyed\n";
    }

    void printItem(){
        std::cout << "Item nº " << id << std::endl;
    }
};

/*
    Create a shared resource, track its reference count dynamically 
    as it enters and leaves inner scopes, and observe when it 
    finally gets destroyed.
*/
int main() {
    std::shared_ptr p1 = std::make_shared<Item>(100);

    std::cout << "Ref count: " << p1.use_count() << std::endl;

    {
        std::shared_ptr<Item> p2 = p1;
        std::cout << "Ref count: " << p1.use_count() << std::endl;
    }

    //should go back to 1, because then the inner scope closes, p2 was destroyed
    std::cout << "Ref count: " << p1.use_count() << std::endl;

}