#ifndef CREATERMAINWINDOW_H
#define CREATERMAINWINDOW_H

#include <QDialog>

namespace Ui {
class CreaterMainWindow;
}

class CreaterMainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreaterMainWindow(QWidget *parent = nullptr);
    ~CreaterMainWindow();

private slots:
    void on_upload_clicked();

    void on_revenue_clicked();

    void on_performance_clicked();

    void on_logout_clicked();

    void on_delete_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();
    void onItemSelected(int index);
    void openVideoFile();

    void on_pushButton_10_clicked();
    void onCheckBoxStateChanged(int state);

    void on_pushButton_11_clicked();

    void onComboBoxIndexChanged(int index);
    void on_pushButton_clicked();
    void openImageFile();

private:
    Ui::CreaterMainWindow *ui;
    QString fileName;
    QString agerestriction;
    QString categorey1;
    QString thumbnail;
};

#endif // CREATERMAINWINDOW_H
