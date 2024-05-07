#include "forgotpassword.h"
#include "ui_forgotpassword.h"
#include "user.h"
#include <QRegularExpressionValidator>
#include <QMessageBox>

ForgotPassword::ForgotPassword(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ForgotPassword)
{
    ui->setupUi(this);
    QPixmap background (":/Forgot Password/Logo's/forgot password/forrgot password[ banda].png");
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

ForgotPassword::~ForgotPassword()
{
    delete ui;
}

void ForgotPassword::on_pushButton_2_clicked()
{
    std::string newpassword = ui->NewPassword->text().toStdString();
    std::string confirmpassword = ui->cpassword->text().toStdString();
    int recoverykey = ui->rkey->text().toInt();
    if (newpassword == confirmpassword){

        std::string email = ui->email->text().toStdString();
        std::string file = "D:\\C++\\User's Data.txt";
        std::string tempfile ="D:\\C++\\temp.txt";
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

