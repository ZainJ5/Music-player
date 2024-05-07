#ifndef SUBSCRIPTION_H
#define SUBSCRIPTION_H

#include <iostream>
#include <fstream>
#include <string>

class Subscription {
private:
    int sub1;
    std::string displaysubscription;
    int bill;

public:
    std::string checkSubscription();
    std::string changeSubscription();
};

#endif // SUBSCRIPTION_H
