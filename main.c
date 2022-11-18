#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#define maxStamina 8

typedef struct character{
    char gameClass[100];
    char sprite[100];

    struct stats{
        int hp;
        int stamina;
        int attack;
        int defense;
        int dodgeChance;
        int criticalChance;
        int counterChance;
    };
};

struct character allCharacters(int choose){
    struct character character[5];

    // Warrior[0]

    strcpy(character[0].gameClass, "Guerreiro");
    character[0].hp = 26;
    character[0].stamina = maxStamina;
    character[0].attack = 8;
    character[0].defense = 6;
    character[0].criticalChance = 0;
    character[0].dodgeChance = 10;
    character[0].counterChance = 0;
    strcpy(character[0].sprite, "sprites/warrior.txt");

    // Assassin[1]
    strcpy(character[1].gameClass, "Assassino");
    character[1].hp = 20;
    character[1].stamina = maxStamina;
    character[1].attack = 9;
    character[1].defense = 1;
    character[1].criticalChance = 40;
    character[1].dodgeChance = 30;
    character[1].counterChance = 0;
    strcpy(character[1].sprite, "sprites/assassin.txt");

    // Swordsman[2]
    strcpy(character[2].gameClass, "Espadachim");
    character[2].hp = 24;
    character[2].stamina = maxStamina;
    character[2].attack = 9;
    character[2].defense = 1;
    character[2].criticalChance = 20;
    character[2].dodgeChance = 10;
    character[2].counterChance = 0;
    strcpy(character[2].sprite, "sprites/swordsman.txt");

    // Barbarian[3]
    strcpy(character[3].gameClass, "Barbaro");
    character[3].hp = 32;
    character[3].stamina = maxStamina;
    character[3].attack = 8;
    character[3].defense = 3;
    character[3].criticalChance = 0;
    character[3].dodgeChance = 10;
    character[3].counterChance = 0;
    strcpy(character[3].sprite, "sprites/barbarian.txt");

    // Knight[4]
    strcpy(character[4].gameClass, "Cavaleiro");
    character[4].hp = 26;
    character[4].stamina = maxStamina;
    character[4].attack = 8;
    character[4].defense = 4;
    character[4].criticalChance = 10;
    character[4].dodgeChance = 10;
    character[4].counterChance = 10;
    strcpy(character[4].sprite, "sprites/cavalier.txt");
    
    return character[choose];
}

void showSprite(char spriteName[100]){
    FILE *sprite = fopen(spriteName, "r");
    char line[100];
    int lineSize;

    if(sprite == NULL){
        printf("Erro ao abrir o arquivo");
    }else{
        while(fgets(line, sizeof(line), sprite)){
            lineSize = strlen(line);
            for(int i = 0; i < lineSize; i++){
                printf("%c", line[i]);
            }
        }
    }
    printf("\n");
    fclose(sprite);
}

void showDuelSprites(char spriteP1[100], char spriteP2[100]){

    FILE *leftSprite = fopen(spriteP1, "r");
    FILE *rightSprite = fopen(spriteP2, "r");

    char leftLine[100], rightLine[100];
    int leftLineSize, rightLineSize;

    if(leftSprite == NULL || rightSprite == NULL){
        printf("Erro ao abrir o arquivo");
    }else{
        while(fgets(leftLine, sizeof(leftLine), leftSprite)){
            fgets(rightLine, sizeof(rightLine), rightSprite);

            leftLineSize = strlen(leftLine);
            rightLineSize = strlen(rightLine);

            for(int i = 0; i < leftLineSize; i++){
                if(leftLine[i] != '\n'){
                    printf("%c", leftLine[i]);
                }
            }
            for(int i = rightLineSize - 1; i >= 0; i--){
                printf("%c", rightLine[i]);
            }
        }
    }
    printf("\n");

    fclose(leftSprite);
    fclose(rightSprite);
}

void showCharacter(int position){
    struct character chooseCharacter = allCharacters(position);
    printf("\nHP: %d\n", chooseCharacter.hp);
    printf("Stamin: %d\n", chooseCharacter.stamina);
    printf("Ataque: %d\n", chooseCharacter.attack);
    printf("Defesa: %d\n", chooseCharacter.defense);
    printf("Chance de Esquiva: %d%%\n", chooseCharacter.dodgeChance);
    printf("Chance de Critico: %d%%\n", chooseCharacter.criticalChance);
    printf("Chance de Contra-Atacar: %d%%\n", chooseCharacter.counterChance);
    showSprite(chooseCharacter.sprite);
}

