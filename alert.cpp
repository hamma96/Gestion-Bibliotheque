#include "alert.h"
#include "ui_alert.h"
#include<database.h>
#include <QtSql>
#include <QDebug>
#include <QDir>
#include <QSqlQueryModel>
alert::alert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::alert)
{
    ui->setupUi(this);
    id1=id11;
    dbConnect();
    QSqlQuery qry;


    QSqlQueryModel *model= new QSqlQueryModel();
    qry.prepare("SELECT * FROM taked WHERE (etudiant_id LIKE :Userid) AND (date_rendre BETWEEN datetime('now','start of day','-2 month','-1 day') AND datetime('now')) ");
    qry.bindValue(":Userid", id1);
    qry.exec();
    model->setQuery(qry);
    ui->Book->setModel(model);
    ui->Book->horizontalHeader()->setSectionResizeMode( QHeaderView::Stretch);
    dbclose();
}

alert::~alert()
{
    delete ui;
}

void alert::on_Book_activated(const QModelIndex &index)
{

}
