#include <iostream>
#include <queue>
#include <string>


void addEvent( std::queue<std::string> &eventQueue,
               const std::string& event )
{
    eventQueue.push( event );
}

void processEvents( std::queue<std::string> &eventQueue )
{
    if( eventQueue.empty() ) {
        std::cout << "Queue is empty\n";
        return;
    }

    while( !eventQueue.empty() ) {
        std::cout << "Processing event called '" << eventQueue.front() << "'\n";
        eventQueue.pop();
    }
}

int main()
{
    std::queue<std::string> queue{};
    addEvent( queue, "Hello" );
    addEvent( queue, "Done" );
    addEvent( queue, "Bull" );
    processEvents( queue );
    return 0;
}
