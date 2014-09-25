#ifndef NAUKAFORM_H
#define NAUKAFORM_H

#include <QWidget>

namespace Ui {
  class naukaForm;
}

class naukaForm : public QWidget
{
  Q_OBJECT

public:
  explicit naukaForm(QWidget *parent = 0);
  ~naukaForm();

private:
  Ui::naukaForm *ui;
};

#endif // NAUKAFORM_H
