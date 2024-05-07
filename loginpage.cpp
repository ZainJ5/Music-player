#include "loginpage.h"
#include "forgotpassword.h"
#include "registration.h"
#include "ui_loginpage.h"
#include "youtubemainpage.h"
#include "user.h"
#include <globalvariable.h>
#include <QLineEdit>
using namespace std;

LoginPage::LoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setFixedSize(663,464);
    this->setWindowTitle("Login Page");
    Qt::WindowFlags flags = this->windowFlags();
    flags |= Qt::WindowMinimizeButtonHint;
    this->setWindowFlags(flags);
    QPixmap photo(":/Creator's Logo/Logo's/Creator's Logo/Background.png");
    ui->Background->setPixmap(photo.scaled(ui->Background->size(),Qt::KeepAspectRatio));
    QPixmap profile(":/Login/Logo's/login/Login Banda.png");
    ui->Profile->setPixmap(profile.scaled(ui->Profile->size(), Qt::KeepAspectRatio));
    QPixmap username(":/Login/Logo's/login/enter email.png"),password(":/Login/Logo's/login/password.png");
    ui->Username->setPixmap(username.scaled(ui->Username->size(),Qt::KeepAspectRatio));
    ui->Password->setPixmap(password.scaled(ui->Password->size(),Qt::KeepAspectRatio));
    QPixmap ceye(":/Login/Logo's/login/Ceye.png");
    ui->pushButton_3->setIcon(ceye);

}


LoginPage::~LoginPage()
{
    delete ui;
}
void LoginPage::on_pushButton_3_toggled(bool checked)
{
    if(checked){
        QPixmap oeye(":/Login/Logo's/login/Oeye.png");
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton_3->setIcon(oeye);
    }
    else{
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        QPixmap ceye(":/Login/Logo's/login/Ceye.png");
        ui->pushButton_3->setIcon(ceye);
    }
}

void LoginPage::on_pushButton_clicked()
{
    User U1;
    QString qemail = ui->lineEdit->text();
    QString qpassword = ui->lineEdit_2->text().trimmed();
    string email = qemail.toStdString();
    string password = qpassword.toStdString();
    string d= "D:\\C++\\User's Data.txt";
    string text = U1.login(d,email,password);
    QString Text= QString::fromStdString(text);
    ui->Text->setText(Text);
    if(text == "Login Successful!!"){
        Youtubemainpage *mainpage = new Youtubemainpage();
        globalVariable = U1.ReturnPawword();
        nameline1 = U1.Returnnameline();
        this->hide();
        mainpage->show();

    }
}
void LoginPage::on_pushButton_2_clicked()
{
    Registration *registration = new Registration();
    registration->show();
}



void LoginPage::on_pushButton_4_clicked()
{
    ForgotPassword *forgotpassword = new ForgotPassword;
    forgotpassword->show();

}

