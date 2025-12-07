#include <iostream>
#include <queue>
#include <string>

void addToQueue( std::queue<std::string> &queue, const std::string& person )
{
    queue.push( person );
}
void processQueue( std::queue<std::string> &queue )
{
    if( queue.empty() ) {
        std::cout << "Queue is empty\n";
        return;
    }
    std::cout << "One person is gone from queue\n";
    queue.pop();
}

int main()
{
    std::queue<std::string> queue{};
    addToQueue( queue, "Hello" );
    addToQueue( queue, "Hello" );
    addToQueue( queue, "Hello" );
    processQueue( queue );
    processQueue( queue );
    processQueue( queue );
    processQueue( queue );
    return 0;
}
