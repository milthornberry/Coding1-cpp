// Milly Thornberry June 16, 2025
// Adventure Assignment week one

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));

    cout << "Welcome to your grand adventure...\n\n";
    cout << "What is your name, traveler?\n";

    string userName = "";
        cin >> userName;
    
    cout << "\nA glorious name indeed, " << userName << "! One fit for an adventurer.\n\n";

    char answerYN = 'y';
    
    int playerHp = 20;
    int gold = 0;
    int enemyHp = 8;
    int loot = rand() % 100 + 8;
    

    cout << "Adventure calls to you, " << userName << ". Will you answer? y/n\n";
    cin >> answerYN;
if(answerYN == 'y') {
        cout << "\nThe road lies before you dark and desolate.";
    while(answerYN == 'y' && playerHp > 0) {
        cout << "\nAn enemy looms near! Roll to attack.\n\n";

        int playerAtt = rand() % 6 + 1;
        int enemyAtt = rand() % 6 + 1;
        int playDamage = rand() % 6 + 1;

        cout << "You rolled " << playerAtt << ".\n";
        cout << "The enemy rolled " << enemyAtt << ".\n";

        if(playerAtt >= enemyAtt) {
            cout << "\nYou won! Your enemy crumples before you.\n";
            gold += loot;
            cout << "\nYou have " << playerHp << " health and " << gold << " gold.\n";
        }else if(playerAtt < enemyAtt) {
            playerHp -= playDamage;
            cout << "\nYou got hit and ran for your life.\n";
            cout << "\nYou have " << playerHp << " health and " << gold << " gold.\n";
        }
        if(playerHp <= 0) {
            cout << "You took too much damage and died.\n";
            cout << "Your bloodied " << gold << " gold lays next to you on the road.\n";
        }
        
        if(playerHp >= 1) {
            cout << "Would you like to continue adventuring?\n";
            cin >> answerYN;
            if(answerYN == 'y') {
                cout << "Quite the brave adventurer you are!\n";
            }else if(answerYN == 'n') {
                cout << "\nPerhaps you will be braver another day.\n\n";
                cout << "You concluded your adventure with:\n";
                cout << "" <<playerHp << " health and " << gold << " gold.\n";
                if(playerHp <= 5 && gold >= 20){
                    cout << "You aren't looking so good, " << userName << ".\n";
                    cout << "You should probably see a doctor.\n";
                }
                break;
            }
        }
        }

    }else if(answerYN == 'n') {
        cout << "\nPerhaps you will be braver another day.\n\n";
        cout << "You concluded your adventure with:\n";
        cout << "" <<playerHp << " health and " << gold << " gold.\n";

        return 0;
    }
} // end of main function