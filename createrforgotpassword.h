#ifndef CREATERFORGOTPASSWORD_H
#define CREATERFORGOTPASSWORD_H

#include <QDialog>

namespace Ui {
class CreaterForgotPassword;
}

class CreaterForgotPassword : public QDialog
{
    Q_OBJECT

public:
    explicit CreaterForgotPassword(QWidget *parent = nullptr);
    ~CreaterForgotPassword();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreaterForgotPassword *ui;
};

#endif // CREATERFORGOTPASSWORD_H
