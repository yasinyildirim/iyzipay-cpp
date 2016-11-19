#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->binRequestButton, SIGNAL(clicked()), this, SLOT(onBinNumberRequested()));
    //set parent (owner) of options to "this" class
    options = new Options(this);
    options->setApiKey("Your Api Key");
    options->setBaseUrl("https://sandbox-api.iyzipay.com");
    options->setSecretKey("Your Api Secret");


}

MainWindow::~MainWindow()
{
    delete ui;
    //options member instance is deleted automatically by parent.
}

void MainWindow::onBinNumberRequested(){
    QString binCode = ui->binCode->toPlainText();
    RetrieveBinNumberRequest retrieveBinNumberRequest;

    retrieveBinNumberRequest.setBinNumber(binCode);
     binNumber = new BinNumber(this);
    connect(binNumber, SIGNAL(responseReady(QString)), this, SLOT(getResponse(QString)));
    QNetworkReply *response = binNumber->retrieve(&retrieveBinNumberRequest,options );


    /*
    connect(response, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(response, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));
            */
}

void MainWindow::getResponse(QString response){
    ui->jsonResultBrowser->setText(response);
    binNumber->deleteLater();
}
