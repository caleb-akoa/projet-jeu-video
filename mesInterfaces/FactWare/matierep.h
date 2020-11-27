#ifndef MATIEREP_H
#define MATIEREP_H

#include <QDialog>

namespace Ui {
class matiereP;
}

class matiereP : public QDialog
{
    Q_OBJECT

public:
    explicit matiereP(QWidget *parent = nullptr);
    ~matiereP();




private:
    Ui::matiereP *ui;
};

#endif // MATIEREP_H
