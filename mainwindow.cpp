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

void MainWindow::on_action_New_triggered()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_action_Open_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Configuration File.",
                                                    "/home",
                                                    "All Files (*.*)");
    qDebug() << fileName;
    QFile *inFile = new QFile(fileName);

    if (!inFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QString buf;
    while (!inFile->atEnd()) {
        buf.append(inFile->readLine());
    }

    ui->plainTextEdit->insertPlainText(buf);
}
