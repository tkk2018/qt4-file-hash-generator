#include "mainwindow.h"
#include <QFileDialog>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
	: QWidget(parent, flags)
{
	ui.setupUi(this);
    items << "Md4" << "Md5" << "Sha1";
    ui.cb_hash_type->addItems(items);
    ui.cb_hash_type->
    connect(ui.pb_browse, SIGNAL(clicked()), this, SLOT(handleBrowse()));
    connect(ui.pb_start, SIGNAL(clicked()), this, SLOT(handleStart()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::handleBrowse() 
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QStringList fileNames;
    if (dialog.exec()) {
        fileNames = dialog.selectedFiles();
        ui.le_path->setText(fileNames.at(0));
    }
}

void MainWindow::handleStart()
{
    QFile f(ui.le_path->text());
    if (!f.exists()) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error");
        msgBox.setText("File does't exist.");
        msgBox.exec();
        return;
    }
    
    int selected = ui.cb_hash_type->currentIndex();
    QCryptographicHash::Algorithm hashType = (QCryptographicHash::Algorithm) selected;
    QByteArray hash = fileChecksum(ui.le_path->text(), hashType);
    QString checksum = QString(hash.toHex());
    QString display = items.at(selected) + ":-" + f.fileName() + "\n" + checksum + "\n";
    ui.te_result->append(display);
}

QByteArray MainWindow::fileChecksum(const QString &fileName, QCryptographicHash::Algorithm hashAlgorithm)
{
    QFile f(fileName);
	qint64 fileSize = f.size();
    const qint64 bufferSize = 10240;
    if (f.open(QFile::ReadOnly)) {
		char buffer[bufferSize];
        int bytesRead;
        int readSize = qMin(fileSize, bufferSize);
        QCryptographicHash hash(hashAlgorithm);
        while (readSize > 0 && (bytesRead = f.read(buffer, readSize)) > 0) {
            fileSize -= bytesRead;
            hash.addData(buffer, bytesRead);
            readSize = qMin(fileSize, bufferSize);
        }
		f.close();
		return hash.result();
    }
    return QByteArray();
}