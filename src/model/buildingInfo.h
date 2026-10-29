#ifndef BUILDINGINFO_H
#define BUILDINGINFO_H

#include <QObject>
#include <QJsonObject>

/*auteur: Nette Beckers
* klasse buildingInfo
* houdt alle informatie van een building bij
* heeft een read functie om gegevens in te lezen
*/

class buildingInfo :  public QObject
{
    Q_OBJECT    
public:
    explicit buildingInfo(int resources, int points, int available, QString name);

    int getResources() const;
    int getPoints() const;
    int getAvailable() const;
    QString getName() const;
    void setAvailable();
    bool getBuildOrNot() const;

    void read(QJsonObject json);

private:
    const int m_numberOfResources;
    const int m_points;
    const QString m_name;
    int m_available;
    bool m_status{true};
};

#endif // BUILDINGINFO_H
