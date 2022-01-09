#include <iostream>
#include <thread>
#include <vector>
#include <functional>

int main(int argc, char *argv[])
{
    std::cout << "mutex main" << std::endl;

    std::function<int(int)> fnc = [&](int cnt) { 

        for(int i = 0; i < cnt; i++)
        {
            std::cout << i << std::endl;
        }
        return 0;
     };

    std::vector<std::thread> workers;

    workers.push_back(std::thread(fnc, 100));

    std::thread th1 = std::thread(fnc, 10);

    for(auto &th : workers)
    {
        th.join();
    }
    th1.detach();
    
    std::cout << __PRETTY_FUNCTION__ << "end" << std::endl;
}