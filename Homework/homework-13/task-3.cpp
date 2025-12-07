#include <queue>
#include <iostream>

struct Order {
    std::string customerName;
    std::vector<std::string> items;
};

void addOrder( std::queue<Order> &orderQueue, const Order& newOrder )
{
    orderQueue.push( newOrder );
}

void processOrder( std::queue<Order> &orderQueue )
{
    if( orderQueue.empty() ) {
        std::cout << "Queue is empty\n";
        return;
    }

    Order &order = orderQueue.front();
    std::cout << "--------------\n"
              << "Customer: " << order.customerName << '\n'
              << "Orders:\n";
    for( std::string o : order.items ) {
        std::cout << o << '\n';
    }

    orderQueue.pop();
}

int main()
{
    std::queue<Order> queue{};
    addOrder( queue, {"Hello", {"car", "svita", "apple"}} );
    addOrder( queue, {"Arg", {"doll", "mister", "push", "denga"}} );
    addOrder( queue, {"Hello", {"car"}} );
    processOrder( queue );
    processOrder( queue );
    processOrder( queue );
    return 0;
}