int characterSelecion(int playerNumber){
    
    int min = 0;
    int max = 4;
    int position = 0;
    int key = 0;

    // key 13 -> ENTER
    while(key != 13){

        system("cls");
        printf("Player %d, escolha seu personagem:\n", playerNumber);
        arrow(0, position);printf("Guerreiro\n");
        arrow(1, position);printf("Assassino\n");
        arrow(2, position);printf("Espadachim\n");
        arrow(3, position);printf("Barbaro\n");
        arrow(4, position);printf("Cavaleiro\n");
        showCharacter(position);

        key = getch();
        fflush(stdin);

        // key 80 -> up arrow
        if(key == 80 && position != max){
        position++;

        // key 72 -> down arrow
        }else if(key == 72 && position != min){
            position --;
        }else{
            position = position;
        }
    }
    return position;
}

void arrow(int realPosition, int arrowPosition){
    if(realPosition == arrowPosition){
        printf(" -->");
    }else{
        printf("    ");
    }
}

int menu(){

    int position = 0;
    int key = 0;
    int min = 0;
    int max = 2;

    // key 13 -> ENTER
    while(key != 13){
        system("cls");
        printf("      War of Kingdoms\n");
        arrow(0, position); printf("||   Start   ||  \n");
        arrow(1, position); printf("||   Rules   ||  \n");
        arrow(2, position); printf("||   Quit    ||  \n");
        key = getch();
        fflush(stdin);
        
        // key 80 -> up arrow
        if(key == 80 && position != max){
            position++;
        // key 72 -> down arrow
        }else if(key == 72 && position != min){
            position --;
        }else{
            position = position;
        }
    }
    return position;
}

int action(int playerName,int totalPlayerHp, int currentHp, int currentStamina, int totalPlayerStamina){
    int position = 0;
    int key = 0;

    while(key != 13){
        system("cls");
        printf("Vez de: %s!\n", playerName);
        printf("HP: %d/%d\nStamina: %d/%d", currentHp,totalPlayerHp, currentStamina, totalPlayerStamina);

        printf("\nEscolha sua acao:\n");
        arrow(0, position); printf("|| Atacar   ( -2 Stamina ) ||  \n");
        arrow(1, position); printf("|| Bloquear ( -1 Stamina ) ||  \n");
        arrow(2, position); printf("|| Esperar  ( +2 Stamina ) ||  \n");
        key = getch();
        fflush(stdin);
        if(key == 80 && position != 2){
            position++;
        }else if(key == 72 && position != 0){
            position --;
        }else{
            position = position;
        }
    }
    return position;
}

void showPlayersData(struct character player[2], int currentHp[2], int currentStamina[2]){
    system("cls");
    for(int i = 0; i < 2; i++){
        printf("P%d - %d/%d Hp\n     %d/%d Stamina\n", i+1, currentHp[i], player[i].hp, currentStamina[i], player[i].stamina);
    }
    printf("Pressione enter para Continuar!\n");
    getchar();
    system("cls");
}

int percentage(int chance){
    srand(time(NULL));

    int r = (rand()%100)+1;

    if (r <= chance){
    return 1;
   }
   return 0;
}


void checkWinner(int currentHpPlayer[2]){
    int hpDifference = currentHpPlayer[0] - currentHpPlayer[1];

    if(currentHpPlayer[0] < 0 || currentHpPlayer < 0){
        if(hpDifference > 0){
            printf("Player 1 Venceu!\n");
        }else if(hpDifference < 0){
            printf("Player 2 Venceu!\n");
        }else{
            printf("EMPATE!!\n");
        }
    }
    
}

int actions(int playerNumber, struct character player, int currentHp, int currentStamina){
    int position = 0;
    int key = 0;

    while(key != 13){
        system("cls");
        printf("Vez de: %s!\n", player.gameClass);
        printf("HP: %d/%d\nStamina: %d/%d", currentHp,player.hp, currentStamina, player.stamina);

        printf("\nEscolha sua acao:\n");
        arrow(0, position); printf("|| Atacar   ( -2 Stamina ) ||  \n");
        arrow(1, position); printf("|| Bloquear ( -1 Stamina ) ||  \n");
        arrow(2, position); printf("|| Esperar  ( +2 Stamina ) ||  \n");
        key = getch();
        fflush(stdin);
        if(key == 80 && position != 2){
            position++;
        }else if(key == 72 && position != 0){
            position --;
        }else{
            position = position;
        }
    }
    return position;
}

