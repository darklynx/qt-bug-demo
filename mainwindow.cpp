#include "mainwindow.h"
#include "mydialog.h"
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

void MainWindow::on_actionTest_triggered()
{
    bool accepted = false;
    if (true) {
        MyDialog dlg(this);
        accepted = (dlg.exec() == QDialog::Accepted);
    }

    if (accepted) {
        ui->listWidget->addItem("Pressed OK");
    } else {
        ui->listWidget->addItem("Pressed Cancel");
    }
}
