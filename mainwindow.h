#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QWidget>
#include "ui_mainwindow.h"
#include <QCryptographicHash>
#include <QByteArray>

class MainWindow : public QWidget
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MainWindow();

private:
	Ui::MainWindowClass ui;
    QByteArray fileChecksum(const QString &, QCryptographicHash::Algorithm);
    QStringList items;

private slots:
    void handleBrowse();
    void handleStart();

};

#endif // MAINWINDOW_H
