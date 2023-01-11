// Funciones en el videojuego.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;

    //Atributos del enemigo
    int enemyHP = 100;
    int enemyDmg;
    string enemyName = "Sauron";
    bool enemyIsAlive = true;
    string enemyOption;
    int enemySelected;

    //Atributos del segundo enemigo
    int enemyHP2 = 100;
    int enemyDmg2;
    string enemyName2 = "Voldemort";
    bool enemyIsAlive2 = true;

    //Atributos del personaje
    int heroHP = 100;
    int heroDmg;
    string heroName;
    bool heroIsAlive = true;
    string attackOption;
    int espadaDmg = 50;
    int magiaDmg = 40;
    int cuchilloDmg = 30;

    //Atributo eleccion enemigo
    int enemigo;

    //Atributo de final de partida
    bool eleccionCorrecta = false;

    void inicio() {
        cout << "Como se llama el heroe?\n";
        cin >> heroName;
        cout << "El nombre del heroe es " << heroName << "\n";
        srand(time(NULL));
  }
    int enemySelect() {
        enemyOption = "g";
        if (enemyIsAlive || enemyIsAlive2) {
            while (enemyOption != "1" || enemyOption != "2") {
                cout << "A quien quieres atacar? [1]Sauron o [2]Voldemort\n";

                cin >> enemyOption;

                if (enemyOption == "1") {
                    return 1;
                }

                if (enemyOption == "2") {
                    return 2;
                }
            }
        }
    }
    void attackOption2(int& eneHP) {
        cout << "[a] espada [b] magia [c] cuchillo\n";
        cin >> attackOption;

        if (attackOption == "a") {
            cout << "Has hecho " << espadaDmg << " de danyo\n";
            eneHP = eneHP - espadaDmg;
        }

        if (attackOption == "b") {
            cout << "Has hecho " << magiaDmg << " de danyo\n";
            eneHP = eneHP - magiaDmg;
        }

        if (attackOption == "c") {
            cout << "Has hecho " << cuchilloDmg << " de danyo\n";
            eneHP = eneHP - cuchilloDmg;
        }
    }
    void heroAttack() {
        attackOption = "z";
        if (enemyOption == "1") {
            while (attackOption != "a" && attackOption != "b" && attackOption != "c") {
                cout << "Como quieres atacar a Sauron\n";
                attackOption2(enemyHP );
            }
        }
    
        if (enemyOption == "2") {
            while (attackOption != "a" && attackOption != "b" && attackOption != "c") {
                cout << "Como quieres atacar a Voldemort\n";
                attackOption2(enemyHP2);
            }
        }
    }   
    void checkEnemyStatus(string& eName, int& eneHP, bool& eneAl) {

        if (eneHP > 0) {
            cout << "La vida de " << eName << " es " << eneHP << "\n";
        }

        else if (eneHP <= 0) {
            cout << "Esta muerto\n";
            eneAl = false;
        }
    }
    bool enemydmg(int& eneDmg, string& eName) {
        eneDmg = 1 + (rand() % 25);
        heroHP = heroHP - eneDmg;
        cout << "El enemigo " << eName << " te ha atacado con " << eneDmg << "\n";
    }
    bool enemyAttack() {
        if (enemyIsAlive && heroIsAlive) {
            enemydmg(enemyDmg, enemyName);
            enemydmg(enemyDmg2, enemyName2);
        }

        if (heroHP > 0) {
            cout << "Te quedan " << heroHP << " puntos de vida\n";
            return true;
        }

        if (heroHP <= 0) {
            cout << "Has muerto\n";
            return false;
        }

    }
    int main() {
        
        inicio();
       
        while ((enemyIsAlive || enemyIsAlive2) && heroIsAlive) {
            
            enemySelected = enemySelect();
            heroAttack();

            if (enemySelected == 1) {
                checkEnemyStatus(enemyName,enemyHP, enemyIsAlive);
            }

            if (enemySelected == 2) {
                checkEnemyStatus(enemyName2, enemyHP2, enemyIsAlive2);
            }

            heroIsAlive = enemyAttack();

        }
    }