void game(struct character player[2]){

    int currentHpPlayer[2] = {player[0].hp, player[1].hp};
    int currentStaminaPlayer[2] = {player[0].stamina, player[1].stamina};
    int playersChoose[2];

    int resultedHp = 0;

    showPlayersData(player, currentHpPlayer, currentStaminaPlayer);


    system("cls");
    printf("Player 1: %s\n", player[0].gameClass);
    printf("Player 2: %s\n", player[1].gameClass);
    printf("Estao prontos?[Pressione Enter botao para continuar]\n");
    showDuelSprites(player[0].sprite, player[1].sprite);
    getchar();

    while(currentHpPlayer[0] > 0 && currentHpPlayer[1] > 0){

    for(int i = 0; i < 2; i++){
        playersChoose[i] = actions(i + 1, player[i], currentHpPlayer[i], currentStaminaPlayer[i]);
    }

    system("cls");
    for(int i = 0; i < 2; i++){
        printf("Player [%d] escolheu:\n", i + 1);
        switch (playersChoose[i])
        {
        case 0:
            printf("Atacar!\n");
            currentStaminaPlayer[i] -= 2;
            break;
        case 1:
            printf("Bloquear!\n");
            currentStaminaPlayer[i] -= 1;
            break;
        case 2:
            printf("Esperar!\n");
            if((currentStaminaPlayer[i] + 2) > maxStamina){
                currentStaminaPlayer[i] = maxStamina;
            }else{
            currentStaminaPlayer[i] += 2;
            }
        default:
            break;
        }
    }
    

    resultedHp = 0;

    if(playersChoose[0] == 0  && playersChoose[1] != 1){
        currentHpPlayer[1] -= player[0].attack;
        printf("\nAtaque do player 1: %d", player[0].attack);
    }else if(playersChoose[0] == 0 && playersChoose[1] == 1){
        resultedHp = player[0].attack - player[1].defense;
        printf("\nAtaque do player 1: %d\nDefesa do player 2: %d", player[0].attack, player[1].defense);
        if(resultedHp < 0){
            resultedHp = 0;
        }
        currentHpPlayer[1] -= resultedHp;
    }

    resultedHp = 0;

    if(playersChoose[1] == 0  && playersChoose[0] != 1){
        currentHpPlayer[0] -= player[1].attack;
        printf("\nAtaque do player 2: %d", player[1].attack);
    }else if(playersChoose[1] == 0 && playersChoose[0] == 1){
        resultedHp = player[1].attack - player[0].defense;
        printf("\nAtaque do player 2: %d\nDefesa do player 1: %d", player[1].attack, player[0].defense);
        if(resultedHp < 0){
            resultedHp = 0;
        }
        currentHpPlayer[0]  -= resultedHp;
    }

    printf("\nPressione Enter para continuar!\n");
    showDuelSprites(player[0].sprite, player[1].sprite);
    getchar();

    checkWinner(currentHpPlayer);
    }
    system("cls");
    
}

void history(){
    system("cls");

    char historia[500] = "Em uma terra distante, existem dois reinos rivais, a paz entre \nos dois era um fio fino que a qualquer momento poderia romper,\nestourando a maior guerra ja vista pelos dois povos, para evitar \nos possiveis danos os reis concordaram em criar um evento anual \nde batalhas entre seus representantes, lutando entre si em busca \nda gloria para honrar o seu reino. \n\nQuem sera o grande vencedor dessa batalha?";

    int cont = 0;

    cont = strlen(historia);

    for (int i = 0; i < cont; ++i){
        printf("%c", historia[i]);
        Sleep(1);
    } 

    getch();
} 

void main(){   
    struct character player[2];
    int playerChoose;
    int menuChoose = 0;

    do{
        menuChoose =  menu();
        switch (menuChoose){
            case 0: // StartGame
                history();
                for(int i = 0; i < 2; i++){
                    playerChoose = characterSelecion(i + 1);
                    player[i] = allCharacters(playerChoose);
                }
                game(player);
                break;
            case 1: // Rules
                
                break;
            case 2: // Quit

                break;
            default:

                break;
        }
    }while(menuChoose != 2);
    printf("Obrigado por jogar!");
}