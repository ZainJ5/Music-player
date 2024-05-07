#include "createrforgotpassword.h"
#include "ui_createrforgotpassword.h"
#include "user.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>

CreaterForgotPassword::CreaterForgotPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreaterForgotPassword)
{
    ui->setupUi(this);
    this->setWindowTitle("Forgot Password");
    this->setFixedSize(663,464);
    QPixmap background (":/Creator's Logo/Logo's/Creator's Logo/createrforgetpassword.png");
    QPixmap recoverykey1(":/Registration/Logo's/registration/Recovery Key.png");
    QPixmap password1(":/Registration/Logo's/registration/Password.png");
    QPixmap email(":/Registration/Logo's/registration/Email.png");

    ui->emaillogo->setPixmap(email);
    ui->confirmlogo->setPixmap(password1);
    ui->newlogo->setPixmap(password1);
    ui->recoverylogo->setPixmap(recoverykey1);
    ui->background->setPixmap(background);

    QRegularExpression rx("\\d{4}");
    QRegularExpressionValidator *validator2 = new QRegularExpressionValidator(rx, this);
    ui->rkey->setValidator(validator2);
}

CreaterForgotPassword::~CreaterForgotPassword()
{
    delete ui;
}

void CreaterForgotPassword::on_pushButton_clicked()
{
    std::string newpassword = ui->NewPassword->text().toStdString();
    std::string confirmpassword = ui->cpassword->text().toStdString();
    int recoverykey = ui->rkey->text().toInt();
    if (newpassword == confirmpassword){

        std::string email = ui->email->text().toStdString();
        std::string file = "D:\\C++\\Creator's Data.txt";
        std::string tempfile = "D:\\C++\\Ctemp.txt";
        User u1;
        std::string value = u1.changepassword(email,recoverykey,newpassword,file,tempfile);
        QString display = QString::fromStdString(value);
        ui->label->setText(display);
        if(value == "Password Successfully Changed!!"){
            QMessageBox* msgBox = new QMessageBox(this);
            msgBox->information(this, "Note", "Password Changed Successfully. Try Login Again");
            this->close();
        }
        else{
            ui->label->setText(display);
        }
    }
    else{
        ui->label->setText("Password donot Match");
    }
}

