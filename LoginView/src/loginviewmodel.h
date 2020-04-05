#ifndef LOGINVIEWMODEL_H
#define LOGINVIEWMODEL_H

#include <QHash>
#include <QObject>
#include "loginview_global.h"

class QXmlStreamReader;
class QQmlApplicationEngine;

class LOGINVIEW_EXPORT LoginViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QStringList countryList READ countryList NOTIFY countryListChanged)
    Q_PROPERTY(int country READ country WRITE setCountry NOTIFY countryChanged)

public:
    explicit LoginViewModel(const QString modelName,
                            QObject *parent = nullptr);
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

public slots:
    void setCountry(int country);

signals:
    void countryChanged(int country);
    void countryListChanged();

private:
    int getCode(QXmlStreamReader &xml);
    QString getName(QXmlStreamReader &xml);

    bool parseCountry(QXmlStreamReader &xml);

    QString m_modelName;
    int m_country;
    QHash<int, QString> m_countryList;
};

#endif // LOGINVIEWMODEL_H
