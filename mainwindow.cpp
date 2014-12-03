#include <QtGui>
#include <QMessageBox>
#include <QString>
#include <QTextCodec>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "naukaform.h"

MainWindow::MainWindow(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::MainWindow),
  naukaFormPtr(0),
  edytorFormPtr(0)
{
  //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
  ui->setupUi(this);

  createActions();
  createMenus();
}

MainWindow::~MainWindow()
{
  if ( naukaFormPtr ) delete naukaFormPtr;
  naukaFormPtr = 0;
}

void MainWindow::createActions()
{
  // NAUKA MENU
  naukaAct = new QAction("Nauka", this);
  connect(naukaAct, SIGNAL(triggered()), this, SLOT(nauka()));

  // EDYTOR MENU
  edytornowyAct = new QAction("Nowy", this);
  connect(edytornowyAct, SIGNAL(triggered()), this, SLOT(edytornowy()));
  edytorotworzAct = new QAction("Otworz", this);
  connect(edytorotworzAct, SIGNAL(triggered()), this, SLOT(edytorotworz()));

  // POMOC MENU
  aboutAct = new QAction("O programie", this);
  connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
  dokuAct = new QAction("Dokumentacja", this);
  connect(dokuAct, SIGNAL(triggered()), this, SLOT(doku()));
  licenceAct = new QAction("Licencja", this);
  connect(licenceAct, SIGNAL(triggered()), this, SLOT(licence()));
  aboutqtAct = new QAction("O Qt", this);
  connect(aboutqtAct, SIGNAL(triggered()), this, SLOT(aboutqt()));
}


void MainWindow::createMenus()
{
  naukaMenu = menuBar()->addMenu("Nauka");
  naukaMenu->addAction(naukaAct);

  edytorMenu = menuBar()->addMenu("Edytor");
  edytorMenu->addAction(edytornowyAct);
  edytorMenu->addAction(edytorotworzAct);

  pomocMenu = menuBar()->addMenu("Pomoc");
  pomocMenu->addAction(aboutAct);
  pomocMenu->addAction(dokuAct);
  pomocMenu->addAction(licenceAct);
  pomocMenu->addAction(aboutqtAct);
}

void MainWindow::nauka()
{

   if ( ! naukaFormPtr ) naukaFormPtr = new naukaForm();
  naukaFormPtr->show();
}

void MainWindow::edytornowy()
{
  QMessageBox::question(this, "", "Otwieranie nowego testu. Niy funguje.", QMessageBox::Yes);
}

void MainWindow::edytorotworz()
{
  QMessageBox::question(this, "", "Otwieranie testu. Niy funguje.", QMessageBox::Yes);
}

void MainWindow::about()
{
  QMessageBox::question(this, "", "O programie. Niy funguje.", QMessageBox::Yes);
}

void MainWindow::doku()
{
  QMessageBox::question(this, "", "Doku. Niy funguje.", QMessageBox::Yes);
}

void MainWindow::licence()
{
  QMessageBox::question(this, "", "Licencja. Niy Funguje.", QMessageBox::Yes);
}

void MainWindow::aboutqt()
{
  QMessageBox::question(this, "", "O Qt. Niy funguje.", QMessageBox::Yes);
}
