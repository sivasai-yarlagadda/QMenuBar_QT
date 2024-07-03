#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->displaylabel->hide();
    ui->contentlabel->hide();
    QMainWindow mainWindow;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_File_triggered()
{
    qDebug()<<"Clicked New File Icon";

    // QString fileName = "C:/Users/Sivasai/Desktop/SivaQT/QMenu/QMenu/hello.txt"; // Replace with your desired file path for statically giving the filename.


    // Ask user for file name
    QString directory = "./TextDocuments/"; // Relative directory path

    // Create directory if it doesn't exist
    QDir dir(directory);
    if (!dir.exists()) {
        if (!dir.mkpath(".")) {
            qDebug() << "Failed to create directory:" << directory;
        }
        qDebug() << "Directory created:" << directory;
    }



    // Taking input of the filename with extension of the file.
    QString fileName = QInputDialog::getText(this, "Enter File Name with extension of the file", "File Name:");

    QString totalfilepath = directory+fileName ;
    qDebug()<<totalfilepath;
    // Checking if the name of the file is empty or not.
    if (totalfilepath.isEmpty())
    {
        QMessageBox::warning(this, "Error", "Filepath or  Filename cannot be empty.");
        return;
    }

    // Ask user for file content
    QString fileContent = QInputDialog::getText(this, "Enter File Content", "File Content:");
    qDebug()<<fileContent;
    QFile file(totalfilepath);

    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << fileContent;
        file.close();

        qDebug() << "File created successfully in location : " << totalfilepath;
        QMessageBox::information(this, "Success", "File created successfully.");
    }
    else
    {
        qDebug() << "Could not create file: " << totalfilepath;
        QMessageBox::critical(this, "Error", "Could not create file.");
    }


}



void MainWindow::on_actionOpen_File_triggered()
{
    //To open the directory and to see the files and access the files.
    QString filePath = QFileDialog::getOpenFileName(nullptr,
                                                    QObject::tr("Open File"),
                                                    QDir::currentPath(),
                                                    QObject::tr("All Files (*)"));

    QString fileContent;

    // Checking the file is selected or not , if selected then the condition applies.
    if (!filePath.isEmpty()) {
        qDebug() << "Selected file:" << filePath;

        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            fileContent = in.readAll();
            qDebug().noquote() << "File content:";
            qDebug().noquote() << fileContent;

            // Display file content in a message box
            QMessageBox::information(nullptr, "File Content", fileContent);


            // Assigning and Displaying the content in the UI.
            ui->displaylabel->setText("<h1> File path : </h1>"+filePath);
            ui->contentlabel->setText("<h2>Contents of the file :</h2>" + fileContent);
            ui->displaylabel->show();
            ui->contentlabel->show();

            file.close();
        } else {
            qDebug() << "Failed to open file:" << filePath;
            QMessageBox::critical(nullptr, "Error", "Failed to open file.");
        }
    } else {
        qDebug() << "No file selected.";
    }


}


void MainWindow::on_actionExit_File_triggered()
{
    QCoreApplication::exit();
}

