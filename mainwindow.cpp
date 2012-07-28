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

    // Close the file.
    inFile->close();
}

void MainWindow::on_actionE_xit_triggered()
{
    // Close the application.
    close();
}

void MainWindow::on_action_Save_triggered()
{
    // Get a file name from a Save file dialog.
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save File...",
                                                    "/home",
                                                    "All Files (*.*)");

    // Open the file for output.
    QFile *outFile = new QFile(fileName);

    if (!outFile->open(QIODevice::WriteOnly | QIODevice::Text))
        return;

    // Send the text editor's plain text to the output stream.
    QTextStream out(outFile);
         out << ui->plainTextEdit->toPlainText();
}

void MainWindow::on_action_About_triggered()
{
    AboutDialog *aboutDialog = new AboutDialog(this);
    aboutDialog->show();
}
