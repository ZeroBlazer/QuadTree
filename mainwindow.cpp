#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openButton_clicked()
{
    QuadImageTree my_tree;
    my_tree.loadImage(ui->lineEdit->text());
    my_tree.loadQTree();                        //Para volver a cargar la imagen desde el quadTree
    my_tree.paint(ui->lbl_drawer);
}

void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit->setText(
                QFileDialog::getOpenFileName(this, tr("Open File"),ui->lineEdit->text()));
}

void MainWindow::on_pushButton_2_clicked()
{
    QuadImageTree my_tree;
    my_tree.loadQTreeFromFile();
    my_tree.paint(ui->lbl_drawer);
}
