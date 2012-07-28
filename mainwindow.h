#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QFileDialog>
#include <QPlainTextEdit>
#include <QtDebug>
#include <aboutdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_action_New_triggered();

    void on_action_Open_triggered();

    void on_actionE_xit_triggered();

    void on_action_Save_triggered();

    void on_action_About_triggered();

    void on_actionSelect_All_triggered();

    void on_action_Deselect_All_triggered();

private:
    Ui::MainWindow *ui;
    QTextCursor * crsr;
};

#endif // MAINWINDOW_H
