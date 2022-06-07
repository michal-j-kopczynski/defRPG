#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996) //saving system

#include <fstream> //saving system

#define sunPower 5

//retro game
struct retroCharacter
{
    int xPos, yPos;
    int behavior;
};

void retroBehavior(int* r1, int* r2, struct retroCharacter retroPlayersXYZ[], struct retroCharacter* mainRetroXYZ, int i)
{
    //1 - random, 2 - agressive
    *r1 = 1, * r2 = 1;
    switch (retroPlayersXYZ[i].behavior)
    {
    case 0:


        do
        {
            if (rand() % 2 == 0)
            {
                *r1 = (-1) * (*r1);
            }
            retroPlayersXYZ[i].xPos += *r1;
        } while (retroPlayersXYZ[i].xPos < 0 || retroPlayersXYZ[i].xPos > 8);
        do
        {
            if (rand() % 2 == 0)
            {
                *r2 = (-1) * (*r2);
            }
            retroPlayersXYZ[i].yPos += *r2;
        } while (retroPlayersXYZ[i].yPos < 0 || retroPlayersXYZ[i].yPos > 8);
        break;
    case 1:


        if (retroPlayersXYZ[i].xPos > mainRetroXYZ->xPos)
        {
            retroPlayersXYZ[i].xPos--;
        }
        else if (retroPlayersXYZ[i].xPos < mainRetroXYZ->xPos)
        {
            retroPlayersXYZ[i].xPos++;
        }

        if (retroPlayersXYZ[i].yPos > mainRetroXYZ->yPos)
        {
            retroPlayersXYZ[i].yPos--;
        }
        else if (retroPlayersXYZ[i].yPos < mainRetroXYZ->yPos)
        {
            retroPlayersXYZ[i].yPos++;
        }
        break;
    }
}



void retroMapDrawer(retroCharacter* mainRetroXYZ, retroCharacter retroPlayersXYZ[], int nOrignal, int treasureI, int treasureJ)
{
    int n = nOrignal, temp = 0, tempCounter = 0;
    int height = 9, width = 9;
    int retroMap[9][9];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            retroMap[i][j] = 10;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp = 0;
            tempCounter = 0;
            int tempStop = 0;

            if (i == treasureI && j == treasureJ)
            {
                std::cout << "T ";
            }
            else
            {
                for (int z = 0; z < n; z++)
                {

                    if (mainRetroXYZ->xPos == i && mainRetroXYZ->yPos == j && tempCounter == 0)
                    {
                        std::cout << "P ";
                        temp++;
                        tempStop = 1;
                    }
                    else if (retroPlayersXYZ[z].xPos == i && retroPlayersXYZ[z].yPos == j && tempStop != 1)
                    {
                        if (temp == 0)
                        {
                            std::cout << z + 1 << " ";
                            temp++;
                        }


                    }
                    else
                    {
                        if (temp == 0 && retroMap[i][j] == 10 && tempCounter == n - 1 && tempStop != 1)
                        {

                            std::cout << "O ";
                            temp++;
                        }

                    }
                    tempCounter++;
                }
            }




        }
        std::cout << "\n";
    }
}
void retroMovement(retroCharacter* mainRetroXYZ, retroCharacter retroPlayersXYZ[], int nOriginal, int treasureI, int treasureJ)
{

    int tempGameResult = -1;
    retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);
    while (tempGameResult != 1 && tempGameResult != 2) // 1 - game is lost, 2, game is won
    {
        time_t t;
        srand((unsigned)time(&t));
        //player turn
        std::cout << "Ruch gracza\nPostać ma pobiec na: \t";
        std::cout << "1 - północ, 2 - wschód, 3 - południe, 4 - zachód\n\n";


        int tempDecision;

        do
        {
            std::cin >> tempDecision;
        } while (tempDecision < 1 || tempDecision > 4);

        switch (tempDecision)
        {
        case 1:
            std::cout << "północ\n";
            mainRetroXYZ->xPos--;
            if (mainRetroXYZ->xPos < 0 || mainRetroXYZ->xPos > 8 || mainRetroXYZ->yPos < 0 || mainRetroXYZ->yPos > 8)
            {
                std::cout << "Wypadłeś z mapy!\n";
                tempGameResult = 1;
                do
                {

                    std::cout << "Wpisz 1 aby kontynuować\n";


                    std::cin >> tempDecision;
                } while (tempDecision < 1 || tempDecision > 4);
            }
            system("cls");
            std::cout << "-_-_-_-_-_-_-_-_-\n";
            retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);
            break;
        case 2:
            std::cout << "wschód\n";
            mainRetroXYZ->yPos++;
            if (mainRetroXYZ->xPos < 0 || mainRetroXYZ->xPos > 8 || mainRetroXYZ->yPos < 0 || mainRetroXYZ->yPos > 8)
            {
                std::cout << "Wypadłeś z mapy!\n";
                tempGameResult = 1;
                do
                {
                   
                        std::cout << "Wpisz 1 aby kontynuować\n";
                    

                    std::cin >> tempDecision;
                } while (tempDecision < 1 || tempDecision > 4);


            }
            system("cls");
            std::cout << "-_-_-_-_-_-_-_-_-\n";
            retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);
            break;
        case 3:
            std::cout << "południe\n";
            mainRetroXYZ->xPos++;
            if (mainRetroXYZ->xPos < 0 || mainRetroXYZ->xPos > 8 || mainRetroXYZ->yPos < 0 || mainRetroXYZ->yPos > 8)
            {
                std::cout << "Wypadłeś z mapy!\n";
                tempGameResult = 1;
                do
                {

                    std::cout << "Wpisz 1 aby kontynuować\n";


                    std::cin >> tempDecision;
                } while (tempDecision < 1 || tempDecision > 4);
            }
            system("cls");
            std::cout << "-_-_-_-_-_-_-_-_-\n";
            retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);
            break;
        case 4:
            std::cout << "zachód\n";
            mainRetroXYZ->yPos--;
            if (mainRetroXYZ->xPos < 0 || mainRetroXYZ->xPos > 8 || mainRetroXYZ->yPos < 0 || mainRetroXYZ->yPos > 8)
            {
                std::cout << "Wypadłeś z mapy!\n";
                tempGameResult = 1;
                do
                {

                    std::cout << "Wpisz 1 aby kontynuować\n";


                    std::cin >> tempDecision;
                } while (tempDecision < 1 || tempDecision > 4);
            }
            system("cls");
            std::cout << "-_-_-_-_-_-_-_-_-\n";
            retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);

            break;
        }


        if (mainRetroXYZ->xPos == treasureI && mainRetroXYZ->yPos == treasureJ)
        {
            std::cout << "Zdobyłeś skarb! Zwycięstwo!\n";
            tempGameResult = 2;
        }


        for (int i = 0; i < nOriginal; i++)
        {
            if (abs(retroPlayersXYZ[i].xPos - mainRetroXYZ->xPos) <= 1 && abs(retroPlayersXYZ[i].yPos - mainRetroXYZ->yPos) <= 1)
            {
                std::cout << "\n(I) Bęc! Maczugą uderzył przeciwnik: " << i + 1 << "\n";
                std::cout << retroPlayersXYZ[i].xPos << " x,  " << retroPlayersXYZ[i].yPos << " y - xy gracza " << mainRetroXYZ->xPos << mainRetroXYZ->yPos << "\n";
                std::cout << "Koniec rozgrywki!\n";
                if (tempGameResult != 2)
                {
                    tempGameResult = 1;
                }
                


            }
        }



        do
        {
            if (tempGameResult != -1)
            {
                std::cout << "Wpisz 1 aby zakończyć rozgrywkę\n";
            }
            else
            {
                std::cout << "Czekasz na ruch przeciwników - wpisz 1 aby kontynuować\n";
            }
            
            std::cin >> tempDecision;
        } while (tempDecision < 1 || tempDecision > 4);
        system("cls");
        //enemies turn
        std::cout << "Ruch przeciwników\n";
        /*
        std::cout << retroPlayersXYZ[0].xPos << "\n";
        std::cout << retroPlayersXYZ[0].yPos << "\n";
        std::cout << mainRetroXYZ->xPos << "\n";
        std::cout << mainRetroXYZ->yPos << "\n";
        */




        for (int i = 0; i < nOriginal; i++)
        {

            int r1 = 1, r2 = 1;
            /*
            int r1 = 1;
            int r2 = 1;

            do
            {
                if (rand() % 2 == 0)
                {
                    r1 =  (-1)* r1;
                }
                retroPlayersXYZ[i].xPos += r1;
            } while (retroPlayersXYZ[i].xPos < 0 || retroPlayersXYZ[i].xPos > 8);
            do
            {
                if (rand() % 2 == 0)
                {
                    r2 = (-1) * r2;
                }
                retroPlayersXYZ[i].yPos += r2;
            } while (retroPlayersXYZ[i].yPos < 0 || retroPlayersXYZ[i].yPos > 8);
            */
            //praca2
            retroBehavior(&r1, &r2, retroPlayersXYZ, mainRetroXYZ, i);




            if (abs(retroPlayersXYZ[i].xPos - mainRetroXYZ->xPos) == 1 && abs(retroPlayersXYZ[i].yPos - mainRetroXYZ->yPos) == 1)
            {
                std::cout << "\n(II) Bęc! Maczugą uderzył przeciwnik: " << i + 1 << "\n";
                std::cout << retroPlayersXYZ[i].xPos << " x,  " << retroPlayersXYZ[i].yPos << " y - xy gracza " << mainRetroXYZ->xPos << mainRetroXYZ->yPos << "\n";
                tempGameResult = 1;
            }

        }
        retroMapDrawer(mainRetroXYZ, retroPlayersXYZ, nOriginal, treasureI, treasureJ);

        /*
         std::cout << retroPlayersXYZ[0].xPos << "\n";
        std::cout << retroPlayersXYZ[0].yPos << "\n";
        std::cout << retroPlayersXYZ[1].xPos << "\n";
        std::cout << retroPlayersXYZ[1].yPos << "\n";
        std::cout << retroPlayersXYZ[2].xPos << "\n";
        std::cout << retroPlayersXYZ[2].yPos << "\n";
        std::cout << retroPlayersXYZ[3].xPos << "\n";
        std::cout << retroPlayersXYZ[3].yPos << "\n";
        std::cout << mainRetroXYZ->xPos << "\n";
        std::cout << mainRetroXYZ->yPos << "\n";
        */



    }



}

