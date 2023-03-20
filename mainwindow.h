#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "operat.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void num_clicked();
    void point_clicked();
    void pb_del_clicked();
    void operations();
    void AC_clicked();
    void MathOperations();
    void equality_clicked();



private:
    Ui::MainWindow *ui;
    double num1 = 0;
    int operationID;
    void block_or_unblock(bool);
    void num_block(bool);




};
#endif // MAINWINDOW_H
