#include "naukaform.h"
#include "ui_naukaform.h"

// NAGŁÓWKI Z BIBLIOTEKI
#include <QtCore>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>

// NAGŁÓWKI MOICH PLIKÓW:
#include "plik_testu/plik_testu.h"

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
  QString nazwa = QFileDialog::getOpenFileName(this, "Testowe - nagłówek", "/home/ser/Qt");
  qDebug() << "Wybrano " << nazwa << endl;
  plik_testu tescik;
  QFile plik(nazwa);
  if ( plik.open(QFile::ReadOnly) )
  {
    QTextStream plik_strumienia(&plik);
    QString linia;
    do
    {
      plik_strumienia >> linia;
      if ( linia[0] == '$' )
      {
        QStringRef porownanie(&linia, 1, linia.length() - 1);
        if ( ! porownanie.compare("test", Qt::CaseInsensitive) )
        { //NOTE: Mozna zmienic, zeby nie byl czuly na wielkosc znakow - na razie mnie to wali
          qDebug() << "znaleziono test" << endl;
          QString wartosc;
          plik_strumienia >> wartosc;
          tescik.set_test( wartosc.mid(1, wartosc.length() - 2) );
          qDebug() << "wartosc to " << tescik.get_test() << endl;
        }
        else if ( ! porownanie.compare("date", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono date" << endl;
        }
        else if ( ! porownanie.compare("desc", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono desc" << endl;
        }
        else if ( ! porownanie.compare("first", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono first" << endl;
        }
        else if ( ! porownanie.compare("sec", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono sec" << endl;
        }
        else if ( ! porownanie.compare("vocab", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono vocab" << endl;
        }
        else if ( ! porownanie.compare("end_vocab", Qt::CaseInsensitive ) )
        {
          qDebug() << "znaleziono end_vocab" << endl;
        }
        else
        {
          qDebug() << "Nieznany znacznik." << endl;
        }
      }
    } while ( linia != "$now_the_very_end" );
  }
}
