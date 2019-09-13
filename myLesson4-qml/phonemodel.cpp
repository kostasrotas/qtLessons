#include "phonemodel.h"
#include <QQmlContext>

PhoneModel::PhoneModel()
{
}

const QHash<int,QByteArray> PhoneModel::RoleNames
{
    {PhoneModel::PhoneNameRole,    "phoneName"},
    {PhoneModel::PhoneTelephoneRole,   "phoneTelephone"},
};

void PhoneModel::setStartData()
{
    QStandardItem *item;
    item=new QStandardItem("<b>Name</b>");
    item->setData("<b>Tel. Nubmer</b>",PhoneTelephoneRole);
    setItem(0,item);

}

void PhoneModel::addPersonData(QString name,QString tel)
{
    QStandardItem *item;
    if (name!="")
    {
        item=new QStandardItem(name);
        item->setData(tel,PhoneTelephoneRole);
        setItem(rowCount(),item);
    }
}

void PhoneModel::updateCounter()
{
    mainQmlComp->setProperty("totalTextValue", rowCount()-1);
}

QHash<int,QByteArray> PhoneModel::roleNames() const
{
    return RoleNames;
}
