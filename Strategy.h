//
// Created by мвидео on 25.11.2021.
//

#ifndef STRATEGY_STRATEGY_H
#define STRATEGY_STRATEGY_H

#include <iostream>

/*** ИНТЕРФЕЙС ПОЛЕТА - СТРАТЕГИЯ ПОЛЕТА ***/
class IFly {
public:
    virtual ~IFly() = default;
    virtual void fly() = 0;
};

/* Конкретные реализации полёта */
class FlyWithWings : public IFly {
public:
    void fly() override {
        std::cout << "Fly with wings!" << std::endl;
    }
};

class FlyNoWay : public IFly {
public:
    void fly() override {
        std::cout << "Can't fly :(" << std::endl;
    }
};

/*** ИНТЕРФЕЙС КРЯКАНЬЯ - СТРАТЕГИЯ КРЯКАНЬЯ ***/
class IQuack {
public:
    virtual ~IQuack() = default;
    virtual void quack() = 0;
};

/* Конкретные реализации кряканья */
class Quack : public IQuack {
public:
    void quack() override {
        std::cout << "Duck's quack!" << std::endl;
    }
};

class Squeak : public IQuack {
public:
    void quack() override {
        std::cout << "Rubber duck's squeak!" << std::endl;
    }
};

class MuteQuack : public IQuack {
public:
    void quack() override {
        std::cout << "No quack :(" << std::endl;
    }
};

/*** АБСТРАКТНЫЙ КЛАСС УТКИ - НАШ КОНТЕКСТ ***/
class Duck {
protected:
    IFly* _flyStrategy;
    IQuack* _quackStrategy;
public:
    virtual ~Duck() = default;
    void setFly(IFly* flyStrategy) {
        this->_flyStrategy = flyStrategy;
    }
    void setQuack(IQuack* quackStrategy) {
        this->_quackStrategy = quackStrategy;
    }
    void performFly() {
        this->_flyStrategy->fly();
    }
    void performQuack() {
        this->_quackStrategy->quack();
    }
    void swim() {
        std::cout << "All ducks can swim!" << std::endl;
    }
    virtual void display() = 0;
};

/*** Конкретные утки ***/
class MallardDuck : public Duck {
public:
    MallardDuck() {
        this->setFly(new FlyWithWings);
        this->setQuack(new Quack);
    }
    void display() override {
       std::cout << "It's a mallard duck!" << std::endl;
    }
};

class ReadHeadDuck : public Duck {
public:
    ReadHeadDuck() {
        this->setFly(new FlyWithWings);
        this->setQuack(new Quack);
    }
    void display() override {
        std::cout << "It's a read-head duck!" << std::endl;
    }
};

class RubberDuck : public Duck {
public:
    RubberDuck() {
        this->setFly(new FlyNoWay);
        this->setQuack(new Squeak);
    }
    void display() override {
        std::cout << "It's a rubber duck!" << std::endl;
    }
};

class DecoyDuck : public Duck {
public:
    DecoyDuck() {
        this->setFly(new FlyNoWay);
        this->setQuack(new MuteQuack);
    }
    void display() override {
        std::cout << "It's a decoy duck!" << std::endl;
    }
};

#endif //STRATEGY_STRATEGY_H
