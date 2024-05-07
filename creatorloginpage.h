#ifndef CREATORLOGINPAGE_H
#define CREATORLOGINPAGE_H

#include <QDialog>

namespace Ui {
class CreatorLoginPage;
}

class CreatorLoginPage : public QDialog
{
    Q_OBJECT

public:
    explicit CreatorLoginPage(QWidget *parent = nullptr);
    ~CreatorLoginPage();

private slots:
    void on_pushButton_5_clicked();

    void on_signup_clicked();

    void on_pushButton_toggled(bool checked);

    void on_Cforgotpassword_clicked();

private:
    Ui::CreatorLoginPage *ui;
    void on_pushButton_3_toggled(bool checked);
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
};

#endif // CREATORLOGINPAGE_H
