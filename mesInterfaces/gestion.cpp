#include "gestion.h"
#include "ui_gestion.h"

Gestion::Gestion(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Gestion)
{
    ui->setupUi(this);
}

Gestion::~Gestion()
{
    delete ui;
}

