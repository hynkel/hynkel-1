#include "naukaform.h"
#include "ui_naukaform.h"

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
