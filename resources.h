#ifndef RESOURCES_H
#define RESOURCES_H

#include <QObject>
#include <QJsonObject>

#define SAND 1
#define WOOD 2
#define CLAY 4
#define STONE 5
#define SILVER 0

/*auteur: Nette Beckers
* klasse resources
* houdt bij hoeveel er van elke resources is
* functie read om gegevens in te lezen
*/

class resources : public QObject
{
    Q_OBJECT
public:
    explicit resources(int sand, int wood, int clay, int stone, int silver);

    int getSilver() const;
    int getWood() const;
    int getSand() const;
    int getStone() const;
    int getClay() const;

    virtual void setResource(int number, int resource);

    virtual void read(QJsonObject json);

protected:
    int m_sand;
    int m_wood;
    int m_clay;
    int m_stone;
    int m_silver;

};

#endif // RESOURCES_H