void retroStarter()
{
    setlocale(LC_CTYPE, "Polish");
    time_t t;
    srand((unsigned)time(&t));


    int n = 4;
    retroCharacter* retroMain = (retroCharacter*)malloc(sizeof(retroCharacter));
    retroCharacter* retroPlayers = (retroCharacter*)malloc(n * (sizeof(retroCharacter)));
    retroMain->xPos = 8; retroMain->yPos = 4;
    for (int i = 0; i < n; i++)
    {
        retroPlayers[i].xPos = 0;
        retroPlayers[i].yPos = i * 2;
        retroPlayers[i].behavior = i % 2;
        if (i == 3)
        {
            retroPlayers[i].yPos = i * 2 + 2;
        }
    }

    int treasureI = rand() % 5 + 2; int treasureJ = rand() % 5 + 1;

    retroMovement(retroMain, retroPlayers, n, treasureI, treasureJ);

    free(retroMain);
    free(retroPlayers);

}


//end retro game





//for pausing
#include <chrono>
#include <thread>

enum enmItemType{enmOffensiveType =0, enmDefensiveType=1, enmUtilitiesType=2};

enum enmOffensiveItemsId {enmOgniomiot=0, enmMrozicho=1 };
enum enmDefensiveItemsId {enmWzmocnionaSzata = 0, enmPancernyPłaszcz=1};
enum enmUtilitiesItemsId {enmSmallHpPotion =0, enmSmallMpPotion=10};
//player data types 
//praca1
struct player
{
    
    //location module
    int locationX; //player location
    int locationY;
    int previousLocationX;
    int previousLocationY;

    int currentMap; //current map that player visits
    int previousMap;
    int previousMap2;
    bool firstSpawn;


    //quest module
    int activeQuestsID[30];
    int finishedQuestsID[30];
    int pernamentDecision[20];

    //player stats
    int hp;
    int mp;
    int speed;
    int exp;

    int goldCoinsAmount;

    int currentWeaponDamage;


    //items in backpack
    int maxItemWeigh; //max possible weight of all items
    int currentItemsWeigh; //weight of all items currently in inventory
    bool itemsLocationAtBackpack[7][9]; //true - place is taken, true/real size 6 and 8, the magic numbers 7 and 9
    //are there for technical reasons
    int itemsLocationAtBackpackId[7][9];
    int itemsLocationAtBackpackIdType[7][9]; //0 - offensive, 1 - defensive, 2 - utilities
    
    //items actively used
    int activeOffensiveItemID, activeDefensiveItemID, activeUtilityItem1ID, activeUtilityItem2ID, activeUtilityItem3ID;
};

struct items
{
    
    int uniqueItemId;
    int itemType;
    
    bool IsEquipped;
    std::string itemName;
    std::string itemDescription;

    //technical stats
    int itemXlocation; 
    int itemYLocation;

    int width;
    int weigh;
    int length;
    
    //useful in game stats
    int attackDamage;
    int defenseValue;
};


void savingLoadingGameState(struct player* playerXYZ, int option) // 1 - load, 2 - save
{
   
    // wip - more statistics need to be saved, for now location of the player is known
    FILE* fptr;
    FILE* fptr2;
    FILE* fptr3;
    switch (option)
    {
    case 1:
        int tempDecision;
        int fromFileX, fromFileY;


        if ((fptr = fopen("game_save_location.txt", "r")) == NULL) {
            printf("Error! Brak pliku z zapisem gry");

            exit(1);
        }

        fscanf(fptr, "%d", &fromFileX);
        printf("X = %d ", fromFileX);
        fscanf(fptr, "%d", &fromFileY);
        printf("Y = %d", fromFileY);

        playerXYZ->locationX = fromFileX;
        playerXYZ->locationY = fromFileY;
        fclose(fptr);
        
        FILE* f_PStats_ptr;
        if ((f_PStats_ptr = fopen("game_save_player_statistics.txt", "r")) == NULL) {
            printf("Error! Brak pliku z zapisem gry 2");

            exit(1);
        }
        //stats module
        fscanf(f_PStats_ptr, "%d", &playerXYZ->hp);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->mp);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->exp);

        //eq module (backpack)
        fscanf(f_PStats_ptr, "%d", &playerXYZ->maxItemWeigh);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->currentItemsWeigh);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->currentWeaponDamage);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->currentMap);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->firstSpawn);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->goldCoinsAmount);

        //active eq module
        fscanf(f_PStats_ptr, "%d", &playerXYZ->activeOffensiveItemID);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->activeDefensiveItemID);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->activeUtilityItem1ID);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->activeUtilityItem2ID);
        fscanf(f_PStats_ptr, "%d", &playerXYZ->activeUtilityItem3ID);
        
        
        fclose(f_PStats_ptr);
        
        if ((fptr3 = fopen("game_save_player_statistics_arrays.txt", "r")) == NULL) {
            printf("Error! Brak pliku z zapisem gry (tablice");

            exit(1);
        }
        
        //eq arrays
        for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
        {
            for (int j = 0; j < 9; j++)
            {
                fscanf(fptr3, "%d", &playerXYZ->itemsLocationAtBackpack[i][j]);
                fscanf(fptr3, "%d", &playerXYZ->itemsLocationAtBackpackId[i][j]);
                fscanf(fptr3, "%d", &playerXYZ->itemsLocationAtBackpackIdType[i][j]);
               
            }
        }
        fclose(fptr3);

        std::cout << "\n";
        std::cout << "Wczytanie gry udane. Podaj 1 aby kontynować: ";
        std::cin >> tempDecision;
        break;
    case 2:

        //saving current location of the player
        fptr = fopen("game_save_location.txt", "w");
        if (fptr == NULL)
        {
            printf("Error! Problem z zapisem stanu gry (Położenie gracza\n");
            exit(1);
        }



        fprintf(fptr, "%d\n%d", playerXYZ->locationX, playerXYZ->locationY);
        

        /*
        fprintf(fptr, "%d", playerXYZ->locationX);
        fprintf(fptr, "\n");
        fprintf(fptr, "%d", playerXYZ->locationY);
        */

        /*
        //stats module
    playerXYZ->hp = 25;
    playerXYZ->mp = 5;
    playerXYZ->speed = 5;

    playerXYZ->exp = 0;



    //eq module (backpack)
    playerXYZ->maxItemWeigh = 25;
    
    
    playerXYZ->currentItemsWeigh = 0;
    
    playerXYZ->currentWeaponDamage = 3;

    playerXYZ->currentMap = 0;
    playerXYZ->firstSpawn = true;

    playerXYZ->goldCoinsAmount = 250;

    for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
    {
        for (int j = 0; j < 9; j++)
        {
            playerXYZ->itemsLocationAtBackpackId[i][j] = -1;
            playerXYZ->itemsLocationAtBackpackIdType[i][j] = -1;
            
            
        }
    }

    for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
    {
        for (int j = 0; j < 9; j++)
        {

            if (i > 5 || j > 7)
            {
                playerXYZ->itemsLocationAtBackpack[i][j] = true;
            }
            else
            {
                playerXYZ->itemsLocationAtBackpack[i][j] = false;
            }


        }
    }
    
    //active eq module
    playerXYZ->activeOffensiveItemID = -1; //no item currently equipped
    playerXYZ->activeDefensiveItemID = -1;
    playerXYZ->activeUtilityItem1ID = -1;
    playerXYZ->activeUtilityItem2ID = -1;
    playerXYZ->activeUtilityItem3ID = -1;
    //praca3
    //quest module
    for (int i = 0; i < 30; i++)
    {
        playerXYZ->activeQuestsID[i] = -1; //no active quests
        playerXYZ->finishedQuestsID[i] = -1; //no finished quests
    }
    
    playerXYZ->activeQuestsID[0] = 1;
        */

        
        fclose(fptr);
        
        //saving basic player stats
        fptr2 = fopen("game_save_player_statistics.txt", "w");
        if (fptr2 == NULL)
        {
            printf("Error! Problem z zapisem stanu gry (statystyki)\n");
            exit(1);
        }
        //stats module
        fprintf(fptr2, "%d\n", playerXYZ->hp);
        fprintf(fptr2, "%d\n", playerXYZ->mp);
        fprintf(fptr2, "%d\n", playerXYZ->exp);
        //eq module (backpack)
        fprintf(fptr2, "%d\n", playerXYZ->maxItemWeigh);
        fprintf(fptr2, "%d\n", playerXYZ->currentItemsWeigh);
        fprintf(fptr2, "%d\n", playerXYZ->currentWeaponDamage);
        fprintf(fptr2, "%d\n", playerXYZ->currentMap);
        fprintf(fptr2, "%d\n", playerXYZ->firstSpawn);
        fprintf(fptr2, "%d\n", playerXYZ->goldCoinsAmount);
        
        //active eq module
        fprintf(fptr2, "%d\n", playerXYZ->activeOffensiveItemID);
        fprintf(fptr2, "%d\n", playerXYZ->activeDefensiveItemID);
        fprintf(fptr2, "%d\n", playerXYZ->activeUtilityItem1ID);
        fprintf(fptr2, "%d\n", playerXYZ->activeUtilityItem2ID);
        fprintf(fptr2, "%d\n", playerXYZ->activeUtilityItem3ID);
        
        fclose(fptr2);
       
        //saving basic player stats (arrays)
        fptr3 = fopen("game_save_player_statistics_arrays.txt", "w");
        if (fptr3 == NULL)
        {
            printf("Error! Problem z zapisem stanu gry (statystyki - tablice)\n");
            exit(1);
        }
        //eq arrays
        for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
        {
            for (int j = 0; j < 9; j++)
            {
                
                fprintf(fptr3, "%d\n", playerXYZ->itemsLocationAtBackpack[i][j]);
                fprintf(fptr3, "%d\n", playerXYZ->itemsLocationAtBackpackId[i][j]);
                fprintf(fptr3, "%d\n", playerXYZ->itemsLocationAtBackpackIdType[i][j]);
            }
        }



       
        fclose(fptr3);
        break;
    }
}
void (*savingLoadingGameState_ptr)(struct player* playerXYZ, int) = &savingLoadingGameState;

