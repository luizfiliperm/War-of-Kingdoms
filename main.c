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
    char playerName[100];
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
    struct character character[6];

    // Warrior[0]

    strcpy(character[0].gameClass, "Guerreiro");
    character[0].hp = 42;
    character[0].stamina = maxStamina;
    character[0].attack = 10;
    character[0].defense = 8;
    character[0].criticalChance = 0;
    character[0].dodgeChance = 20;
    character[0].counterChance = 10;
    strcpy(character[0].sprite, "sprites/warrior.txt");

    // Assassin[1]
    strcpy(character[1].gameClass, "Assassino");
    character[1].hp = 33;
    character[1].stamina = maxStamina;
    character[1].attack = 13;
    character[1].defense = 3;
    character[1].criticalChance = 40;
    character[1].dodgeChance = 30;
    character[1].counterChance = 10;
    strcpy(character[1].sprite, "sprites/assassin.txt");

    // Swordsman[2]
    strcpy(character[2].gameClass, "Espadachim");
    character[2].hp = 33;
    character[2].stamina = maxStamina;
    character[2].attack = 13;
    character[2].defense = 5;
    character[2].criticalChance = 10;
    character[2].dodgeChance = 20;
    character[2].counterChance = 30;
    strcpy(character[2].sprite, "sprites/swordsman.txt");

    // Barbarian[3]
    strcpy(character[3].gameClass, "Barbaro");
    character[3].hp = 48;
    character[3].stamina = maxStamina;
    character[3].attack = 11;
    character[3].defense = 5;
    character[3].criticalChance = 0;
    character[3].dodgeChance = 10;
    character[3].counterChance = 20;
    strcpy(character[3].sprite, "sprites/barbarian.txt");

    // Knight[4]
    strcpy(character[4].gameClass, "Cavaleiro");
    character[4].hp = 39;
    character[4].stamina = maxStamina;
    character[4].attack = 11;
    character[4].defense = 7;
    character[4].criticalChance = 10;
    character[4].dodgeChance = 20;
    character[4].counterChance = 10;
    strcpy(character[4].sprite, "sprites/cavalier.txt");

    // Arqueiro[5]
    strcpy(character[5].gameClass, "Arqueiro");
    character[5].hp = 30;
    character[5].stamina = maxStamina;
    character[5].attack = 12;
    character[5].defense = 3;
    character[5].criticalChance = 40;
    character[5].dodgeChance = 50;
    character[5].counterChance = 10;
    strcpy(character[5].sprite, "sprites/archer.txt");



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

    FILE *leftSprite = fopen(spriteP2, "r");
    FILE *rightSprite = fopen(spriteP1, "r");

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
    printf("Stamina: %d\n", chooseCharacter.stamina);
    printf("Ataque: %d\n", chooseCharacter.attack);
    printf("Defesa: %d\n", chooseCharacter.defense);
    printf("Chance de Esquiva: %d%%\n", chooseCharacter.dodgeChance);
    printf("Chance de Critico: %d%%\n", chooseCharacter.criticalChance);
    printf("Chance de Contra-Atacar: %d%%\n", chooseCharacter.counterChance);
    showSprite(chooseCharacter.sprite);
}

