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

void takeOwnership(std::unique_ptr<Item> item);

/*
    Create a custom struct, manage its lifecycle dynamically using std::unique_ptr, 
    try to break it by copying it, and then successfully transfer it 
    to a function using move semantics.
*/
int main() {
    std::unique_ptr<Item> p1 = std::make_unique<Item>(42);
    //std::unique_ptr<Item> p2 = p1; 
    // ^^^ NOT POSSIBLE, compiler blocks it, "unique_ptr" is unique, meaning it must be the only owner to that object
    p1->printItem();

    takeOwnership(std::move(p1));

    //p1->printItem(); -> seg fault, item already destroyed

}

void takeOwnership(std::unique_ptr<Item> i){
    i->printItem();
}