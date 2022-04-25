/* 58. shortest path */

/*
 * Features:
 * Dijkstra method
 */

#include "route.h"
int main(int argc, char const *argv[])
{
    Route route;

    route.add_node("A", "B", 7);
    route.add_node("A", "C", 9);
    route.add_node("A", "F", 14);
    route.add_node("B", "C", 10);
    route.add_node("B", "D", 15);
    route.add_node("C", "D", 11);
    route.add_node("C", "F", 2);
    route.add_node("D", "E", 6);
    route.add_node("F", "E", 9);

    route.dijkstra("A");
    auto resD = route.shortest_path("A", "D");
    auto resE = route.shortest_path("A", "E");
    
    route.dijkstra("F");
    auto resFB = route.shortest_path("F", "B");
    auto resFD = route.shortest_path("F", "D");


    std::cout << "path: "
              << "\n";
    for (auto &&i : resD)
        std::cout << i->name() << ":" << i->weight << " ";
    std::cout << "\n";

    for (auto &&i : resE)
        std::cout << i->name() << ":" << i->weight << " ";
    std::cout << "\n";

    for (auto &&i : resFB)
        std::cout << i->name() << ":" << i->weight << " ";
    std::cout << "\n";

    for (auto &&i : resFD)
        std::cout << i->name() << ":" << i->weight << " ";
    std::cout << "\n";

    return 0;
}