void creatingItems(struct items* itemXYZ, int legnth, int width, int weigh,int attackDamage, int defenseValue,std::string name,int uniqueItemId, int itemType, struct player *playerXYZ)
{
    
    
    
    itemXYZ->IsEquipped = false;
    itemXYZ->length = legnth;
    itemXYZ->width = width;
    itemXYZ->weigh = weigh;
    itemXYZ->attackDamage = attackDamage;
    itemXYZ->defenseValue = defenseValue;

    itemXYZ->itemName = name;
    itemXYZ->itemType = itemType;
    itemXYZ->uniqueItemId = uniqueItemId;
}


void showItemsArea(struct player* playerXYZ) //only shows if place is taken - not names of items
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (playerXYZ->itemsLocationAtBackpack[i][j] == true)
            {
                std::cout << "X ";
            }
            else
            {
                std::cout << "O ";
            }
        }
        std::cout << "\n";
    }
}


void equippingItems(struct items* itemXYZ, struct player* playerXYZ)
{
    bool areaTest = false;
    int choosenX, choosenY;

    struct player *freshEq = (struct player*)malloc(sizeof(struct player));
    *freshEq = *playerXYZ;
    
    
    
    std::cout << "\n";
    showItemsArea(playerXYZ);
    std::cout << "Wybierz miejsce w plecaku:";
    std::cout << "Na osi X (rzędy): ";
    do
    {
        std::cin >> choosenX;
    } while (choosenX < 1 || choosenX > 6);
    std::cout << "Na osi Y (kolumny): ";
    do
    {
        std::cin >> choosenY;
    } while (choosenY < 1 || choosenY > 8);
    choosenX--; choosenY--;
    
    
    
    if (playerXYZ->itemsLocationAtBackpack[choosenX][choosenY] == false && itemXYZ->IsEquipped == false)
    {
        for (int i = 0, i2 = choosenX; i < itemXYZ->width; i++, i2++)
        {
            for (int j = 0, j2 = choosenY; j < itemXYZ->length; j++, j2++)
            {
                if (playerXYZ->itemsLocationAtBackpack[i2][j2] == false)
                {
                    freshEq->itemsLocationAtBackpack[i2][j2] = true;
                    freshEq->itemsLocationAtBackpackId[i2][j2] = itemXYZ->uniqueItemId;
                    freshEq->itemsLocationAtBackpackIdType[i2][j2] = itemXYZ->itemType;
                    
                    areaTest = true;
                }
                else
                {
                    i = 50;
                    j = 50;
                    areaTest = false;
                }
                    
            }
        }
    }
    

    
    
        if ((((playerXYZ->currentItemsWeigh + itemXYZ->weigh) <= playerXYZ->maxItemWeigh) && itemXYZ->IsEquipped == false)&&areaTest==true)
        {
            *playerXYZ = *freshEq;
            

            itemXYZ->itemXlocation = choosenX; itemXYZ->itemYLocation= choosenY;
            
            itemXYZ->IsEquipped = true;
            playerXYZ->currentItemsWeigh += itemXYZ->weigh;
            std::cout << "Udało się dodać do ekwipunku przedmiot: " << itemXYZ->itemName << "\n";
            std::cout << "Aktualny stan ekwipunku: \n";
            showItemsArea(playerXYZ);
            std::cout << "\n";
        }
        else if (itemXYZ->IsEquipped == true)
        {
            std::cout << "Przedmiot: " << itemXYZ->itemName << " jest już założony!\n";

        }
        else
        {
            if (playerXYZ->currentItemsWeigh + itemXYZ->weigh > playerXYZ->maxItemWeigh) 
                std::cout << "Przekroczona dozwolona waga posiadanych przedmiotów!\n";
            else
            {
                std::cout << "Przy tej próbie wciśnięcia przedmiotu do plecaka nie udało się!\n";
            }
        }
    
        free(freshEq);
       

}

//showId defines what types of items to show, 0 everything, 1 offensive, 2 defensive, 3 utilities/special 
void whatItemsAreEquiped(struct player* playerXYZ, int showId, struct items offensiveXYZ[], struct items defensiveXYZ[], struct items utilitiesXYZ[])
{
    system("cls");
    showItemsArea(playerXYZ);
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (playerXYZ->itemsLocationAtBackpack[i][j] == true)
            {
                
                if (playerXYZ->itemsLocationAtBackpackIdType[i][j] == enmOffensiveType && (showId != 2 && showId != 3) )//offensive type is found
                {
                    std::cout << "W komórce: X-" << i + 1 << " Y-" << j + 1 << " znajduje się: ";
                    std::cout << offensiveXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].itemName << " ID: " << offensiveXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].uniqueItemId << "\n";
                }
                if (playerXYZ->itemsLocationAtBackpackIdType[i][j] == enmDefensiveType && (showId != 1 && showId != 3))//defensive type is found
                {
                    std::cout << "W komórce: X-" << i + 1 << " Y-" << j + 1 << " znajduje się: ";
                    std::cout << defensiveXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].itemName <<" ID: " << defensiveXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].uniqueItemId << "\n";
                }
                if (playerXYZ->itemsLocationAtBackpackIdType[i][j] == enmUtilitiesType && (showId != 1 && showId != 2))//utilities type is found
                {
                    std::cout << "W komórce: X-" << i + 1 << " Y-" << j + 1 << " znajduje się: ";
                    std::cout << utilitiesXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].itemName << " ID: " << utilitiesXYZ[playerXYZ->itemsLocationAtBackpackId[i][j]].uniqueItemId << "\n";
                }
                
                    
            }
            else
            {
                //nothing found at [i][j]
            }
        }
        std::cout << "\n";
    }
    
}

void whatItemToUnequip(struct player* playerXYZ, int showId, struct items offensiveXYZ[], struct items defensiveXYZ[], struct items utilitiesXYZ[])
{
    
    int decision, decisionIdOfItemToDelete;
    std::cout << "Jakiego typu przedmiot chcesz usunąć?\n";
    std::cout << "Ofensywny - 1, Defensywny - 2, Specjalny - 3\n";
    std::cin >> decision;
    
    switch (decision)
    {
    case 1:
        whatItemsAreEquiped(playerXYZ, decision, offensiveXYZ, defensiveXYZ, utilitiesXYZ);
        std::cout << "Podaj ID przedmiotu który chcesz usunąć:\n";
        std::cout << "Podaj -1 aby anulować\n";
        std::cin >> decisionIdOfItemToDelete;
        

        if (decisionIdOfItemToDelete != -1)
        {
            playerXYZ->currentItemsWeigh -= offensiveXYZ[0].weigh;
            offensiveXYZ[decisionIdOfItemToDelete].IsEquipped = false;



            for (int i = 0, i2 = offensiveXYZ[decisionIdOfItemToDelete].itemXlocation; i < offensiveXYZ[decisionIdOfItemToDelete].width; i++, i2++)
            {
                for (int j = 0, j2 = offensiveXYZ[decisionIdOfItemToDelete].itemYLocation; j < offensiveXYZ[decisionIdOfItemToDelete].length; j++, j2++)
                {


                    playerXYZ->itemsLocationAtBackpack[i2][j2] = false;
                    playerXYZ->itemsLocationAtBackpackId[i2][j2] = -1; //change to neutral type
                    playerXYZ->itemsLocationAtBackpackIdType[i2][j2] = -1; //change to neutral type



                }
            }
            std::cout << "Pomyślnie wyrzucono przedmiot: " << offensiveXYZ[decisionIdOfItemToDelete].itemName << "\n";
        }



        if (decisionIdOfItemToDelete == -1)
        {
            system("cls");
            std::cout << "Pomyślnie anulowano. Aktualny stan ekwipunku:\n";
        }
        std::cout << "Aktualny stan ekwipunku: \n";
        showItemsArea(playerXYZ);
        break;
    case 2:
        whatItemsAreEquiped(playerXYZ, decision, offensiveXYZ, defensiveXYZ, utilitiesXYZ);
        std::cout << "Podaj ID przedmiotu który chcesz usunąć:\n";
        std::cout << "Podaj -1 aby anulować\n";
        std::cin >> decisionIdOfItemToDelete;
        
        if (decisionIdOfItemToDelete != -1)
        {
            playerXYZ->currentItemsWeigh -= defensiveXYZ[0].weigh;
            defensiveXYZ[decisionIdOfItemToDelete].IsEquipped = false;



            for (int i = 0, i2 = defensiveXYZ[decisionIdOfItemToDelete].itemXlocation; i < defensiveXYZ[decisionIdOfItemToDelete].width; i++, i2++)
            {
                for (int j = 0, j2 = defensiveXYZ[decisionIdOfItemToDelete].itemYLocation; j < defensiveXYZ[decisionIdOfItemToDelete].length; j++, j2++)
                {


                    playerXYZ->itemsLocationAtBackpack[i2][j2] = false;
                    playerXYZ->itemsLocationAtBackpackId[i2][j2] = -1; //change to neutral type
                    playerXYZ->itemsLocationAtBackpackIdType[i2][j2] = -1; //change to neutral type



                }
            }
            std::cout << "Pomyślnie wyrzucono przedmiot: " << defensiveXYZ[decisionIdOfItemToDelete].itemName << "\n";
        }
        
        
        
        
        if (decisionIdOfItemToDelete == -1)
        {
            system("cls");
            std::cout << "Pomyślnie anulowano. Aktualny stan ekwipunku:\n";
        }
        std::cout << "Aktualny stan ekwipunku: \n";
        showItemsArea(playerXYZ);
        break;
    case 3:
        whatItemsAreEquiped(playerXYZ, decision, offensiveXYZ, defensiveXYZ, utilitiesXYZ);
        std::cout << "Podaj ID przedmiotu który chcesz usunąć:\n";
        std::cout << "Podaj -1 aby anulować\n";
        std::cin >> decisionIdOfItemToDelete;
        
        if (decisionIdOfItemToDelete != -1)
        {
            playerXYZ->currentItemsWeigh -= utilitiesXYZ[0].weigh;
            utilitiesXYZ[decisionIdOfItemToDelete].IsEquipped = false;



            for (int i = 0, i2 = utilitiesXYZ[decisionIdOfItemToDelete].itemXlocation; i < utilitiesXYZ[decisionIdOfItemToDelete].width; i++, i2++)
            {
                for (int j = 0, j2 = utilitiesXYZ[decisionIdOfItemToDelete].itemYLocation; j < utilitiesXYZ[decisionIdOfItemToDelete].length; j++, j2++)
                {


                    playerXYZ->itemsLocationAtBackpack[i2][j2] = false;
                    playerXYZ->itemsLocationAtBackpackId[i2][j2] = -1; //change to neutral type
                    playerXYZ->itemsLocationAtBackpackIdType[i2][j2] = -1; //change to neutral type



                }
            }
            std::cout << "Pomyślnie wyrzucono przedmiot: " << utilitiesXYZ[decisionIdOfItemToDelete].itemName << "\n";
            std::cout << "Aktualny stan ekwipunku: \n";
        }
        if (decisionIdOfItemToDelete == -1)
        {
            system("cls");
            std::cout << "Pomyślnie anulowano. Aktualny stan ekwipunku:\n";
        }
        showItemsArea(playerXYZ);
        break;
    }
}


