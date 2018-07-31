#include "database.h"
#include <QDebug>
#include <QFileInfo>
#include <QDir>


Database::Database()
{
     //path = "/home/hamma/Project/qt/Gestion_Bibliotheque/Gestion";
     path = "../Gestion_Bibliotheque/Gestion";
}

bool Database::dbConnect(){ // connect to the base
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path);

    if (!db.open()){
        qDebug() << "error connection ";
        return false;
    }else{
        qDebug() << "connected ";
        return true;
    }
}

void Database::dbclose(){ // deconnect from the base

    QString connection;
    connection = db.connectionName();
    db.close();
    db = QSqlDatabase();
    db.removeDatabase(connection);

}
