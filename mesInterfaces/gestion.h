#ifndef GESTION_H
#define GESTION_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Gestion; }
QT_END_NAMESPACE

class Gestion : public QMainWindow
{
    Q_OBJECT

public:
    Gestion(QWidget *parent = nullptr);
    ~Gestion();

private:
    Ui::Gestion *ui;
};
#endif // GESTION_H
