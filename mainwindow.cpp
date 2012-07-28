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
    //Clear the page.
    ui->plainTextEdit->clear();
}

void MainWindow::on_action_Open_triggered()
{
    // Get a file name from an Open file dialog.
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    "Open Configuration File.",
                                                    "/home",
                                                    "All Files (*.*)");
    // Open the file
    QFile *inFile = new QFile(fileName);

    if (!inFile->open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    // Write the file to a QString
    QString buf;

    while (!inFile->atEnd()) {
        buf.append(inFile->readLine());
    }

    // Put the QString into the text editor window.
    ui->plainTextEdit->insertPlainText(buf);
}

void MainWindow::on_actionE_xit_triggered()
{
    this->close();
}
