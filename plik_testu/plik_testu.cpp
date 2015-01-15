#include "plik_testu.h"

plik_testu::plik_testu(QObject *parent) :
  QObject(parent)
{
}

void plik_testu::dodaj_slowo(QString pierwsza, QString druga)
{
  slowa.push_back( slowo(pierwsza, druga) );
}

void plik_testu::dodaj_slowo(slowo & s)
{
  slowa.push_back(s);
}
