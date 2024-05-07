#include "registration.h"
#include "ui_registration.h"
#include "user.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QIcon>

Registration::Registration(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Registration)
{
    ui->setupUi(this);
    QPixmap logo(":/Registration/Logo's/registration/Youtube logo.png");
    ui->youtubelogo->setPixmap(logo);
    QPixmap profile(":/Registration/Logo's/registration/Register.png");
    ui->profile->setPixmap(profile);
    QPixmap username1(":/Registration/Logo's/registration/Username.png");
    QPixmap password1(":/Registration/Logo's/registration/Password.png");
    QPixmap age1(":/Registration/Logo's/registration/Age.png");
    QPixmap email1(":/Registration/Logo's/registration/Email.png");
    QPixmap recoverykey1(":/Registration/Logo's/registration/Recovery Key.png");


    ui->name1->setPixmap(username1);
    ui->age1->setPixmap(age1);
    ui->password1->setPixmap(password1);
    ui->recoverykey1->setPixmap(recoverykey1);
    ui->email1->setPixmap(email1);




    QRegularExpression rx("\\d{4}");
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(rx, this);
    ui->recoverykey->setValidator(validator2);


    QIntValidator * validator = new QIntValidator(this);
    validator->setRange(5,100);
    ui->age->setValidator(validator);

    // QIntValidator *validator2 = new QIntValidator(100, 999, this);;
    // ui->recoverykey->setValidator(validator2);

}

Registration::~Registration()
{
    delete ui;
}

void Registration::on_pushButton_clicked()
{
    std::string name = ui->name->text().toStdString();
    std::string password = ui->password->text().toStdString();
    std::string email = ui->email->text().toStdString();

    int age = 0;
    int recoverykey = 0;
    age = ui->age->text().toInt();
    recoverykey = ui->recoverykey->text().toInt();
    std::string file = "D:\\C++\\User's Data.txt";
    if (!name.empty() && !password.empty() && !email.empty() && age != 0 && recoverykey != 0){
    User u1;
    u1.registration(name,age,email,password,recoverykey,file);
    QMessageBox* msgBox = new QMessageBox(this);
    msgBox->information(this, "Note", "Registration Successful. Try Login Again");
    this->close();
    }
}