//praca2
void activeEq(struct player* playerXYZ, int DecisionParameter, struct items offensiveXYZ[], struct items defensiveXYZ[], struct items utilitiesXYZ[])
{
    int tempDecision1, tempDecision2, tempDecision3;
    int tempIDitemToEquip;
    std::cout << "Aktywny przedmiot ofensywny:\t";
    if (playerXYZ->activeOffensiveItemID == -1)
    {
        std::cout << "Nie wybrano aktywnego przedmiotu ofensywnego\n";
    }
    else
    {
        std::cout << offensiveXYZ[playerXYZ->activeOffensiveItemID].itemName << "\n";
    }
    std::cout << "Aktywny przedmiot defensywny:\t";
    if (playerXYZ->activeDefensiveItemID == -1)
    {
        std::cout << "Nie wybrano aktywnego przedmiotu defensywnego\n";
    }
    else
    {
        std::cout << defensiveXYZ[playerXYZ->activeDefensiveItemID].itemName << "\n";
    }
    std::cout << "Aktywny przedmiot specjalny:\t";
    if (playerXYZ->activeUtilityItem1ID == -1)
    {
        std::cout << "Nie wybrano aktywnego przedmiotu specjalnego\n";
    }
    else
    {
        std::cout <<utilitiesXYZ[playerXYZ->activeUtilityItem1ID].itemName << "\n";
    }
    
    std::cout << "Czy chcesz zmienić aktulnie używane aktywne przedmioty na inne?\n";
    std::cout << "1 - tak, 2 - nie\n";
    do
    {
        std::cin >> tempDecision1;
    } while (tempDecision1 < 1 || tempDecision1 > 2);
    if (tempDecision1 == 1)
    {
        std::cout << "Zmień: 1 - ofensywny, 2 - defensywny, 3 - specjalny\n"; //wip - only 1 offensive item and 1 defensive item works
        do
        {
            std::cin >> tempDecision2;
        } while (tempDecision2 < 1 || tempDecision2 > 5);
        if (tempDecision2 == 1)
        {
            whatItemsAreEquiped(playerXYZ, 1, offensiveXYZ, defensiveXYZ, utilitiesXYZ); //1 - show offensive
            std::cout << "Podaj ID przedmiotu który ma być założony (-1 aby usunąć aktualnie założony przedmiot)\n";
            std::cin >> tempIDitemToEquip;
            
            if (tempIDitemToEquip == -1)
            {
                playerXYZ->activeOffensiveItemID = -1;
            }
            else if (offensiveXYZ[tempIDitemToEquip].IsEquipped == true)
            {
                playerXYZ->activeOffensiveItemID = tempIDitemToEquip;
            }
            else 
            {
                std::cout << "Wybrany przedmiot nie znajduje się w plecaku\n";
            }
        }


        else if (tempDecision2 == 2)
        {
            whatItemsAreEquiped(playerXYZ, 2, offensiveXYZ, defensiveXYZ, utilitiesXYZ); //2 - show defensive
            std::cout << "Podaj ID przedmiotu który ma być założony (-1 aby usunąć aktualnie założony przedmiot)\n";
            std::cin >> tempIDitemToEquip;

            if (tempIDitemToEquip == -1)
            {
                playerXYZ->activeDefensiveItemID = -1;
            }
            else if (defensiveXYZ[tempIDitemToEquip].IsEquipped == true)
            {
                playerXYZ->activeDefensiveItemID = tempIDitemToEquip;
            }
            else
            {
                std::cout << "Wybrany przedmiot nie znajduje się w plecaku\n";
            }
        }
        else if (tempDecision2 == 3)
        {
            whatItemsAreEquiped(playerXYZ, 3, offensiveXYZ, defensiveXYZ, utilitiesXYZ); //3 - show utilities
            std::cout << "Podaj ID przedmiotu który ma być założony (-1 aby usunąć aktualnie założony przedmiot)\n";
            std::cin >> tempIDitemToEquip;

            if (tempIDitemToEquip == -1)
            {
                playerXYZ->activeUtilityItem1ID = -1;
            }
            else if (utilitiesXYZ[tempIDitemToEquip].IsEquipped == true)
            {
                playerXYZ->activeUtilityItem1ID = tempIDitemToEquip;
            }
            else
            {
                std::cout << "Wybrany przedmiot nie znajduje się w plecaku\n";
            }
        }

    }
   
}

//old version
/*
* void UnEquippingItems(struct player* playerXYZ, int typeToDelete, int itemToDeleteId, struct items offensiveXYZ[], struct items defensiveXYZ[], struct items utilitiesXYZ[])
{

    
    
        playerXYZ->currentItemsWeigh -= offensiveXYZ[0].weigh;
        offensiveXYZ[itemToDeleteId].IsEquipped = false;

        
        
            for (int i = 0, i2 = offensiveXYZ[itemToDeleteId].itemXlocation; i < offensiveXYZ[itemToDeleteId].width; i++, i2++)
            {
                for (int j = 0, j2 = offensiveXYZ[itemToDeleteId].itemYLocation; j < offensiveXYZ[itemToDeleteId].length; j++, j2++)
                {
                   
                        playerXYZ->itemsLocationAtBackpack[i2][j2] = false;

                }
            }
            std::cout << "Pomyślnie wyrzucono przedmiot: "<< offensiveXYZ[itemToDeleteId].itemName <<"\n";
            std::cout << "Aktualny stan ekwipunku: \n";
            showItemsArea(playerXYZ);


    
}
*/







void startingPlayerStats(struct player* playerXYZ)
{
    
    //location module
    playerXYZ->locationX = 14;
    playerXYZ->locationY = 12;


    //stats module
    playerXYZ->hp = 25;
    playerXYZ->mp = 5;
    playerXYZ->speed = 5;

    playerXYZ->exp = 0;



    //eq module (backpack)
    playerXYZ->maxItemWeigh = 25;
    
    
    playerXYZ->currentItemsWeigh = 0;
    
    playerXYZ->currentWeaponDamage = 3;

    playerXYZ->currentMap = 0;
    playerXYZ->firstSpawn = true;

    playerXYZ->goldCoinsAmount = 250;

    for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
    {
        for (int j = 0; j < 9; j++)
        {
            playerXYZ->itemsLocationAtBackpackId[i][j] = -1;
            playerXYZ->itemsLocationAtBackpackIdType[i][j] = -1;
            
            
        }
    }

    for (int i = 0; i < 7; i++) //magic numbers for eq 6x8
    {
        for (int j = 0; j < 9; j++)
        {

            if (i > 5 || j > 7)
            {
                playerXYZ->itemsLocationAtBackpack[i][j] = true;
            }
            else
            {
                playerXYZ->itemsLocationAtBackpack[i][j] = false;
            }


        }
    }
    
    //active eq module
    playerXYZ->activeOffensiveItemID = -1; //no item currently equipped
    playerXYZ->activeDefensiveItemID = -1;
    playerXYZ->activeUtilityItem1ID = -1;
    playerXYZ->activeUtilityItem2ID = -1;
    playerXYZ->activeUtilityItem3ID = -1;
    //praca3
    //quest module
    for (int i = 0; i < 30; i++)
    {
        playerXYZ->activeQuestsID[i] = -1; //no active quests
        playerXYZ->finishedQuestsID[i] = -1; //no finished quests
    }
    
    playerXYZ->activeQuestsID[0] = 1;
    
    
}