int characterSelecion(int playerNumber){

    int min = 0;
    int max = 5;
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
        arrow(5, position);printf("Arqueiro\n");
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

void centralizeWidith(){
    printf("                                                                                                           ");
}
void centralizeHeight(){
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

int menu(){

    int position = 0;
    int key = 0;
    int min = 0;
    int max = 2;

    // key 13 -> ENTER
    while(key != 13){
        system("cls");
        centralizeHeight();
        centralizeWidith();printf("    !War of Kingdoms!\n\n");
        centralizeWidith();arrow(0, position); printf("||   Comecar   ||  \n");
        centralizeWidith();arrow(1, position); printf("||   Regras    ||  \n");
        centralizeWidith();arrow(2, position); printf("||   Sair      ||  \n");
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

void showPlayersData(struct character player[2], int currentHp[2], int currentStamina[2]){
    system("cls");
    for(int i = 0; i < 2; i++){
        printf("P%d - %d/%d Hp\n     %d/%d Stamina\n", i+1, currentHp[i], player[i].hp, currentStamina[i], player[i].stamina);
    }
    showDuelSprites(player[0].sprite, player[1].sprite);
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


void checkWinner(int currentHpPlayer[2], struct character player[2]){
    if(currentHpPlayer[0] <= 0 || currentHpPlayer[1] <= 0){
        if(currentHpPlayer[0] > currentHpPlayer[1]){
            printf("Player 1 venceu!\n\n");
            showSprite(player[0].sprite);
        }else if(currentHpPlayer[1] > currentHpPlayer[0]){
            printf("Player 2 venceu!\n\n");
            showSprite(player[1].sprite);
        }else{
            printf("EMPATE!!\n");
        }
    }
    printf("\nPressione Enter para continuar");
}

int actions(int playerNumber, struct character player, int currentHp, int currentStamina){
    int position = 0;
    int key = 0;

    while(key != 13){
        system("cls");
        printf("Vez de: %s!\n", player.gameClass);
        printf("HP: %d/%d\nStamina: %d/%d", currentHp,player.hp, currentStamina, player.stamina);

        printf("\nEscolha sua acao:\n");
        arrow(0, position); printf("|| Atacar   ( -2 Stamina ) (%d de dano)             ||\n",player.attack);
        arrow(1, position); printf("|| Bloquear ( -1 Stamina ) (%d de bloqueio)          ||\n",player.defense);
        arrow(2, position); printf("|| Esperar  ( +2 Stamina ) (%d%% Chance de esquiva)  ||\n",player.dodgeChance);
        showSprite(player.sprite);

        key = getch();
        fflush(stdin);

        if(key == 80 && position != 2){
            position++;
        }else if(key == 72 && position != 0){
            position --;
        }else{
            position = position;
        }

        if(key == 13  && currentStamina <= 1 && position == 0){
            printf("Voce nao pode realizar esta açao!");
            printf("\nPressione Enter para Selecionar novamente!");
            getch();
            key = 0;
        }else if(key == 13 && currentStamina == 0 && position <= 1 ){
            printf("Voce nao pode realizar esta açao!");
            printf("\nPressione Enter para Selecionar novamente!");
            getch();
            key = 0;
        }
    }
    return position;
}

int * roundResult(int playersChoose[2], struct character players[2], int currentPlayerHp[2]){
    // Both Attack
    int p1Attack = players[0].attack, p2Attack = players[1].attack;
    if(playersChoose[0] == 0 && percentage(players[0].criticalChance)){
            p1Attack *= 1.5;
            printf("Player 1 Critou!\n");
    }
    if(playersChoose[1] == 0 && percentage(players[1].criticalChance)){
            p2Attack *= 1.5;
            printf("Player 2 Critou!\n");
    }

    if(playersChoose[0] == 0  && playersChoose[1] == 0){

        currentPlayerHp[1] -= p1Attack;
        printf("\nO %s recebeu %d de dano!", players[1].gameClass, p1Attack);

        currentPlayerHp[0] -= p2Attack;
        printf("O %s recebeu %d de dano!",players[0].gameClass, p2Attack);

    }else if(playersChoose[0] == 0 && playersChoose[1] == 1){
        int damage = p1Attack - players[1].defense;

        printf("\nAtaque do player 1: %d\nDefesa do player 2: %d", p1Attack ,players[1].defense);
        printf("\nO Player 2 bloqueou %d de dano e perdeu %d de hp!\n", players[1].defense,damage);
        currentPlayerHp[1] -= p1Attack - players[1].defense;
        if(percentage(players[1].counterChance)){

            printf("\n\nO player 2 bloqueou parte do ataque, mas viu uma oportunidade e contra-atacou!!\n");
            currentPlayerHp[0] -= p2Attack / 2;
            printf("O player 1 recebeu %d de dano do contra ataque!\n",  p1Attack / 2);
        }

    }else if(playersChoose[0] == 1 && playersChoose[1] == 0){
        int damage = p1Attack - players[1].defense;

        printf("\nAtaque do player 2: %d\nDefesa do player 1: %d", p2Attack ,players[0].defense);
        printf("\nO Player 1 bloqueou %d de dano e perdeu %d de hp!\n", players[0].defense,damage);

        currentPlayerHp[0] -= p2Attack - players[0].defense;

        if(percentage(players[0].counterChance)){

            printf("\n\nO player 1 bloqueou parte do ataque, mas viu uma oportunidade e contra-atacou!!\n");
            currentPlayerHp[1] -= p1Attack / 2;
            printf("O player 2 recebeu %d de dano no contra ataque!\n",  p2Attack / 2);

        }

    }else if(playersChoose[0] == 0  && playersChoose[1] == 2){
        if(percentage(players[1].dodgeChance)){
            printf("O player 2 conseguiu desviar!\n");
        }else{
            printf("O player 2 tomou %d de dano", p1Attack);
            currentPlayerHp[1] -= p1Attack;
        }
    }else if(playersChoose[0] == 2  && playersChoose[1] == 0){
        if(percentage(players[0].dodgeChance)){
            printf("\nO player 1 conseguiu desviar!\n");
        }else{
            printf("O player 1 tomou %d de dano", p2Attack);
            currentPlayerHp[0] -= p2Attack;
        }
    }else{
        printf("Nada acontece!\n");
    }

    return currentPlayerHp;

}

void game(struct character player[2]){

    int currentHpPlayer[2] = {player[0].hp, player[1].hp};
    int currentStaminaPlayer[2] = {player[0].stamina, player[1].stamina};
    int *calculatedHpPlayer;
    int playersChoose[2];

    int resultedHp = 0;

    showPlayersData(player, currentHpPlayer, currentStaminaPlayer);

    system("cls");
    printf("Player 1: %s\n", player[0].gameClass);
    printf("Player 2: %s\n", player[1].gameClass);
    printf("Estao prontos?[Pressione Enter para continuar]\n");
    showDuelSprites(player[0].sprite, player[1].sprite);
    getchar();

    while(currentHpPlayer[0] > 0 && currentHpPlayer[1] > 0){

    for(int i = 0; i < 2; i++){
        playersChoose[i] = actions(i + 1, player[i], currentHpPlayer[i], currentStaminaPlayer[i]);
    }

    system("cls");

    // StaminaControler
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

    calculatedHpPlayer = roundResult(playersChoose,player,currentHpPlayer);
    currentHpPlayer[0] = calculatedHpPlayer[0];
    currentHpPlayer[1] = calculatedHpPlayer[1];

    printf("\nPressione Enter para continuar!\n");
    showDuelSprites(player[0].sprite, player[1].sprite);
    getchar();

    showPlayersData(player, currentHpPlayer, currentStaminaPlayer);
    checkWinner(currentHpPlayer, player);

    }
    printf("\n\nPressione Enter para voltar para o menu inicial!\n");
    getch();
    system("cls");

}

void printTxtFile(char txtName[100], int delay){
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    FILE *txtFile;

    txtFile = fopen(txtName, "r");
    char line[100];
    int lenLine;

    while(fgets(line, sizeof(line), txtFile)){
        lenLine = strlen(line);
        for(int i = 0; i < lenLine; i++){
            if(delay){
                Sleep(delay);
            }
            printf("%c", line[i]);
        }
    }
    printf("\n\nPressione Enter para continuar!");
    getch();
    fclose(txtFile);
}

void main(){
    setlocale(LC_ALL, "Portuguese");
    struct character player[2];
    int playerChoose;
    int menuChoose = 0;
    int count = 1;
    do{
        menuChoose =  menu();
        switch (menuChoose){
            case 0: // StartGame
                printTxtFile("texts/history.txt", 20);
                for(int i = 0; i < 2; i++){
                    playerChoose = characterSelecion(i + 1, count);
                    player[i] = allCharacters(playerChoose);
                    system("cls");
                }
                game(player);
                count++;
                break;
            case 1: // Rules
                printTxtFile("texts/rules.txt", 0);
                break;
            case 2: // Quit

                break;
            default:

                break;
        }
    }while(menuChoose != 2);
    system("cls");
    printf("Obrigado por jogar!");
    getch();
}
