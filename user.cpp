#include "user.h"
#include <globalvariable.h>
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
User::User() {
    checkU = false;
    checkP = false;
    totalbill="0$";
    subscription="Standard Account";
    lpassword = "";
}

string User::login(string file, string useremail, string userpassword)
{
    ifstream readfile(file);
    int line_number = 0;
    while (getline(readfile, checkusername))
    {
        if (useremail == checkusername)
        {
            checkU = true;
            break;
        }
        line_number++;
    }
    emailline = line_number;
    line_number++;
    int currentline = 0;
    readfile.seekg(0, ios::beg);
    if (checkU)
    {
        while (getline(readfile, checkpassword))
        {
            if (currentline == line_number)
            {
                if (userpassword == checkpassword)
                {
                    checkP = true;
                    createrpassword = userpassword;
                }

            }
            currentline++;
        }
    }
    readfile.clear();
    readfile.seekg(0, ios::beg);
    line_number = line_number - 2;
    nameline = line_number;
    lineofusername = nameline;
    currentline = 1;
    string cname;
    while (getline(readfile, cname))
    {
        if (currentline == line_number)
        {
            this->name = cname;
            username = name;
        }
        if (currentline == line_number + 1)
        {
            string sage = cname;
            this->age = stoi(sage);
            gage = age;
        }

        currentline++;
    }
    if ((checkU) && (checkP))
    {
        this->lpassword = userpassword;
        return "Login Successful!!";
    }

    else if (!checkU)
    {
        return "User Not Found!!";
    }
    else
    {
        return "Invalid Password!!";
    }
}
string User:: ReturnPawword(){
    return lpassword;
}
int User::Returnnameline(){
    return nameline;
}
void User::registration(std::string name, int age, std::string remail, std::string rpassword, int rpin, std::string file)
{
    this->name = name;
    this->age = age;
    this->remail = remail;
    this->rpassword = rpassword;
    this->rpin = rpin;

    ofstream userdata(file, std::ios::app);
    if (!userdata)
    {
        cout << "Error: Could not open file for writing." <<endl;
        return;
    }

    userdata << this->name <<endl;
    userdata << this->age <<endl;
    userdata << this->remail <<endl;
    userdata << this->rpassword <<endl;
    userdata << this->rpin <<endl;
    if (file == "D:\\C++\\User's Data.txt")
    {
        userdata << this->subscription <<endl;
        userdata << this->totalbill <<endl;
    }
    else
    {
        userdata << 0 <<endl;
    }
    userdata.close();
}
string User::changepassword(string email, int recoverykey1, string newpassword12, string file, string tempfile) {
    string Srpin;
    string newpassword;
    this->lemail = email;
    this->rpin = recoverykey1;
    Srpin = to_string(rpin);
    ifstream readfile(file);
    int recoverykey = 0;
    while (getline(readfile, this->checkusername)) {
        if (lemail == this->checkusername) {
            this->checkU = true;
            break;
        }
        recoverykey++;
    }
    readfile.seekg(0, ios::beg);
    recoverykey = recoverykey + 2;
    for (int i = 0; i <= recoverykey; i++) {
        getline(readfile, this->checkpassword);
        if (i == recoverykey) {
            if (Srpin == this->checkpassword) {
                this->checkP = true;
                break;
            }
        }
    }

    ofstream temp(tempfile);
    readfile.seekg(0, ios::beg);
    if (!this->checkU) {
        return "No User Found";
    }
    if (!this->checkP) {
        return "Recovery Key Invalid!";
    }

    if ((this->checkU) && (this->checkP)) {

        newpassword = newpassword12;
        recoverykey = recoverykey;
        int cline = 0;
        string line;
        ifstream readfile(file);
        while (getline(readfile, line)) {
            cline++;
            if (cline == recoverykey) {
                temp << newpassword << endl;
            }
            else
                temp << line << endl;
        }
    }
    readfile.close();
    temp.close();
    const char *ofile = file.c_str();
    const char *tfile = tempfile.c_str();
    remove(ofile);
    rename(tfile, ofile);
    return "Password Successfully Changed!!";
}

std::string User::deleteaccount(std::string dpass, std::string file, std::string tempfile,const std::string& lpassword) {
    ifstream readfile(file);
    ofstream temp(tempfile);

    if (!(dpass == lpassword)) {
        readfile.close();
        temp.close();
        return "Authentication Failed!!";
    }

    string temp1;
    int deletestarting = nameline1;
    int deleteending = nameline1 + 6;
    int lineNumber = 1;
    while (getline(readfile, temp1)) {
        if (!(lineNumber >= deletestarting && lineNumber <= deleteending)) {
            temp << temp1 << endl;
        }
        lineNumber++;
    }
    readfile.close();
    temp.close();
    const char *oFile = file.c_str();
    const char *tFile = tempfile.c_str();
    remove(oFile);
    rename(tFile, oFile);

    return "Account Successfully Deleted!!";
}