//hazard
void hazard(struct player* playerXYZ)
{
    int gamblingDecision = 0, simulationSize;
    std::cout << "W zacienionym pomieszczeniu odnajdujesz popularny model machiny hazardowej \"Baryłkacz\"\n";
    std::cout << "Magiczna szklana kula symuluje wynurzanie się zatopionych baryłek.\n";
    std::cout << "Za każdą baryłkę która pojawi się na powierzchni w ciągu chwili działania zaklęcia\notrzymasz dwie sztuki złota.\n";
    std::cout << "Czy chcesz zaryzykować powodzenie wyprawy dla kilku złotych monet?\n";
    std::cout << "1 - tak, 2 - nie\n";
    
    std::cin >> gamblingDecision;
    if (gamblingDecision == 1)
    {
        int i, j, numberOfWins = 0;
        time_t t;
        srand((unsigned)time(&t));
        
        std::cout << "Jak wielka powinna być symulacja? Minimalna ilość magicznie przewidywanych potencjalnie wynurzeń baryłek to 4\n";
        std::cout << "Rośnie ona kwadratowo - wielkość symulacji 2 oznacza 4 baryłki, wielkość symulacji 3 oznacza 9 baryłek\n";
        std::cout << "Każda baryłka kosztuje 1 sztukę złota\n";
        std::cout << "Podaj wielkość symulacji: \t";
        do
        {
            std::cin >> simulationSize;
        } while (simulationSize < 2);
        std::cout << "Symulacja tej wielkości będzie kosztować Cię " << simulationSize * simulationSize << "sztuk złota\n";
        if (simulationSize * simulationSize <= playerXYZ->goldCoinsAmount)
        {
            playerXYZ->goldCoinsAmount -= simulationSize * simulationSize;

            
            int** symArr = (int**)malloc(sizeof(int*) * simulationSize);
            for (i = 0; i < simulationSize; i++)
            {
                symArr[i] = (int*)malloc(sizeof(int) * simulationSize);
            }
            ;
            for (i = 0; i < simulationSize; i++)
            {
                for (j = 0; j < simulationSize; j++)
                {
                    
                    symArr[i][j] = rand() % 2;
                    
                }
            }
            for (i = 0; i < simulationSize; i++)
            {
                for (j = 0; j < simulationSize; j++)
                {
                    if (symArr[i][j] == 0)
                    {
                        std::cout << "~ ";
                    }
                    else
                    {
                        std::cout << "B ";
                        numberOfWins++;
                    }
                    
                }
                std::cout << "\n";
            }
            for (i = 0; i < simulationSize; i++)
            {
                free(symArr[i]);
            }
            free(symArr);
            
            
            playerXYZ->goldCoinsAmount += numberOfWins*2;
            std::cout << "Wynurzyło się: " << numberOfWins << " baryłek. Otrzymujesz " << numberOfWins * 2 << " sztuk złota\n";
            std::cout << "Całkowita ilość posiadanego złota po zadziałaniu machiny: " << playerXYZ->goldCoinsAmount;
        }
        else
        {
            std::cout << "\"Maszyna wydusiła: \"za mało złotych monet! Operacja przerwana!\" po czym wypluła wcześniej wrzucone monety\n";
        }
    }
   
}



//przeciwnicy
struct enemy
{
    int hp;
    int mp;
    int standardDamage;
    int criticalDamage;
    int speed;
};
//walka //fight1
void walka(struct player* playerXYZ, struct enemy* enemyXYZ1, struct enemy* enemyXYZ2, int numberOfEnemies, int gainedExperience)
{
    int decision;
    if (numberOfEnemies == 1)
    {
        do
        {
            if (playerXYZ->speed > enemyXYZ1->speed)
            {
                std::cout << "\nTwoje odpowiedź to:\n";
                std::cout << "1 - atak, 2 - przyjęcie ciosu w pozycji obronnej\n";
                do
                {
                    std::cin >> decision;
                } while (decision < 1 || decision > 2);
                switch (decision)
                {
                case 1:
                    std::cout << "Wybrałeś atak! Atakujesz\n";
                    enemyXYZ1->hp -= playerXYZ->currentWeaponDamage;
                    std::cout << "Zadałeś " << playerXYZ->currentWeaponDamage << " obrażeń\n";
                    
                    if (enemyXYZ1->hp > 0)
                    {
                        std::cout << "\nPrzeciwnik atakuje!\n";
                        playerXYZ->hp -= enemyXYZ1->standardDamage;
                        std::cout << "Otrzymałeś " << enemyXYZ1->standardDamage << " obrażeń\n";
                    }
                    break;
                case 2:
                    std::cout << "Work in progress\n - zwiększy się współczynnik obrony\n";
                    if (enemyXYZ1->hp > 0)
                    {
                        std::cout << "\nPrzeciwnik atakuje!\n";
                        playerXYZ->hp -= enemyXYZ1->standardDamage;
                        std::cout << "Otrzymałeś " << enemyXYZ1->standardDamage << " obrażeń\n";
                    }
                    break;
                }
            }
            std::cout << "Twój poziom zdrowia aktualnie wynosi: " << playerXYZ->hp << "\n";
        }while (enemyXYZ1->hp > 0 && playerXYZ->hp > 0);
        if (playerXYZ->hp > 0)
        {
            std::cout << "Udało Ci się pokonać przeciwnika. Otrzymujesz " << gainedExperience << " exp\n\n";
            playerXYZ->exp += gainedExperience;
        }
        else
        {
            std::cout << "Twoje hp spadło poniżej 0. Giniesz!\n\n";
        }
    }
    else if (numberOfEnemies == 2)
    {
        //wip
    }
}


void defineEnemyStats(struct enemy *enemyXYZ, int hp, int mp, int standardDamage, int criticalDamage, int speed)
{
    enemyXYZ->hp = hp;
    enemyXYZ->mp = mp;
    enemyXYZ->standardDamage = standardDamage;
    enemyXYZ->criticalDamage = criticalDamage;
}


//unique locations currently available (maps, islands)

struct worldMap
{
    std::string worldMapName;
    int worldMapWidth;
    int worldMapHeight;
    
    int allLocations[40][40];
    
};

/*
100 - default location of a map - port city of Thukam
101 - ocean
*/
void locationCreatorOnChoosenWorldMap(struct worldMap worldMapXYZ[], struct player* playerXYZ, int mapWidth, int mapHeight, std::string nameOfWorldMap, int whatMapToDraw) //whatMapToDraw - ID of a map
{
    worldMapXYZ[whatMapToDraw].worldMapWidth = mapWidth;
    worldMapXYZ[whatMapToDraw].worldMapHeight = mapHeight;

    worldMapXYZ[whatMapToDraw].worldMapName = nameOfWorldMap;
   
    switch (whatMapToDraw)
    {
    case 0:
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                if (i == 14 && j == 12)
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 103; //port town
                }
                else if (i < 5 || i > 14 || j < 5 || j > 14)
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 101; //ocean 
                }
                else if (i > 8 && i < 13 && j > 7 && j < 17)
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 102; //Clearing (polana)
                }
                else //default
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 100; //Forest
                }

            }
        }
        break;
    case 1:
        for (int i = 0; i < mapHeight; i++)
        {
            for (int j = 0; j < mapWidth; j++)
            {
                if (i == 10 && j == 15)
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 203; //desert port town
                }
                else if (i > 8 && i < 13 && j > 7 && j < 17)
                {
                    if (i % 3 == 0 && j%2 == 0)
                    {
                        worldMapXYZ[whatMapToDraw].allLocations[i][j] = 100; //Forest
                    }
                    else if (i % 3 == 1 && j%4==0)
                    {
                        worldMapXYZ[whatMapToDraw].allLocations[i][j] = 101; //ocean 
                    }
                    else
                    {
                        worldMapXYZ[whatMapToDraw].allLocations[i][j] = 200; //desert
                    }
                }
                else if (i < 12 || i > 14 || j < 8 || j > 15)
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 101; //ocean 
                }
                else //default
                {
                    worldMapXYZ[whatMapToDraw].allLocations[i][j] = 200; //desert
                }

            }
        }
        break;
    }

    

   /*
   *  for (int i = 0; i < mapWidth; i++)
        {
            for (int j = 0; j < mapHeight; j++)
            {
                if (i < 5 || i > 14 || j < 5 || j > 14 )
                {
                    worldMapXYZ->allLocations[i][j] = 101; //ocean 
                }
                else //default
                {
                    worldMapXYZ->allLocations[i][j] = 100; //default location type
                }
            }
        
        }
       
   */
       
}

void showWorldMap (struct worldMap worldMapXYZ[], struct player* playerXYZ, int whatMapToShow)
{
    
        std::cout << "Kraina: " << worldMapXYZ[whatMapToShow].worldMapName << "\n";
        
        
            for (int i = 0; i < worldMapXYZ[whatMapToShow].worldMapHeight; i++)
            {
                for (int j = 0; j < worldMapXYZ[whatMapToShow].worldMapWidth; j++)
                {
                    
                    if (playerXYZ->locationX == i && playerXYZ->locationY == j)
                    {
                        std::cout << "P ";
                    }
                    else if (worldMapXYZ[whatMapToShow].allLocations[i][j] == 100)
                    {
                        std::cout << "T ";
                    }
                    else if (worldMapXYZ[whatMapToShow].allLocations[i][j] == 101)
                    {
                        std::cout << "~ ";
                    }
                    else if (worldMapXYZ[whatMapToShow].allLocations[i][j] == 102)
                    {
                        std::cout << "& ";
                    }
                    else if (worldMapXYZ[whatMapToShow].allLocations[i][j] == 103 || worldMapXYZ[whatMapToShow].allLocations[i][j] == 203)
                    {
                        std::cout << "C ";
                    }
                    else if (worldMapXYZ[whatMapToShow].allLocations[i][j] == 200)
                    {
                        std::cout << "D ";
                    }
                   


                }
                std::cout << "\n";
            }
                
        

        
        
        /*
         for (int i = 0; i < worldMapXYZ->worldMapWidth; i++)
        {
            for (int j = 0; i < worldMapXYZ->worldMapHeight; j++)
            {
                if (worldMapXYZ->allLocations[i][i] == 100)
                {
                    std::cout << "R";
                }
                if (worldMapXYZ->allLocations[i][i] == 101)
                {
                    std::cout << "~";
                }
            }
        }
        */
        
}



