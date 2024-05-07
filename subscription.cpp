#include "subscription.h"
#include <globalvariable.h>

std::string Subscription::checkSubscription() {
    sub1 = lineofusername + 4;
    std::ifstream readfile("D:\\C++\\User's Data.txt");
    std::string checksub;
    int current_line = 0;
    while (std::getline(readfile, checksub)) {
        if (current_line == sub1) {
            displaysubscription = checksub;
            break;
        }
        current_line++;
    }
    return displaysubscription;
}

std::string Subscription::changeSubscription() {

    sub1 = lineofusername + 4;
    std::string result;
    bill = sub1 + 1;
    std::ifstream readfile1("D:\\C++\\User's Data.txt");
    std::string checksub;
    int current_line = 0;
    while (std::getline(readfile1, checksub)) {
        if (current_line == sub1) {
            displaysubscription = checksub;
            break;
        }
        current_line++;
    }
    readfile1.close();

    std::ifstream readfile("D:\\C++\\User's Data.txt");
    std::ofstream temp("D:\\C++\\temp.txt");
    if (!((readfile.is_open()) && (temp.is_open()))) {
        std::cout << "Error Opening File!!" << std::endl;
        return 0;
    } else if (displaysubscription == "Standard Account") {
        current_line = 0;
        readfile.seekg(0, std::ios::beg);
        while (std::getline(readfile, checksub)) {
            if (current_line == sub1) {
                temp << "Premium Account" << std::endl;
            } else if (current_line == bill) {
                temp << "10$" << std::endl;
            } else {
                temp << checksub << std::endl;
            }
            current_line++;
        }
        result = "Account Upgraded Successfully!!";
    }
    if (displaysubscription == "Premium Account") {

        current_line = 0;
        readfile.seekg(0, std::ios::beg);
        while (std::getline(readfile, checksub)) {
            if (current_line == sub1) {
                temp << "Standard Account" << std::endl;
            } else if (current_line == bill) {
                temp << "0$" << std::endl;
            } else {
                temp << checksub << std::endl;
            }
            current_line++;
        }
        result = "Account Subscription Removed!! ";
    }
    temp.close();
    readfile.close();
    std::remove("D:\\C++\\User's Data.txt");
    std::rename("D:\\C++\\temp.txt", "D:\\C++\\User's Data.txt");
    return result;
}
