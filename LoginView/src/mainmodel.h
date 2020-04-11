#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <QHash>
#include <QObject>
#include "loginview_global.h"
#include "userdata.h"

class QXmlStreamReader;
class QQmlApplicationEngine;
class CountrysParser;

namespace LoginView {


class LOGINVIEW_EXPORT MainModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList countryList READ countryList NOTIFY countryListChanged)
    Q_PROPERTY(int country READ country WRITE setCountry NOTIFY countryChanged)
    Q_PROPERTY(UserData data READ data WRITE setData NOTIFY dataChanged)

public:
    explicit MainModel(const QString modelName,
                            QObject *parent = nullptr);
    ~MainModel();
    /**
     * @brief setCounrySource - sets path to xml source file and extract list of countrys
     * @param path
     * @return true if the function finished successful
     */
    Q_INVOKABLE bool setCounrySource(const QString &path);

    /**
     * @brief init - prepare all items for use on qml.
     * @param engine - current qml engine of application
     * @return true if the function finished successful
     */
    bool init(QQmlApplicationEngine *engine);

    int country() const;
    QStringList countryList() const;
    UserData data() const;

public slots:
    void setCountry(int country);

    void setData(UserData data);

signals:
    void countryChanged(int country);
    void countryListChanged();
    void sigLoginRequest(UserData);
    void sigRegisterRequest(UserData);

    void dataChanged(UserData data);

private:

    bool isValidData(const UserData &data);

    CountrysParser *m_countrysParser = nullptr;
    QString m_modelName;
    int m_country;
    QHash<int, QString> m_countryList;
    UserData m_data;
};

}
#endif // LOGINVIEWMODEL_H
