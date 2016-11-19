#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "options.h"
#include <QNetworkReply>
#include "binnumber.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
signals:

public slots:
    void onBinNumberRequested();
    void getResponse(QString);
private:
    Ui::MainWindow *ui;
    Options* options;
    BinNumber *binNumber;
};

#endif // MAINWINDOW_H
