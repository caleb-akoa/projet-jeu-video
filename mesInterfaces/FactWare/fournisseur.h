#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H


#include <QDialog>

namespace Ui {
class fournisseur;
}

class fournisseur : public QDialog
{
    Q_OBJECT

public:
    explicit fournisseur(QWidget *parent = nullptr);
    ~fournisseur();

private slots:
    void on_ajouter_clicked();

private:
    Ui::fournisseur *ui;
};

#endif // FOURNISSEUR_H
