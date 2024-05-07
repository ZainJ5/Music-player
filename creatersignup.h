#ifndef CREATERSIGNUP_H
#define CREATERSIGNUP_H

#include <QDialog>

namespace Ui {
class CreaterSignUp;
}

class CreaterSignUp : public QDialog
{
    Q_OBJECT

public:
    explicit CreaterSignUp(QWidget *parent = nullptr);
    ~CreaterSignUp();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::CreaterSignUp *ui;
};

#endif // CREATERSIGNUP_H
