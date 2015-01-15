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
  QString nazwa = QFileDialog::getOpenFileName(this, "Testowe - nagłówek", "/home/ser/Qt/hynkel");
  qDebug() << "Wybrano " << nazwa << endl;

  // TUTAJ TWORZE PLIK TESTU
  plik_testu tescik;

  QFile plik(nazwa);
  if ( plik.open(QFile::ReadOnly) )
  {
    QTextStream plik_strumienia(&plik);
    QString linia;
    QString wartosc;
    do
    {
      plik_strumienia >> linia;
      if ( linia[0] == '$' )
      {
        QStringRef porownanie(&linia, 1, linia.length() - 1);

        // TUTAJ ZACZYNA SIĘ ANALIZA
        if ( ! porownanie.compare("test", Qt::CaseInsensitive) )
        {
          plik_strumienia >> wartosc;
          tescik.set_test( wartosc.mid(1, wartosc.length() - 2) );
        }
        else if ( ! porownanie.compare("date", Qt::CaseInsensitive ) )
        {
          plik_strumienia >> wartosc;
          int y, m, d;
          y = wartosc.mid(1, 4).toInt();
          m = wartosc.mid(6, 2).toInt();
          d = wartosc.mid(9, 2).toInt();
          tescik.set_data( QDate(y, m, d) );
        }
        else if ( ! porownanie.compare("desc", Qt::CaseInsensitive ) )
        {
          plik_strumienia >> wartosc;
          tescik.set_opis( wartosc.mid(1, wartosc.length() - 2) );
        }
        else if ( ! porownanie.compare("first", Qt::CaseInsensitive ) )
        {
          plik_strumienia >> wartosc;
          tescik.set_pierwsza( wartosc.mid(1, wartosc.length() - 2) );
        }
        else if ( ! porownanie.compare("sec", Qt::CaseInsensitive ) )
        {
          plik_strumienia >> wartosc;
          tescik.set_druga( wartosc.mid(1, wartosc.length() - 2) );
        }
        else if ( ! porownanie.compare("word", Qt::CaseInsensitive ) )
        {
          qDebug() << linia << endl;
          plik_strumienia >> wartosc;
          qDebug() << wartosc << endl;
          // NOTE: Kolene lewe rozwiazanie: najpierw pobieram jeden argument poza ifem, a teraz drugi w ifie.
          QString pierwsze = wartosc.mid(1, wartosc.length() - 2 );
          plik_strumienia >> wartosc;
          qDebug() << wartosc << endl;
          QString drugie = wartosc.mid(1, wartosc.length() - 2 );
          slowo s(pierwsze, drugie);
          qDebug() << "skonstruowane slowo :" << s << endl;
          tescik.dodaj_slowo(pierwsze, drugie);
        }
        else
        {
          // NOTE: strasznie lewe rozwiazanie, ale chce zostawic znacznik now_the_very_end
          if ( linia.mid(1, linia.length() - 1 ) == "now_the_very_end" ) break;
          qDebug() << "Nieznany znacznik:" << endl;
          qDebug() << "    linia = " << linia << endl << "    wartosc = " << wartosc << endl;
        }
      }
    } while ( linia != "$now_the_very_end" );
  }
  QApplication::quit();
}
