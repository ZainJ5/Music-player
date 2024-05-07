#include "mainwindow.h"
#include "creatorloginpage.h"
#include "loginpage.h"
#include "ui_mainwindow.h"
#include "loginpage.h"
#include <QGraphicsBlurEffect>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Youtube Clone");
    this->setFixedSize(476,478);
    Qt::WindowFlags flags = this->windowFlags();
    flags |= Qt::WindowMinimizeButtonHint;
    this->setWindowFlags(flags);
    QPixmap photo(":/First Window/Logo's/First Window/Background.png");
    // int w = ui->Background->width();
    // int h = ui->Background->height();
    ui->Background->setPixmap(photo.scaled(ui->Background->size(), Qt::IgnoreAspectRatio));
    QPixmap photo2(":/First Window/Logo's/First Window/Youtube Logo.png");
    int w1 = ui->YoutubeLogo->width();
    int h1 = ui->YoutubeLogo->height();
    ui->YoutubeLogo->setPixmap(photo2.scaled(w1,h1,Qt::KeepAspectRatio));
    // QGraphicsBlurEffect *blurEffect = new QGraphicsBlurEffect;
    // blurEffect->setBlurRadius(5);
    // ui->Background->setGraphicsEffect(blurEffect);


}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    CreatorLoginPage *Clogin = new CreatorLoginPage();
    Clogin->show();
    this->close();
}


void MainWindow::on_pushButton_2_clicked()
{
    LoginPage *login = new LoginPage();
    login->show();
    this->close();
}

