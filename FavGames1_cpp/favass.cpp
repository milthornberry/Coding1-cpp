// Milly Thornberry
// Favorite Games Program

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

vector<string> favGames;
vector<string>::iterator iter;
iter = favGames.begin();

string input;


cout << "Welcome to Fav Games.\n";
cout << "Would you like to work on your list?\n";
cin >> input;
    
    while(input = "YES", "Yes", "yes") {
        cout << "\nYour commands are:\n\tAdd\n\tEdit\n\tDelete\n\tShow\n\tQuit\n\n";
        cout << "What would you like to do?\n";
        cin >> input;

        if(input == "Add") {
            cout << "What game would you like to add?\n";
            cin >> input;
            favGames.push_back(input);
            continue;
        }
        
        if(input == "Edit") {
            cout << "What game would you like to edit?\n";
            cin >> input;
            std::string targetGame = input;
            auto it = std::find(favGames.begin(), favGames.end(), targetGame);

                if(it != favGames.end()) {
                    cout << "What would you like to replace it with?\n";
                    cin >> input;
                    *it = input;
                    cout << "The game has been replaced by " << *it << ".\n";
                }if(it == favGames.end()) {
                    cout << "\nGame not found in list.\n";
                    continue;
                }
        }

        if(input == "Delete") {
            cout << "What game would you like to delete?\n";
            cin >> input;
            std::string targetGame = input;
            auto it = std::find(favGames.begin(), favGames.end(), targetGame);

                if(it == favGames.end()) {
                    cout << "Game not found in list.\n";
                    continue;
                }if(it != favGames.end()) {
                    favGames.erase(it);
                    cout << "" << input << " has been removed from the list.\n";
                }
        }

        if(input == "Show") {
            cout << "Here is your list of favorite games!\n\n";
            sort(favGames.begin(), favGames.end());

            for(int i = 0; i <favGames.size(); i++) {
                favGames[i].insert(0, to_string(i + 1) + " ");
            }

            for(int i = 0; i < favGames.size(); i++) {
                cout << "\t" << favGames[i] << "\n";
            }

        }

        if(input == "Quit") {
            cout << "Are you sure?\n";
            cin >> input;

            if(input == "Yes", "YES", "yes") {
                cout << "Thank you for playing!\n";
                return 0;
            }if(input != "Yes", "yes", "YES") {
                continue;
            }
        }
    }
}