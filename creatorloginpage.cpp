#include "creatorloginpage.h"
#include "createrforgotpassword.h"
#include "creatermainwindow.h"
#include "creatersignup.h"
#include "ui_creatorloginpage.h"
#include "user.h"
#include <QPixmap>
#include <QString>

CreatorLoginPage::CreatorLoginPage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreatorLoginPage)
{
    ui->setupUi(this);
    this->setFixedSize(663, 464);
    this->setWindowTitle("Login Page");
    Qt::WindowFlags flags = this->windowFlags();
    flags |= Qt::WindowMinimizeButtonHint;
    this->setWindowFlags(flags);

    // Set background and profile images
    QPixmap background(":/Creator's Logo/Logo's/Creator's Logo/Background.png");
    ui->Background->setPixmap(background.scaled(ui->Background->size(), Qt::KeepAspectRatio));
    QPixmap profile(":/Login/Logo's/login/Login Banda.png");
    ui->Profile->setPixmap(profile.scaled(ui->Profile->size(), Qt::KeepAspectRatio));
    QPixmap username(":/Login/Logo's/login/enter email.png"), password(":/Login/Logo's/login/password.png");
    ui->Username->setPixmap(username.scaled(ui->Username->size(), Qt::KeepAspectRatio));
    ui->Password->setPixmap(password.scaled(ui->Password->size(), Qt::KeepAspectRatio));
    QPixmap ceye(":/Login/Logo's/login/Ceye.png");
    ui->pushButton->setIcon(ceye);
}


CreatorLoginPage::~CreatorLoginPage()
{
    delete ui;
}


void CreatorLoginPage::on_pushButton_5_clicked()
{
    User U1;
    QString qemail = ui->lineEdit->text();
    QString qpassword = ui->lineEdit_2->text().trimmed();
    std::string email = qemail.toStdString();
    std::string password = qpassword.toStdString();
    std::string file_path = "D:\\C++\\Creator's Data.txt";
    std::string text = U1.login(file_path, email, password);
    ui->Text->setText(QString::fromStdString(text));
    if (text == "Login Successful!!") {
        CreaterMainWindow *mainpage = new CreaterMainWindow();
        this->hide();
        mainpage->show();
    }
}


void CreatorLoginPage::on_signup_clicked()
{
    CreaterSignUp *signup = new CreaterSignUp;
    signup->show();
}


void CreatorLoginPage::on_pushButton_toggled(bool checked)
{

    if (checked) {
        QPixmap oeye(":/Login/Logo's/login/Oeye.png");
        ui->lineEdit_2->setEchoMode(QLineEdit::Normal);
        ui->pushButton->setIcon(oeye);
    } else {
        ui->lineEdit_2->setEchoMode(QLineEdit::Password);
        QPixmap ceye(":/Login/Logo's/login/Ceye.png");
        ui->pushButton->setIcon(ceye);
    }
}


void CreatorLoginPage::on_Cforgotpassword_clicked()
{
    CreaterForgotPassword *forgot = new CreaterForgotPassword;
    forgot->show();
}

