#ifndef USER_H
#define USER_H

#include <QString>
#include <QFile>
#include <QTextStream>
// using namespace std;
class User
{
private:
    std::string name;
    int age;
    std::string remail;
    std::string rpassword;
    std::string lemail;
    std::string lpassword;
    std::string checkusername;
    std::string checkpassword;
    int emailline;
    int nameline;
    int rpin;
    std::string totalbill;
    std::string subscription;
    bool checkU;
    bool checkP;

public:
    User();
    std::string  ReturnPawword();
    int Returnnameline();
    void registration(std::string name, int age, std::string remail, std::string rpassword, int rpin, std::string file);
    std::string login(std::string file, std::string useremail, std::string userpassword);
    std::string changepassword(std::string email,int recoverykey1,std::string newpassword12,std::string file,std::string tempfile);
    std::string deleteaccount(std::string dpass, std::string file, std::string tempfile, const std::string &lpassword);
    std::string getName() const;
    int getAge() const;
};

#endif // USER_H
