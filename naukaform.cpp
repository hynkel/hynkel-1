#include "naukaform.h"
#include "ui_naukaform.h"

#include <QtCore>
#include <QStringList>
#include <QStandardItemModel>

naukaForm::naukaForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::naukaForm)
{
  ui->setupUi(this);
}

naukaForm::~naukaForm()
{
  delete ui;
}

void naukaForm::on_button_wczytaj_clicked()
{
  qDebug() << "nacisnieto przycisk wczytaj" << endl;
  QStandardItemModel mod;
  for( int i = 0; i < 2; i++)
  {
    QStandardItem * item = new QStandardItem(QString("row %0").arg(i));
    mod.setItem(i, item);
  }
    //ui->columnView->setModel(&mod);
    ui->tableView->setModel(&mod);
}
