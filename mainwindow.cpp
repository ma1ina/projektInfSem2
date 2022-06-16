#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>
#include <QtCore>
#include <QtGui>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Przelicznik składników");

   QVBoxLayout *lay = new QVBoxLayout(this);

   int iloscPrzepisow=10;
   QPushButton* przyciskPrzepisy[iloscPrzepisow];
   for(int i=0;i<iloscPrzepisow;i++){
       QString * przepisNazwa = new QString("Przepis "+QString::number(i));
       przyciskPrzepisy[i] = new QPushButton(*przepisNazwa);
       lay -> addWidget(przyciskPrzepisy[i]);
   }
   ui->scrollAreaWidgetContents->setLayout(lay);


   for(int i=0;i<iloscPrzepisow;i++){
       QObject::connect(przyciskPrzepisy[i],&QPushButton::clicked,this,&MainWindow::handleButton);
   }

}




MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
  QMessageBox::StandardButton reply = QMessageBox::question(this, "Zamknij", "Czy na pewno chcesz zamknąć program?", QMessageBox::Yes | QMessageBox::No );
  if(reply ==QMessageBox::Yes)
  {
      QApplication::quit();
  }

}
void MainWindow::handleButton(){
    QPushButton * sButton=qobject_cast<QPushButton *>(sender());
    QString id=sButton->text();
    setTextFromFile(QString("test"));
}