//common graphics
void commonGraphics(int option)
{
    switch (option)
    {
    case 1:
        printf(R"EOF(
              .-.
             (o.o)
              |=|                  +-+ 
             __|__    0============| |
          // .=|=. \\//           `:_;'
          \\ .=|=.  \/
           \\(_=_)
            (:| |:
             || ||
             () ()
             || ||
             || ||
            ==' '== 
            )EOF");
        break;
    case 2:
        printf(R"EOF(
                     ___
                    /<T>\
                   /     \      
                  /       \
                 /         \

            )EOF");
        break;
    case 3:
        printf(R"EOF(
 
              _,._      
  .||,       /_ _\\     
 \.`',/      |o o| |    
 = ,. =      | - | L    
 / || \    ,-'\ /,'`.   
   ||     ,'   `,,. `.  
   ,|____,' , ,;' \| |  
  (3|\    _/|/'   _| |  
   ||/,-''  | >-'' _,\\ 
   ||'      ==\ ,-'  ,' 
   ||       |  V \ ,|   
   ||       |    |` |   
   ||       |    |   \  
   ||       |    \    \ 
   ||       |     |    \
   ||       |      \_,-'
   ||       |___,,--")_\
   ||         |_|   /__/ 
   ||        /__/       
   ||         
        )EOF");
        break;
    }
}

void EhimeDefaultSpawn()
{
    std::cout << "Morska podróż dobiegła końca.\n";
    std::cout << "Miasto portowe Thukam widzało lepsze czasy, jeśli wierzyć opowieściom Elrika,\nktóry dwie dekady temu zwiedził Archipelag Maggurn.\n";
    std::cout << "Twoje zadanie: dowiedzieć się, co prześladuje krainę Ehime.\nPorażka nie wchodzi w grę, zważając na twoje zaniedbanie obowiązków w gildii.\n";
    
    std::chrono::milliseconds timespan(1000);
    std::this_thread::sleep_for(timespan);
}

//common locations
void polana(struct player* playerXYZ)
{
    int randomOption;
    time_t t;
    srand((unsigned)time(&t));
    randomOption = rand() % 5;
    struct enemy skeleton, slime;
    defineEnemyStats(&skeleton, 15, 0, 2, 5, 2);
    defineEnemyStats(&slime, 25, 0, 1, 3, 2);
    
    std::cout << "\n\nPo wielu godzinach drogi dotarłeś na: Polanę\n";
    printf(R"EOF(
                       
            \ _ /
          -= (_) =-                         UUUU
            /   \                           UUUU
              |                              []
    _  ___  __  _ __ __ _  _ _T _ _ __  __ _ ||
  =-O-_=-=-_=-T_=-_=0_=-_-_=_=-= _=_=-=0_,-_---_-
   =- _=-T-_=0 _=-= _T-_ =-= -T=-=_-=_,-"-_--=---        
     =- =- =O= =- = -  -===- 0-= -= ."                
            )EOF");




    
    if (randomOption == 0) //fight2
    {
        std::cout << "\n\nNiecny szkielet zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(1);
        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = skeleton;

        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 1)
    {
        std::cout << "\n\nOgromny żywy szlam zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(2);
        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = slime;
        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 2 )
    {
        std::cout << "Zaczął padać deszcze\n";
    }
    else if (randomOption == 3)
    {
        std::cout << "Zrobiło się pochmurno, wzmógł się wiatr\n";
    }
    else if (randomOption == 3)
    {
        std::cout << "Chmury nie blokują słońca. Jest ciepło.\n";
    }

    
    std::cout << "poziom hp postaci: " << playerXYZ->hp << "\n";
} //clearing

void desert(struct player* playerXYZ)
{
    int randomOption;
    time_t t;
    srand((unsigned)time(&t));
    randomOption = rand() % 4;
    struct enemy skeleton, slime;
    defineEnemyStats(&skeleton, 15, 0, 2, 5, 2);
    defineEnemyStats(&slime, 25, 0, 1, 3, 2);

    std::cout << "\n\nPo wielu godzinach drogi dotarłeś na: Pustynne stepy\n";
    printf(R"EOF(
              .    _    +     .  ______   .          .
 (      /|\      .    |      \      .   +
     . |||||     _    | |   | | ||         .
.      |||||    | |  _| | | | |_||    .
   /\  ||||| .  | | |   | |      |       .
__||||_|||||____| |_|_____________\__________
. |||| |||||  /\   _____      _____  .   .
  |||| ||||| ||||   .   .  .         ________
 . \|`-'|||| ||||    __________       .    .
    \__ |||| ||||      .          .     .
 __    ||||`-'|||  .       .    __________
.    . |||| ___/  ___________             .
   . _ ||||| . _               .   _________
_   ___|||||__  _ \\--//    .          _
     _ `---'    .)=\oo|=(.   _   .   .    .
_  ^      .               
            )EOF");




    if (randomOption == 0)
    {
        std::cout << "\n\nNiecny szkielet zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(1);

        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = skeleton;

        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 1)
    {
        std::cout << "\n\nOgromny żywy szlam zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(2);

        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = slime;
        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 2)
    {
        std::cout << "Pojawiło się kila delikatnych, podłóżnych chmur. Nie wygląda, jakby zanosiło się na deszcz, jednak jest odrobinę chłodniej niż zwykle w tej cześci świata\n";
    }
    else if (randomOption == 3)
    {
        std::cout << "Burza piaskowa rani twoje oczy a żar wywołuje migrenę. Poziom HP spada o 2 punkty.\n";
        playerXYZ->hp -= 1;
    }
    else if (randomOption == 3)
    {
        std::cout << "Jest upalnie.\n";
    }


    std::cout << "poziom HP postaci: " << playerXYZ->hp << "\n";
}



void forest(struct player* playerXYZ)
{
    int randomOption;
    time_t t;
    srand((unsigned)time(&t));
    randomOption = rand() % 4;
    struct enemy skeleton, slime;
    defineEnemyStats(&skeleton, 15, 0, 2, 5, 2);
    defineEnemyStats(&slime, 25, 0, 1, 3, 2);

    std::cout << "\n\nPo wielu godzinach drogi dotarłeś do: Puszcza\n";
    printf(R"EOF(


       &&& &&  & &&                     oxoxoo    ooxoo
      && &\/&\|& ()|/ @, &&           ooxoxo oo  oxoxooo
      &\/(/&/&||/& /_/)_&/_&         oooo xxoxoo ooo ooox
   &() &\/&|()|/&\/ '%" & ()         oxo o oxoxo  xoxxoxo
  &_\_&&_\ |& |&&/&__%_/_& &&         oxo xooxoooo o ooo
&&   && & &| &| /& & % ()& /&&          ooo\oo\  /o/o
 ()&_---()&\&\|&&-&&--%---()~                \  \/ /
     &&     \|||                             |   /
             |||                             |  |
             |||                             | D|
             |||                             |  |
       , -=-~  .-^- _                        |  |      
                                      ______/____\____
   
            )EOF");     




    if (randomOption == 0)
    {
        std::cout << "\n\nNiecny szkielet zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(1);

        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = skeleton;

        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 1)
    {
        std::cout << "\n\nOgromny żywy szlam zaatakował!\nRozpoczęła się walka!\n\n\n";
        commonGraphics(2);

        struct enemy* enemyPtr = (struct enemy*)malloc(sizeof(struct enemy));
        *enemyPtr = slime;
        walka(playerXYZ, enemyPtr, enemyPtr, 1, 2); //fight with 2 enemies wip
        free(enemyPtr);
    }
    else if (randomOption == 2)
    {
        std::cout << "Pojawiło się kila delikatnych, podłóżnych chmur. Nie wygląda, jakby zanosiło się na deszcz, jednak jest odrobinę chłodniej niż zwykle w tej cześci świata\n";
    }
    else if (randomOption == 3)
    {
        std::cout << "Burza piaskowa rani twoje oczy a żar wywołuje migrenę. Poziom HP spada o 2 punkty.\n";
        playerXYZ->hp -= 1;
    }
    else if (randomOption == 3)
    {
        std::cout << "Jest upalnie.\n";
    }


    std::cout << "poziom HP postaci: " << playerXYZ->hp << "\n";
}
//end of locations


struct quests 
{
    int questID;
    
    int progressNumber;
    int progressChecker[40];
    int progressBoolChecker[25];
    std::string messege[35];
    
};
void questCreator(struct quests questXYZ[])
{

}


//defines/checks where player is on the world map
void whereAmI_XY(struct player* locationXY, struct worldMap worldMapXYZ[])
{
    /*
    int operX = locationXY->locationX;
    int operY = locationXY->locationY;
    */
    int operX = locationXY->locationX;
    int operY = locationXY->locationY;
    (*savingLoadingGameState_ptr)(locationXY, 2);

    switch (worldMapXYZ[locationXY->currentMap].allLocations[operX][operY])
    {
    case 100: //forest
        std::cout << "x: " << operX << " y: " << operY << "\n";
        std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
        std::cout << "Lokacja: Puszcza\n";
        showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
        forest(locationXY);
        break;
    case 101: //ocean
        std::cout << "x: " << operX << " y: " << operY << "\n";
        std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
        std::cout << "Lokacja: Ocean\n"; //for clarity this option will never execute
        showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
        
        break;
    case 102: //polana
        std::cout << "x: " << operX << " y: " << operY << "\n";
        std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
        std::cout << "Lokacja: Polana\n";
        showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
        polana(locationXY);
        break;
    case 103: //port town
        if (locationXY->firstSpawn == true)
        {
            EhimeDefaultSpawn();
            locationXY->firstSpawn = false;
            
            std::cout << "x: " << operX << " y: " << operY << "\n";
            std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
            std::cout << "Lokacja: Miasto Portowe Thukam\n";
            showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
                            printf(R"EOF(
            ||=============================================================||
            ||                                   ___        ___       T__  ||
            ||                        ________   | |~~~~~~~~| ||~~~~| |||  ||
            ||    __|~~~~~~~~|   _/\_ |^^^^^^|  _| |--------| ||    | |##  ||
            ||    |_|HHHHHHHH|  _|--| |------|_-#########################  ||
            ||=============================================================||
            )EOF");
        }
        else
        {
            std::cout << "x: " << operX << " y: " << operY << "\n";
            std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
            std::cout << "Lokacja: Miasto Portowe Thukam\n";
            showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
            std::cout << "Miasto portowe widziało lepsze lata\n";
            std::cout << "Gildia szuka odpowiedzi. \nWedług plotek która można usłyszeć przechodząc się ulicami Thukam na północy wyspy występują jak do tej pory niewyjaśnione anomalie pogodowe.\n";
            std::cout << "Utrudnia to produkcję podstawowych dóbr. Wiesz już, w jaką stronę się udać. Szkoda tylko, że magia kontrolii pogody zawsze była dla ciebie nieuchwytna\n";
            std::cout << "Kula ognia nie rozwiąże każdego problemu.\n";
            printf(R"EOF(
            ||=============================================================||
            ||                                   ___        ___       T__  ||
            ||                        ________   | |~~~~~~~~| ||~~~~| |||  ||
            ||    __|~~~~~~~~|   _/\_ |^^^^^^|  _| |--------| ||    | |##  ||
            ||    |_|HHHHHHHH|  _|--| |------|_-#########################  ||
            ||=============================================================||
            )EOF");
            
            int tempDecision, tempDecision2, tempDecision3, tempDecision4;
            int talkedWithOwnerAboutQuests = 0;
            std::cout << "\n1 - udaj się do karczmy \"Pod Błękitnym Trunkiem\", 2 - oddaj się hazardowi w podejrzanie wyglądacym przytułku,\n3 - udaj się najbliższym statkiem na wyspę Solana \n";
            do
            {
                std::cin >> tempDecision;
            } while (tempDecision < 1 || tempDecision > 3);
                switch (tempDecision)
                {
                case 1:
                    std::cout << "Pomieszczenie jest szerokie, pomimo sporej ilości gości nie jest tłoczno.\n";
                    std::cout << "1 - poszukaj rozmówcy w izbie karczemnej, 2 - porozmawiaj z właścicilem\n";
                    do
                    {
                        std::cin >> tempDecision2;
                    } while (tempDecision2 < 1 || tempDecision2 > 2);
                    switch (tempDecision2)
                    {
                    case 1:
                        break;
                    case 2:
                        std::cout << "1 - Wynajmij kwaterę i odpocznij (koszt - 5 złotych monet), 2 - wypytaj o sytuację na wyspie\n";
                        do
                        {
                            std::cin >> tempDecision3;
                        } while (tempDecision3 < 1 || tempDecision3 > 2);
                        switch (tempDecision3)
                        {
                        case 1:
                            std::cout << "Po sytym i bogatym posiłku udajesz się do kwatery. Drzemasz.";
                            std::cout << "HP oraz MP powróciło do stanu maksymalnego.\n";
                            //hp + mp to max level wip
                            break;
                        case 2:
                            std::cout << "Nie będę ukrywał, lepsze czasy mam już za sobą. Niestabilność polityczna to coś, z czym\nzmagamy się już wielu lat.\n";
                            std::cout << "Coraz wyższe cła na import produktów z kontynentu sprawiają, że byle jaka ceramika to towar luksuowy. Inflacja nie ma litości.\n";
                            std::cout << "Sprawa jednak nabrała znacznie mroczniejszego wymiaru zważając na jak dotąd niewyjaśnione anomalie pogodowe. Trąby powietrzne, burze, sztormy stały się codziennością\n";
                            std::cout << "Szczególnie w północnej części wyspy oraz na otaczających ją wodach. Żaden kapitan nie ryzykuje skracania podróży - tamta część wyspy jest prawie opuszczona.\n";
                            std::cout << "Nie zawsze tak było. Jeszcze kilka lat temu działała tam kopalnia miedzi. Teraz nikt się tam nie zapuszcza.\n";
                            std::cout << "Między innymi przez trujące opary. I umarlaków-górników którzy powstali. Też na początku nie wierzyłem,\ndopóki jeden taki nie przeszedł dziesiątek kilometrów aż do naszego miasta.\n";
                            std::cout << "Właśnie po katastrofie na wyspie rozpoczęły się anomalie. Oczywiście, nasza kiepsko finansowana gwardia nie jest w stanie kopalni zabezpieczyć.\n";
                            std::cout << "Tamtego lata życie stracili nie tylko górnicy, ale także większość członków komisji mającej rozwiązać problem. Komisja była dobrze uzbrojna. Wróciło tylko kilku.\n";
                            std::cout << "Teraz już wiesz, czemu nikt się tam nie zapuszcza.\n";
                            std::cout << "Przynajmniej nasz lokalny browar sprzedaje się nieźle.\n";
                            std::cout << "1 - Spytaj, z kim jeszcze warto porozmawiać, 2 - Podziękuj za informacje i zakończ rozmowę\n";
                            do
                            {
                                std::cin >> tempDecision4;
                            } while (tempDecision4 < 1 || tempDecision4 > 2);
                            if (tempDecision4 == 1)
                            {
                                std::cout << "Alchemik szuka ziół które rosną na północy wyspy. Z oczywistych względów, sam się tam nie wybierze.\n";
                                std::cout << "Często można tu spotkać kartografa oraz przyrodnika-badacza.\n";
                                talkedWithOwnerAboutQuests = 1;
                            }
                            break;
                        }
                        break;
                     
                    }
                break;
                case 2:
                    int tempDecision_case_2_1;
                    std::cout << "Przy wejściu znajduje automat \"Wyścig po skarb\"\n";
                    std::cout << "1 - zagrasz, 2 - kierujesz się w głąb budynku\n";
                    do
                    {
                        std::cin >> tempDecision_case_2_1;
                    } while (tempDecision_case_2_1 < 1 || tempDecision_case_2_1 > 2);
                    if (tempDecision_case_2_1 == 1)
                    {
                        system("cls");
                        retroStarter();
                        system("cls");
                    }
                    else if (tempDecision_case_2_1 == 2)
                    {
                        hazard(locationXY);
                        
                    }
                   
                    break;
                case 3: 
                    std::cout << "Jeszcze tego samego dnia odpływa \"Szklany Kieł\". Zabierasz się na pokład.\n";
                    
                    locationXY->previousMap = locationXY->currentMap;
                    locationXY->currentMap = 1; //Solana
                    
                    locationXY->previousLocationX = locationXY->locationX;
                    locationXY->previousLocationY = locationXY->locationY;
                    locationXY->locationX = 10;
                    locationXY->locationY = 15;
                    showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
                    break;
                    
                }
        }
        break;
    case 200: //desert
        std::cout << "x: " << operX << " y: " << operY << "\n";
        std::cout << "ID: " << worldMapXYZ[locationXY->currentMap].allLocations[operX][operY] << "\n";
        std::cout << "Lokacja:Pustynia\n";
        showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
        desert(locationXY);
        break;
    case 203: //desert port town
        std::cout << "Solana to spalona słońcem wyspa. Jedynie w nielicznych oazach istnieje możliwość zdobycia wody.\n";
        std::cout << "Niestety, wskutek nieprzewidzianej ewolucji drapieżnych ptaków-ludziożerców próba eksploracji bogatej w minerały krainy stała się jeszcze bardziej niebezpieczna\n";
        std::cout << "Istnieje podejrzenie, że w centrum pustyni zapanowała pewna złowieszcza moc, która mutuje do tej pory nie zagrażające ludziom Orły Solańskie\n";
        std::cout << "Do tej pory, wszystkie drużyny śmiałków udające się w powyższe tereny nie wróciły pomimo upływających miesięcy\n";
        std::cout << "Masz możliwość wypoczynku - znajdujesz się w fortecy-mieście Zephir\n\n";
        int tempDecisionDesertFortress;
        
        printf(R"EOF(             
                 /^\ 
         [][][] /""\ [][][]           |#|
          |::| /____\ |::|           |===|
          |[]|_|::::|_|[]|            |0|       
          |::::::__::::::|            | |  
          |:::::/||\:::::|            | |              ____      ____        ____
          |:#:::||||::#::|           =====          __/ \--\  __/ \--\    __/ \--\                
         #%*###&*##&*&#*&##           _||_||_         H |_|__|  M |_|__|    S |_|__| 
        ##%%*####*%%%###*%*#
)EOF");


        std::cout << "\n1 - Odpocznij w motelu dla podróżncych, 2 - udaj się do machiny typu \"Baryłkacz\", \n3 - udaj się najbliższym statkiem na wyspę Ehime \n";
        do
        {
            std::cin >> tempDecisionDesertFortress;
        } while (tempDecisionDesertFortress < 1 || tempDecisionDesertFortress > 3);
        switch (tempDecisionDesertFortress)
        {
        case 1:
            std::cout << "Wybór jest szeroki\n";
            break;
        case 2:
            hazard(locationXY);
            break;
        case 3:
            std::cout << "Jeszcze tego samego dnia odpływa \"Pustynny Sokół\". Zabierasz się na pokład.\n";

            locationXY->previousMap = locationXY->currentMap;
            locationXY->currentMap = 0; //Ehime

            locationXY->previousLocationX = locationXY->locationX;
            locationXY->previousLocationY = locationXY->locationY;
            locationXY->locationX = 14;
            locationXY->locationY = 12;
            showWorldMap(worldMapXYZ, locationXY, locationXY->currentMap);
            break;

        }
        break;
        (*savingLoadingGameState_ptr)(locationXY, 2);
    }
    
}//skok

void changeOfLocation(struct player* playerXYZ, struct worldMap worldMapsXYZ[])
{ 
    
    std::cout << "Zdecydowałeś się wyruszyć w drogę\n\n";
    std::cout << "1 - północ, 2 - wschód, 3 - południe, 4 - zachód\n\n";
    std::cout << "Skierujesz się na: ";
    
    int decision;
    char empty;
    do
    {
      std::cin >> decision;
    } while (decision < 1 || decision > 4);
    switch (decision)
    {
    case 1:
        std::cout << "północ\n";
        playerXYZ->locationX--;
        if (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] == 101) //101 - ocean
        {
            std::cout << "Natknąłeś się na nieprzekraczalną przeszkodę: ocean. Wracasz do poprzedniej lokacji\n";
            playerXYZ->locationX++;
            std::cout << "Podaj -1 aby kontynować\n";
            std::cin >> empty;
        }
        system("cls");
        break;
    case 2:
        std::cout << "wschód\n";
        playerXYZ->locationY++;
        if (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationY][playerXYZ->locationX] == 101) //101 - ocean
        {
            std::cout << "Natknąłeś się na nieprzekraczalną przeszkodę: ocean. Wracasz do poprzedniej lokacji\n";
            playerXYZ->locationY--;
            std::cout << "Podaj -1 aby kontynować\n";
            std::cin >> empty;
        }
        system("cls");
        break;
    case 3:
        std::cout << "południe\n";
        playerXYZ->locationX++;
        if (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] == 101) //101 - ocean
        {
            std::cout << "Natknąłeś się na nieprzekraczalną przeszkodę: ocean. Wracasz do poprzedniej lokacji\n";
            playerXYZ->locationX--;
            std::cout << "Podaj -1 aby kontynować\n";
            std::cin >> empty;
        }
        system("cls");
        break;
    case 4:
        std::cout << "zachód\n";
        playerXYZ->locationY--;
        if (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] == 101) //101 - ocean
        {
            std::cout << "Natknąłeś się na nieprzekraczalną przeszkodę: ocean. Wracasz do poprzedniej lokacji\n";
            playerXYZ->locationY++;
            std::cout << "Podaj -1 aby kontynować\n";
            std::cin >>empty;

        }
        system("cls");
        
        break;
    }

}

