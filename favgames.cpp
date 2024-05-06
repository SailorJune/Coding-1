#include "main.h"

int main() {
  // Load games from the file into our vector
  FileInteractions fileInteractions; // Create an instance of FileInteractions

  fileInteractions.load(favGames, fileName); // Call the load function using the
                                             // instance of FileInteractions

  // add a game and show it
  addGame();
  showGames();

  // clear games and show it
  clearGames();
  showGames();

  // add a game then remove it and show it
  addGame();
  removeGame();
  showGames();

  // add a game then edit it and show it
  addGame();
  editGame();
  showGames();

  // save games to file
  fileInteractions.save(favGames, fileName);
}

void addGame() {
  string game;
  cout << "What game would you like to add?\n";
  getline(cin, game);
  favGames.push_back(game);
}
void showGames() {
  cout << "\n\nHere are your favorite games:\n";
  for (int game = 0; game < favGames.size(); game++) {
    cout << favGames[game] << endl;
  }
}
void removeGame() {
  string game;
  cout << "What game would you like to remove?\n";
  getline(cin, game);
  for (int gameNum = 0; gameNum < favGames.size(); gameNum++) {
    if (favGames[gameNum] == game) {

      favGames.erase(favGames.begin() + gameNum);
      cout << "The game has been removed.\n";
      return;
    }
    cout << "I couldn't find that game.\n";
  }
}
void editGame() {
  string gameToEdit;
  cout << "What game would you like to edit?\n";
  getline(cin, gameToEdit);
  for (int gameNum = 0; gameNum < favGames.size(); gameNum++) {
    if (favGames[gameNum] == gameToEdit) {
      cout << "What would you like to change " << favGames[gameNum] << " to?\n";
      getline(cin, favGames[gameNum]);
      cout << "game edited!\n";
      return;
    }
  }
  cout << "I couldn't find that game.\n";
}
void clearGames() { favGames.clear(); }