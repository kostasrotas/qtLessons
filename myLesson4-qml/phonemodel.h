#ifndef PHONEMODEL_H
#define PHONEMODEL_H

#include <QStandardItemModel>

class PhoneModel : public QStandardItemModel
{
    Q_OBJECT

    //Expose C++ variable to qml
    Q_PROPERTY(QString phoneModelTitleStr MEMBER phoneModelTitle)
    // Or using functions getPhoneModelTitle and setPhoneModelTitle and signal phoneModelTitleChanged
    //Q_PROPERTY(QString phoneModelTitleStr READ getPhoneModelTitle WRITE setPhoneModelTitle NOTIFY phoneModelTitleChanged)
    QString phoneModelTitle="PHONES";

public:

    enum Roles {
        PhoneNameRole = Qt::DisplayRole,
        PhoneTelephoneRole = Qt::UserRole + 1
    };

    QHash<int,QByteArray> roleNames() const Q_DECL_OVERRIDE;

    PhoneModel();
    void setStartData();
    Q_INVOKABLE void addPersonData(QString name,QString tel);
    Q_INVOKABLE void updateCounter();

private:
    static const QHash<int,QByteArray> RoleNames;
};

extern QObject *mainQmlComp;

#endif // PHONEMODEL_H
