#ifndef DEFENCETOWER_H
#define DEFENCETOWER_H

#include "resources.h"

/*auteur: Nette Beckers
* klasse defenceTower
* afgeleid van resources
* heeft eigen signalen voor naar defenceTowerView te sturen om te updaten
* functie read om gegevens in te lezen
*/

class defenceTower : public resources
{
    Q_OBJECT
public:
    explicit defenceTower(int sand = 1, int wood = 1, int clay = 1, int stone = 1, int silver = 1);

    int getNumberOfReource(int resource) const;

    virtual void setResource(int number, int resource) override;
    virtual void read(QJsonObject json) override;

signals:
    void updateResources();
};

#endif // DEFENCETOWER_H
