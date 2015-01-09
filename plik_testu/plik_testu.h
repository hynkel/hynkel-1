#ifndef PLIK_TESTU_H
#define PLIK_TESTU_H

#include <QObject>

#include <QPair>
#include <QDate>
#include <QString>
#include <QVector>

typedef QPair<QString, QString> slowo;

class plik_testu : public QObject
{
  Q_OBJECT
public:
  explicit plik_testu(QObject *parent = 0);
  //TODO: 0: Jakos dobrze wymyslic wczytywanie

  // GETY
  QString get_test(void) { return test; }
  QDate get_data(void) { return data; }
  QString get_opis(void) { return opis; }
  QString get_pierwsza(void) { return pierwsza; }
  QString get_druga(void) { return druga; }

  // SETY
  void set_test(QString t) { test = t; }

private:
  QVector<slowo> slowa;
  QString test;
  QDate data;
  QString opis;
  QString pierwsza;
  QString druga;

  /*----------------------------------------------------------------------
   * Opis:
   * - slowa - wektor słów należących do testu. Słowo jest parą QStringów
   * - test - nazwa testu
   * - data - data ostatniej modyfikacji
   * - opis - krótki opis testu
   * - pierwsza - określa, co znajduje się w pierwszej kolumnie
   * - druga - określa, co znajduje się w drugiej kolumnie
   *--------------------------------------------------------------------*/
  //NOTE: Zdecydowac, czy data okresla date utworzenia, czy ostatniej modyfikacji



  //   KONCEPCJA PLIKU:
  /*---------------------------------------------------------------------
   * - KAŻDA INFORMACJA W INNEJ LINII
   * - INFORMACJE ODNOŚNIE TESTU ZAPISYWANE SĄ W ZMIENNYCH POSTACI:
   *     $nazwa [biały znak] "wartość"
   * - nazwę opcji od wartości rozdziela co najmniej jeden biały znak
   * - słowa w teście zapisywane są między znacznikami:
   *     $vocab
   *       "koza" "goat"
   *     // tutaj słownictwo
   *     $end_vocab
   * - białe znaki niebędące wewnątrz znaczników są ignorowane
   *   z wyjątkiem pary słowo-tłumaczenie - musi być w jednej linii
   *-------------------------------------------------------------------*/

signals:

public slots:

};

#endif // PLIK_TESTU_H
