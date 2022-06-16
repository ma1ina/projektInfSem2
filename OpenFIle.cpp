#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QString>
#include <QFileDialog>

void MainWindow::setTextFromFile(QString id){
    QString fname = QFileDialog::getOpenFileName(this);
    QFile file(fname);

    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->textEdit->setText(ReadFile.readAll());
    file.close();
}
