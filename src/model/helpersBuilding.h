#ifndef HELPERSBUILDING_H
#define HELPERSBUILDING_H

#include <QJsonArray>

#include "building.h"

#define HELPER_POINTS_KEEP 14
#define HELPER_POINTS_PALACE 17
#define HELPER_POINTS_SMALL_GATE 5
#define HELPER_POINTS_BIG_GATE 10
#define HELPER_POINTS_SERVANTS_HOUSE_A 6
#define HELPER_POINTS_SERVANTS_HOUSE_B 7
#define HELPER_POINTS_SERVANTS_HOUSE_C 8
#define HELPER_POINTS_FORGE_A 6
#define HELPER_POINTS_FORGE_B 10
#define HELPER_POINTS_STABLE_A 12
#define HELPER_POINTS_STABLE_B 16
#define HELPER_POINTS_TAVERN_A 6
#define HELPER_POINTS_TAVERN_B 12
#define HELPER_POINTS_MARKET 6
#define NUMBER_OF_HELPERS 16

/*auteur: Nette Beckers
* klasse helpersBuilding
* houdt bij welke speler op welke helpersplek staat
* zo kan makelijk de einstand berekent worden
* functie read om gegevens in te lezen
*/

class helpersBuilding : public building
{
    Q_OBJECT
public:
    enum BUILDING_FOLLOW_NUMBER{KEEP, PALACE, SMALLGATE, BIGGATE, SERVANTSHOUSE, FORGE, STABLE, TAVERN, MARKET};

    explicit helpersBuilding();

    void setPlayerHelper(int player);
    void setHelper(int building, int number);

    int endPointsHelpers(int player, int cash);
    void read(QJsonObject json);

private:
    void keepEndPoints(int player, int *points);
    void palaceEndPoints(int player, int *points);
    void smallGateEndPoints(int player, int *points);
    void bigGateEndPoints(int player, int *points);
    void ServantsEndPoints(int player, int *points);
    void ForgeEndPoints(int player, int *points);
    void stableEndPoints(int player, int *points);
    void tavernEndPoints(int player, int *points);
    void marketEndPoints(int player, int *points, int cash);

    //to store wich player stands on the place
    int m_helperKeepPlayer;
    int m_helperPalacePlayer[2];
    int m_helperSmallGatePlayer;
    int m_helperBigGatePlayer;
    int m_helperServantsHousePlayer[3];
    int m_helperForgePlayer[2];
    int m_helperStablePlayer[2];
    int m_helperTavernPlayer[2];
    int m_helperMarketPlayer[2];
    int m_numberOfHelpers{NUMBER_OF_HELPERS};
    int m_playerHelper;
};

#endif // HELPERSBUILDING_H
