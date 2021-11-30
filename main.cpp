#include "Strategy.h"
#include <vector>

int main() {
    std::vector<Duck*> someDucks = {new MallardDuck, new ReadHeadDuck, new RubberDuck, new DecoyDuck};
    for (auto duck : someDucks) {
        duck->performFly();
        duck->performQuack();
        duck->swim();
        duck->display();
        std::cout << std::endl;
        delete duck;
    }
    return 0;
}
