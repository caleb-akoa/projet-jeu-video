#include "matierep.h"
#include "ui_matierep.h"
#include "dialog.h"
matiereP::matiereP(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::matiereP)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(reject()));
     QObject::connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(reject()));
      QObject::connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(reject()));
       QObject::connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(reject()));
        QObject::connect(ui->pushButton_10, SIGNAL(clicked()), this, SLOT(reject()));
}

matiereP::~matiereP()
{
    delete ui;
}
