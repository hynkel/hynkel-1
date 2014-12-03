#ifndef LIB_H
#define LIB_H

#include <QString>
#include <stdexcept>

  // KLASA WYJĄTKU RZUCANA PRZEZ PARSER
class NotFound : public std::runtime_error
{
public:
  NotFound(const QString & m = "Nie znaleziono.") :
    runtime_error(m.toUtf8().constData()){};
};

QString znajdz(const QString & line, const QString & przed, const QString & po) throw (NotFound);
unsigned long potegaDzies(int wykl);
//unsigned long strToULong(const QString & in);

#endif // LIB_H
