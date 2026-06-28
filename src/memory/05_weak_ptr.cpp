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
    Demonstrate how a weak_ptr can observe a shared_ptr without 
    increasing its reference count, and how to safely access the 
    data using .lock() before and after the resource is destroyed.
*/
int main() {
    std::weak_ptr<Item> observer;

    {
        std::shared_ptr<Item> p1 = std::make_shared<Item>(99);
        observer = p1;

        //should be 1
        std::cout << "Ref count: " << p1.use_count() << std::endl;

        if (std::shared_ptr<Item> temp = observer.lock()) {
            std::cout << "Success \n";
            temp->printItem();
            
            //2
            std::cout << "Ref count: " << p1.use_count() << std::endl;
        }

        std::cout << "Ref count: " << p1.use_count() << std::endl;
    }

    //innter scope closed, p1 destroyed
    if (std::shared_ptr<Item> temp = observer.lock()) {
        std::cout << "Success \n";
    } else {
        std::cout << "Pointer expired \n";
    }
}