void gameUpdate(struct player* playerXYZ, struct worldMap worldMapsXYZ[], struct items offensiveXYZ[], struct items defensiveXYZ[], struct items utilitiesXYZ[])
{
    (*savingLoadingGameState_ptr)(playerXYZ, 2);
   
    
    //savingLoadingGameState(playerXYZ, 2);
    whereAmI_XY(playerXYZ, worldMapsXYZ);
    (*savingLoadingGameState_ptr)(playerXYZ, 2);
    
    static int decEscape;
    int decisionEq, decisionWhatToDoWithEq;
    do
    {
        
        printf(R"EOF(
    ||==============================================================================================================================================||
    ||                                                                                                                                              ||
            Czas podjąć kolejne działania                                                                                                           ||
            1 - pora na dalszą podróż, 2 - medytacja, 3 - przegląd ekwipunku, , 4 - lista zadań, 5 - mapa świata, 6 - pozostań w danej lokacji      ||  
    ||                                                                                                                                              ||
    ||==============================================================================================================================================||
    )EOF");


        //std::cout << "Czas podjąć kolejne działania\n";
        //std::cout << "1 - pora na dalszą podróż, 2 - medytacja, 3 - przegląd ekwipunku, 4 - lista zadań, 5 - mapa świata\n";
        do
        {
            std::cin >> decEscape;
        } while (decEscape < 1 || decEscape > 6);
        switch (decEscape)
        {
        case 1:
            system("cls");
            
            switch (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY])
            {
            case 100:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Puszcza\n";
                
                break;
            case 101:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Ocean\n"; //for clarity this option will never execute
                
            case 102:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Polana\n";
                
                break;
            }
            
            showWorldMap(worldMapsXYZ, playerXYZ, playerXYZ->currentMap);
            changeOfLocation(playerXYZ, worldMapsXYZ);
            
            break;
        case 2:
            system("cls");
            std::cout << "Zwracasz szczególną uwagę na swój organizm. Jesteś w stanie określić swój stan fizyczny: \n";
            std::cout << "HP: " << playerXYZ->hp << "\n";
            std::cout << "MP: " << playerXYZ->mp << "\n";
            std::cout << "EXP: " << playerXYZ->exp << "\n";
            (*savingLoadingGameState_ptr)(playerXYZ, 2);
            break;
        case 3:
            system("cls");
            std::cout << "Oto posiadane przedmioty:\n";
            whatItemsAreEquiped(playerXYZ, 0, offensiveXYZ, defensiveXYZ, utilitiesXYZ); //0 - shows every item, need enum
            std::cout << "1 - ustal aktywnie używane przedmioty, 2 - usuń wybrany przedmiot z ekwipunku, 3 - powrót\n";
            do
            {
                std::cin >> decisionWhatToDoWithEq;
            } while (decisionWhatToDoWithEq < 1 || decisionWhatToDoWithEq > 3);
            switch (decisionWhatToDoWithEq)
            {
            case 1:
                activeEq(playerXYZ, 0, offensiveXYZ, defensiveXYZ, utilitiesXYZ); //praca4
                break;
            case 2:
                whatItemToUnequip(playerXYZ, 0, offensiveXYZ, defensiveXYZ, utilitiesXYZ);
                break;
            case 3:
                system("cls");
                //empty
                break;



            }
            
            break;
        case 4:
            system("cls");
            std::cout << "Zostałeś wysłany aby zrozumieć sytuację wyspy Ehime, z której dochodzą tragiczne wieści.\n";
            break;
        case 5:
            system("cls");
            std::cout << "Mapa świata: \n";
            
            switch (worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY])
            {
            case 100:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Puszcza\n";

                break;
            case 101:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Ocean\n"; //for clarity this option will never execute

            case 102:
                std::cout << "x: " << playerXYZ->locationX << " y: " << playerXYZ->locationY << "\n";
                std::cout << "ID: " << worldMapsXYZ[playerXYZ->currentMap].allLocations[playerXYZ->locationX][playerXYZ->locationY] << "\n";
                std::cout << "Lokacja: Polana\n";

                break;
            }
            
            
            showWorldMap(worldMapsXYZ, playerXYZ, playerXYZ->currentMap);
            break;
        case 6:
            system("cls");
            whereAmI_XY(playerXYZ, worldMapsXYZ);
            //decision to stay at current location
            break;
            (*savingLoadingGameState_ptr)(playerXYZ, 2);
        }
    } while (decEscape != 1);
    
    
    
}

