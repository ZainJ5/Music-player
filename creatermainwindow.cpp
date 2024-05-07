#include "creatermainwindow.h"
#include "creatorloginpage.h"
#include "qmessagebox.h"
#include "ui_creatermainwindow.h"
#include "uploadvideo.h"
#include "user.h"
#include <QFileDialog>
#include <globalvariable.h>
#include <fstream>

CreaterMainWindow::CreaterMainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CreaterMainWindow)
{
    ui->setupUi(this);    
    QPixmap ytlogo(":/Creator's Logo/Logo's/Creator's Logo/Youtube Creator.png");
    ui->ytlogo->setPixmap(ytlogo);
    QString n = QString::fromStdString(username);
    ui->username->setText(n);
    UploadVideo up1;
    up1.performance(username);
    for (int i = 0; i < cvideosize; i++) {
        QString add = QString::fromStdString(CreatersVideo[i]);
        ui->comboBox->addItem(add);
    }
    ui->comboBox->addItem("Select Video");
    ui->comboBox->setCurrentText("Select Video");

    QPixmap u(":/Creator's Logo/Logo's/Creator's Logo/Upload page photo.png");
    ui->upload_2->setPixmap(u);

    QStringList categories = {"Entertainment", "Education", "Gaming", "News and Politics"};
    ui->comboBox_4->addItems(categories);


    connect(ui->Browse, &QPushButton::clicked, this, &CreaterMainWindow::openVideoFile);
    connect(ui->checkBox ,&QCheckBox::stateChanged,this, &CreaterMainWindow::onCheckBoxStateChanged);
    connect(ui->comboBox_4, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxIndexChanged(int)));
    connect(ui->pushButton,&QPushButton::clicked,this,&CreaterMainWindow::openImageFile);


    agerestriction = "Not Restricted";

    ui->stackedWidget->setCurrentIndex(0);
}

CreaterMainWindow::~CreaterMainWindow()
{
    delete ui;
}

void CreaterMainWindow::onCheckBoxStateChanged(int state) {
    if (state == Qt::Checked) {
        agerestriction = "Restricted";
        qDebug() << "Checkbox is checked";
    } else {
        agerestriction = "Not Restricted";
        qDebug() << "Checkbox is unchecked";
    }
}
void CreaterMainWindow::onComboBoxIndexChanged(int index) {
    categorey1 = ui->comboBox_4->itemText(index);
}
void CreaterMainWindow::on_upload_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void CreaterMainWindow::on_revenue_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void CreaterMainWindow::on_performance_clicked()
{
    if(cvideosize>=0){
    ui->stackedWidget->setCurrentIndex(3);

    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onItemSelected(int)));
    }

}
void CreaterMainWindow::onItemSelected(int index) {
    qDebug()<<"Function Started";
    UploadVideo up1;
    QString selectedItem = ui->comboBox->itemText(index);
    std::string select = selectedItem.toStdString();
    up1.likevideo(select,false);
    QString views = QString::fromStdString(createrviews);
    QString likes = QString::fromStdString(createrlikes);
    QString revenue = QString::number(createrrevenue) + "$";
    ui->displayviews->setText(views);
    ui->displaylikes->setText(likes);
    ui->displayrevenue->setText(revenue);
}


void CreaterMainWindow::on_logout_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void CreaterMainWindow::on_delete_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void CreaterMainWindow::on_pushButton_3_clicked()
{
    CreatorLoginPage *login = new CreatorLoginPage;
    login->show();
    this->hide();
}


void CreaterMainWindow::on_pushButton_2_clicked()
{
    std::string file = "D:\\C++\\Creator's Data.txt";
    std::string tempfile = "D:\\C++\\Ctemp.txt";
    QString password = ui->dpassword->text().trimmed();
    std::string dpassword = password.toStdString();
    if (!dpassword.empty()){
        User u1;
        std::string pass = createrpassword;
        std::string output = u1.deleteaccount(dpassword,file ,tempfile,pass);
        if(output == "Account Successfully Deleted!!"){
            QString display = QString::fromStdString(output);
            ui->deleteresult->setText(display);
            QMessageBox *mess = new QMessageBox (this);
            mess->information(this,"Note","Account Deleted");
            CreatorLoginPage *login = new CreatorLoginPage;
            login->show();
            this->hide();

        }
        else{
            QString display = QString::fromStdString(output);
            ui->invalidpassword->setText(display);
        }
    }
}

#include <QFileDialog>

void CreaterMainWindow::openVideoFile() {
    QFileDialog dialog(this);
    dialog.setWindowTitle("Open Video File");
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("Video Files (*.mp4 *.avi *.mov)");

    if (dialog.exec()) {
        fileName = dialog.selectedFiles().first();
        qDebug() << "Selected Video File: " << fileName;
    }
}

void CreaterMainWindow::on_pushButton_10_clicked()
{
    if(!fileName.isEmpty()){
        ui->stackedWidget->setCurrentIndex(1);
    }
}


void CreaterMainWindow::on_pushButton_11_clicked()
{

    QString videotitle1 = ui->videotitle->text();
    QString videoDescription = ui->videodes->text();
    // uploadvideo(string name,string vt,string des,string vl,string cate,string restriction)
    if (!username.empty() && !videotitle1.isEmpty() && !videoDescription.isEmpty() &&
        !fileName.isEmpty() && !agerestriction.isEmpty() && !categorey1.isEmpty() && !thumbnail.isEmpty()) {
        UploadVideo up1;
        std::string vt = videotitle1.toStdString();
        std::string vd = videoDescription.toStdString();
        std::string vl = fileName.toStdString();
        std::string cate = categorey1.toStdString();
        std::string restriction = agerestriction.toStdString();
        std::string Thumbanil = thumbnail.toStdString();
        up1.uploadvideo(username,vt,vd,vl,cate,restriction);
        qDebug()<<username;
        qDebug()<<videotitle1;
        qDebug()<<videoDescription;
        qDebug()<<fileName;
        qDebug()<<agerestriction;
        qDebug()<<categorey1;

        qDebug()<<"Thumbnail path : ";
        qDebug()<<thumbnail;
        std::ofstream file("D:\\C++\\Video Thumbnails.txt", std::ios::app);
        if (file.is_open()) {
            file << vt << std::endl;
            file << Thumbanil  << std::endl;
            file.close();
        }

        QMessageBox *message = new QMessageBox;
        message->information(this, "Note", "Video Successfully Uploaded");
        ui->stackedWidget->setCurrentIndex(0);
    }


}

void CreaterMainWindow::openImageFile() {
    QFileDialog dialog(this);
    dialog.setWindowTitle("Open Image File");
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("Image Files (*.png *.jpg *.bmp *.jpeg)");

    if (dialog.exec()) {
        thumbnail = dialog.selectedFiles().first();
        if (!fileName.isEmpty()) {
            qDebug() << "Selected File: " << fileName;
        }
    }
}


