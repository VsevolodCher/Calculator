#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "operat.h"
#include <QMessageBox>



#define PLUS 1;
#define MINUS 2;
#define DEL 3;
#define MULT 4;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pb_0,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_1,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_2,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_3,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_4,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_5,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_6,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_7,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_8,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_9,&QPushButton::clicked,this,&MainWindow::num_clicked);
    connect(ui->pb_point,&QPushButton::clicked,this,&MainWindow::point_clicked);
    connect(ui->pb_del,&QPushButton::clicked,this,&MainWindow::pb_del_clicked);
    connect(ui->pb_procent,&QPushButton::clicked,this,&MainWindow::operations);
    connect(ui->pb_minus_or_plus,&QPushButton::clicked,this,&MainWindow::operations);
    connect(ui->pb_delall,&QPushButton::clicked,this,&MainWindow::AC_clicked);
    connect(ui->pb_minus,&QPushButton::clicked,this,&MainWindow::MathOperations);
    connect(ui->pb_delen,&QPushButton::clicked,this,&MainWindow::MathOperations);
    connect(ui->pb_umnogh,&QPushButton::clicked,this,&MainWindow::MathOperations);
    connect(ui->pb_plus,&QPushButton::clicked,this,&MainWindow::MathOperations);
    connect(ui->pb_ravno,&QPushButton::clicked,this,&MainWindow::equality_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::block_or_unblock(bool flag)
{
    ui->pb_plus->setEnabled(flag);
    ui->pb_minus_or_plus->setEnabled(flag);
    ui->pb_minus->setEnabled(flag);
    ui->pb_delen->setEnabled(flag);
    ui->pb_procent->setEnabled(flag);
    ui->pb_umnogh->setEnabled(flag);
    ui->pb_ravno->setEnabled(flag);

}

void MainWindow::num_block(bool flag)
{
    ui->pb_0->setEnabled(flag);
    ui->pb_1->setEnabled(flag);
    ui->pb_2->setEnabled(flag);
    ui->pb_3->setEnabled(flag);
    ui->pb_4->setEnabled(flag);
    ui->pb_5->setEnabled(flag);
    ui->pb_6->setEnabled(flag);
    ui->pb_7->setEnabled(flag);
    ui->pb_8->setEnabled(flag);
    ui->pb_9->setEnabled(flag);
    ui->pb_del->setEnabled(flag);

}


void MainWindow::num_clicked()
{
    QString label = ui->label->text();
    if(!label.contains(".")){
        ui->pb_point->setEnabled(true);
    }
    if(!(ui->label->text().contains('e'))){


    ui->pb_ravno->setEnabled(true);
    if(ui->label->text().length() < 15){
    QPushButton *pb = (QPushButton*)sender();

    QString str;

    if (ui->label->text() == "0" && (pb->text() != "+0" || pb->text() == "-0")){
        str = pb->text();
    } else {
        str = ui->label->text() + pb->text();
    }
    ui->label->setText(str);

    } else{
        QMessageBox::warning(this,"Error!","Ogranichitel!");
    }

    }
}

void MainWindow::point_clicked()
{   if(ui->label->text().length() < 15){
    if(!ui->label->text().contains(".")) {
        ui->label->setText(ui->label->text() + ".");
        }
    ui->pb_point->setEnabled(false);
    }
}

void MainWindow::pb_del_clicked()
{
    if(!(ui->label->text().contains('e'))){
    QString str = ui->label->text();
    str.chop(1);
    if(str.isEmpty() || str == "-"){
        str = "0";
    }
    ui->label->setText(str);

    if(!(ui->label->text().contains("."))){
        ui->pb_point->setEnabled(true);
        }
    }
}

void MainWindow::operations()
{
     QPushButton *pb = (QPushButton *)sender();
     double numbers;
     QString str;

     ui->pb_point->setEnabled(true);
     if(pb->text() == "+/-"){
         str = ui->label->text();
         if (str.startsWith('-')) {
             str.remove(0, 1);
             ui->label->setText(str);
         } else {
             ui->label->setText('-' + str);
         }
     } else if(pb->text() == "%"){
         numbers = (ui->label->text()).toDouble();
         numbers = numbers * 0.01;
         str = QString::number(numbers, 'g', 15);
         ui->label->setText(str);
     }
     if(!(ui->label->text().contains('.'))){
         ui->pb_point->setEnabled(true);
     }


}

void MainWindow::AC_clicked(){
    ui->label->setText("0");
    block_or_unblock(true);
    num_block(true);
    ui->pb_point->setEnabled(true);

}

void MainWindow::MathOperations(){

    operationID = 0;
    QPushButton *pb = (QPushButton *)sender();
    num1 = ui->label->text().toDouble();
    ui->label->setText(ui->label->text() + pb->text());

    if(pb->text() == "+"){
        block_or_unblock(false);
        ui->pb_point->setEnabled(false);
        operationID = PLUS;
    } else if(pb->text() == "-"){
        block_or_unblock(false);
        ui->pb_point->setEnabled(false);
        operationID = MINUS;
    } else if(pb->text() == "x"){
        block_or_unblock(false);
        ui->pb_point->setEnabled(false);
        operationID = MULT;
    } else if(pb->text() == "/"){
        block_or_unblock(false);
        ui->pb_point->setEnabled(false);
        operationID = DEL;
    }

    ui->label->setText("");

}

void MainWindow::equality_clicked(){
    block_or_unblock(true);
    double num2 = ui->label->text().toDouble();
    ui->pb_point->setEnabled(true);

    if(operationID == 3 && num2 == 0){
        ui->label->setText("Press AC");
        block_or_unblock(false);
        num_block(false);
        ui->pb_point->setEnabled(false);
        QMessageBox::warning(this,"ERROR","1000 berpi!");
    } else if(operationID != 0){
        operati calculate = {operationID,num1,num2};
        ui->label->setText(QString::number(mathresult(calculate), 'g', 15));
    }
}