int main()
{
    
    int mainMenuOptions;
    bool exitFromGame1 = false;
    
    setlocale(LC_CTYPE, "Polish"); 

    struct player player1;
    startingPlayerStats(&player1);

    struct items offensive[200], defensive[200],utilities[200];

    struct worldMap worldMaps[12];
    locationCreatorOnChoosenWorldMap(worldMaps, &player1, 20, 20, "Ehime", 0);
    locationCreatorOnChoosenWorldMap(worldMaps, &player1, 20, 20, "Solana", 1);
    //showWorldMap(worldMaps, &player1, 0);
    
    //teleport1
    creatingItems(&offensive[enmOgniomiot], 3, 1, 5, 4, 0, "Ogniomiot", enmOgniomiot, enmOffensiveType, &player1);
    creatingItems(&defensive[enmPancernyPłaszcz], 2, 2, 2, 4, 0, "Pancerny Płaszcz", enmPancernyPłaszcz, enmDefensiveType, &player1);
    creatingItems(&utilities[enmSmallHpPotion], 1, 1, 2, 4, 0, "Mała Mikstura PŻ", enmSmallHpPotion, enmUtilitiesType, &player1);

   

    
    //example: how to equip items
     equippingItems(&offensive[enmOgniomiot], &player1);
    equippingItems(&defensive[enmPancernyPłaszcz], &player1);
    equippingItems(&utilities[enmSmallHpPotion], &player1);
    //whatItemsAreEquiped(&player1, 0,offensive,  defensive, utilities);
   // whatItemToUnequip(&player1, 0, offensive, defensive, utilities);


    

  
   
   
    
    


    printf(R"EOF(
||===========================================================||
||                   ___====-_  _-====___                    ||
||             _--^^^#####//      \\#####^^^--_              ||
||          _-^##########// (    ) \\##########^-_           ||
||         -############//  |\^^/|  \\############-  DEF RPG ||
||       _/############//   (@::@)   \\############\_        ||
||      /#############((     \\//     ))#############\       ||
||     -###############\\    (oo)    //###############-      ||
||    -#################\\  / VV \  //#################-     ||
||   -###################\\/      \//###################-    ||
||  _#/|##########/\######(   /\   )######/\##########|\#_   ||
||  |/ |#/\#/\#/\/  \#/\##\  |  |  /##/\#/  \/\#/\#/\#| \|   ||
||  `  |/  V  V  `   V  \#\| |  | |/#/  V   '  V  V  \|  '   ||
||     `   `  `      `   / | |  | | \   '      '  '   '      ||
||                      (  | |  | |  )                       ||
||                     __\ | |  | | /__                      ||
||                    (vvv(VVV)(VVV)vvv)                     ||
||===========================================================||
)EOF");

    printf(R"EOF(
||===========================================================||
||                                                           ||
||         1 - Nowa Gra, 2 - Wczytaj Grę, 3 - Wyjście        ||                         
||                                                           ||
||===========================================================||
)EOF");
    
    
    std::cout << "\n";
    std::cin >> mainMenuOptions;
    

    switch (mainMenuOptions)
    {
    case 1:
        exitFromGame1 = false;
        break;
    case 2:
        exitFromGame1 = false;
        
        (*savingLoadingGameState_ptr)(&player1, 1);
        //savingLoadingGameState(&player1, 1);




        break;
    case 3:
         exitFromGame1 = true;
        break;
    }
    
    system("cls"); 
    if (!exitFromGame1)
    {
       
        for (;;)
        {
            gameUpdate(&player1, worldMaps, offensive, defensive, utilities);
        }
    }
    
    return 100;//program exit
    
}
