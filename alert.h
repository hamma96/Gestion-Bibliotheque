#ifndef ALERT_H
#define ALERT_H
#include<database.h>
#include <QDialog>

namespace Ui {
class alert;
}

class alert : public QDialog, protected Database
{
    Q_OBJECT

public:
    explicit alert(QWidget *parent = 0);
    ~alert();

private slots:
    void on_Book_activated(const QModelIndex &index);

private:
    Ui::alert *ui;
    QString id1;
};

#endif // ALERT_H
