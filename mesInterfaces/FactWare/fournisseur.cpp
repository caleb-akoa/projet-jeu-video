#include "fournisseur.h"
#include "ui_fournisseur.h"
#include <QMessageBox>
#include "info_fournisseur.h"

fournisseur::fournisseur(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fournisseur)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton_1, SIGNAL(clicked() ), this, SLOT(reject() ));
   // QObject::connect(ui->pushButton_2, SIGNAL(clicked() ), this, SLOT(reject() ));
    QObject::connect(ui->pushButton_3, SIGNAL(clicked() ), this, SLOT(reject() ));
    QObject::connect(ui->pushButton_4, SIGNAL(clicked() ), this, SLOT(reject() ));


}

fournisseur::~fournisseur()
{
    delete ui;
}


void fournisseur::on_ajouter_clicked()
{
    int identifiant = ui->lineEdit_identifiantF->text().toInt();
    QString nom =  ui->lineEdit_nomF->text();
    QString adresse =  ui->lineEdit_adresseF->text();
    int telephone =  ui->lineEdit_telephoneF->text().toInt();
    QString email =  ui->lineEdit_emailF->text();

    info_fournisseur f(identifiant,nom,adresse,telephone,email);
    bool test = f.ajouter();
     if(test)
     {

         QMessageBox::critical(nullptr, QObject::tr("ajout du fournisseur"),
                     QObject::tr("ajout avec succes.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);


     }
       else
           QMessageBox::critical(nullptr, QObject::tr("ajouter un fournisseur"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}
