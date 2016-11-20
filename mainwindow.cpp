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

    options->setApiKey("your api key");
    options->setBaseUrl("https://sandbox-api.iyzipay.com");
    options->setSecretKey("your api secret");

    QSslConfiguration conf =QSslConfiguration::defaultConfiguration();
    conf.setProtocol(QSsl::SecureProtocols);
    QList<QSslCertificate> certifs = conf.caCertificates();

    //Caution! arrange path of certificates properly!
    //Otherwise "Sssl handshake failed" error might be thrown.
    QList<QSslCertificate> cert1 = QSslCertificate::fromPath("Certificates/iyzipay.crt");
    QList<QSslCertificate> cert2 = QSslCertificate::fromPath("Certificates/GeoTrustGlobalCA.crt");
    QList<QSslCertificate> cert3 = QSslCertificate::fromPath("Certificates/RapidSSLSHA256CA.crt");
    certifs.append(cert1);
    certifs.append(cert2);
    certifs.append(cert3);
    conf.setCaCertificates(certifs);
    QSslConfiguration::setDefaultConfiguration(conf);

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
    retrieveBinNumberRequest.setConversationId("12345678");
     binNumber = new BinNumber(this);

    connect(binNumber, SIGNAL(responseReady(QString)), this, SLOT(getResponse(QString)));
    QNetworkReply *response = binNumber->retrieve(&retrieveBinNumberRequest,options );



    connect(response, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));
    connect(response, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));

}

void MainWindow::getResponse(QString response){
    ui->jsonResultBrowser->setText(response);
    binNumber->deleteLater();
}

void MainWindow::slotError(QNetworkReply::NetworkError error){
    qDebug() <<"Network error no: "<<error;
}

void MainWindow::slotSslErrors(QList<QSslError> errors){
    QList<QSslError>::Iterator it = errors.begin();
    for(; it != errors.end(); ++it){
        qDebug() <<(*it).errorString();
    }

}
