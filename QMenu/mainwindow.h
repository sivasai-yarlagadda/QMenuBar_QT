#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFile>// For accessing the folders
#include <QTextStream>// Used for writing the content in the files
#include <QInputDialog>
#include <QDir> // For Directory checking
#include <QFileDialog>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_File_triggered();

    void on_actionOpen_File_triggered();

    void on_actionExit_File_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
