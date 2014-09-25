#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QAction>

namespace Ui {
  class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  Ui::MainWindow *ui;
  void createActions();
  void createMenus();
  // OBIEKTY DO OBSŁUGI MENU
  QMenu * naukaMenu;
  QMenu * edytorMenu;
  QMenu * pomocMenu;
  QAction * naukaAct;
  QAction * edytornowyAct;
  QAction * edytorotworzAct;
  //QAction * edytorAct;
  QAction * aboutAct;
  QAction * dokuAct;
  QAction * licenceAct;
  QAction * aboutqtAct;

  // OKNO DO OTWIERANIA TESTU
  QWidget * naukaFormPtr;       // DO WCZYTYWANIA TESTÓW
  QWidget * edytorFormPtr;      // DO TWORZENIA TESTÓW

private slots:
  void nauka();
  void edytornowy();
  void edytorotworz();
  void about();
  void doku();
  void licence();
  void aboutqt();

};

#endif // MAINWINDOW_H
