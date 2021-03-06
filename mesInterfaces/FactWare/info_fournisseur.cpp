#include "info_fournisseur.h"

info_fournisseur::info_fournisseur()
{
     identifiant=0;
     nom="";
     adresse="";
     telephone=0;
     email="";

}


info_fournisseur::info_fournisseur(int identifiant, QString nom, QString adresse, int telephone, QString email)
{
    this->identifiant = identifiant;
    this->nom=nom;
    this->adresse=adresse;
    this->telephone=telephone;
    this->email=email;
}


int info_fournisseur::get_identifiant(){return identifiant;}
QString info_fournisseur::get_nom(){return nom;}
QString info_fournisseur::get_adresse(){return adresse;}
int info_fournisseur::get_telephone(){return telephone;}
QString info_fournisseur::get_email(){return email;}






bool info_fournisseur::ajouter()
{
QSqlQuery query;
QString res= QString::number(identifiant);
query.prepare("INSERT INTO info_fournisseur (IDENTIFIANT, NOM, ADRESSE, TELEPHONE, EMAIL)"
                    "VALUES (:identifiant, :nom, :adresse, :telephone, :email)");
query.bindValue(":identifiant", res);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":telephone", telephone);
query.bindValue(":email", email);

return    query.exec();
}
