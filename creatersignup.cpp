#include "creatersignup.h"
#include "ui_creatersignup.h"
#include "user.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>
#include <QIntValidator>
#include <QIcon>

CreaterSignUp::CreaterSignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreaterSignUp)
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
    QPixmap sidephoto(":/Creator's Logo/Logo's/Creator's Logo/Login Photo.png");

    ui->name1->setPixmap(username1);
    ui->age1->setPixmap(age1);
    ui->password1->setPixmap(password1);
    ui->recoverykey1->setPixmap(recoverykey1);
    ui->email1->setPixmap(email1);
    ui->label->setPixmap(sidephoto);



    QRegularExpression rx("\\d{4}");
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(rx, this);
    ui->recoverykey->setValidator(validator2);


    QIntValidator * validator = new QIntValidator(this);
    validator->setRange(5,100);
    ui->age->setValidator(validator);

}

CreaterSignUp::~CreaterSignUp()
{
    delete ui;
}

void CreaterSignUp::on_pushButton_2_clicked()
{
    qDebug()<<"Button Clickked";
    std::string name = ui->name->text().toStdString();
    std::string password = ui->password->text().toStdString();
    std::string email = ui->email->text().toStdString();
    int age = 0;
    int recoverykey = 0;
    age = ui->age->text().toInt();
    recoverykey = ui->recoverykey->text().toInt();
    std::string file = "D:\\C++\\Creator's Data.txt";
    if (!name.empty() && !password.empty() && !email.empty() && age != 0 && recoverykey != 0){
        User u1;
        u1.registration(name,age,email,password,recoverykey,file);
        QMessageBox* msgBox = new QMessageBox(this);
        msgBox->information(this, "Note", "Registration Successful. Try Login Again");
        this->close();
    }
}

