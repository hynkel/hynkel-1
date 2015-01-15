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
  QString get_test(void) const { return test; }
  QDate get_data(void) const { return data; }
  QString get_opis(void) const { return opis; }
  QString get_pierwsza(void) const { return pierwsza; }
  QString get_druga(void) const { return druga; }

  QString get_data_string(void) const { return data.toString("yyyy.MM.dd"); }

  // SETY
  void set_test(QString t) { test = t; }
  void set_data(QDate d) { data = d; }
  void set_opis(QString t) { opis = t; }
  void set_pierwsza(QString t) { pierwsza = t; }
  void set_druga(QString t) { druga = t; }

  void dodaj_slowo(QString pierwsza, QString druga);
  void dodaj_slowo(slowo & s);

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
   * - słowa w teście zapisywane są w jednej linii, np.
   *     "koza" "goat"
   *   Muszą być rozdzielone białym znakiem. Mogą być w dowolnym miejscu
   *   testu. Zakładam, że słowa są parami (nie ma słów nie do pary).
   * - białe znaki niebędące wewnątrz znaczników są ignorowane
   *   z wyjątkiem pary słowo-tłumaczenie - musi być w jednej linii
   *-------------------------------------------------------------------*/

signals:

public slots:

};

#endif // PLIK_TESTU_H
