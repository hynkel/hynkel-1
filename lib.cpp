#include "lib.h"

#include <QString>

QString znajdz(const QString & line, const QString & przed, const QString & po) throw (NotFound)
{
  QString s;
  for( int i = 0; i < line.size(); i++)
  {
    if ( line.mid( i, przed.size()) == przed )
      for( int j = i + przed.size(); j < line.size(); j++ )
        if ( line.mid( j, po.size() ) == po )
          return line.mid( i + przed.size(), j - i - przed.size());
  }
  throw NotFound("Blad: Nie znaleziono: " + przed + po + ".");
}

unsigned long potegaDzies(int wykl)
{
  if ( wykl == 0) return 1;
  return ( 10 * potegaDzies( wykl - 1) );
}

/*
unsigned long strToULong(const QString & in)
{
  unsigned long res = 0;
  for( int i = 0; i < static_cast<int>(in.size()); i++ )
    res += ( in[i].toAscii() - '0' ) * potegaDzies( in.size() - i - 1 );
  return res;
}
*/
