#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Say(string givenText) { cout << givenText << endl; }

bool AskYN(string question) {
  do {
    cout << question << " y/n\n";
    char input;
    cin >> input;

    if (input == 'y') {
      return true;
    }
    if (input == 'n') {
      return false;
    }

    cout << "You need to type a lowercase 'y' or 'n'.\n";
  } while (true);
}

int Diceroll(int sides = 6) {
  if (sides < 1) {
    sides = 2;
  }
  if (sides > 100) {
    sides = 100;
  }

  return rand() % sides + 1;
}

// I do not understand enum. I tried my best using the video. I'm sorry.
enum itemType { weapon, tool, consumable };

enum elementalType { fire, water, grass, normal };

class item {
public:
  itemType type;
  int weaponDmg;
  string name;
  elementalType element;
  int remainingUses;
  int healingAmount;

  // build a fancy constructor
  item(string n, itemType t) {
    name = n; // assign the name of the item to the given name
    type = t;

    if (type == weapon) {
      // calculate weaponDmg and element
      weaponDmg = rand() % 5 + 3;
      element =
          (elementalType)(rand() % 4); // typecast an int into an elementalType
      remainingUses = 9999;
      healingAmount = 0;
    } else if (type == tool) {
      weaponDmg = 1;
      element = normal;
      remainingUses = rand() % 5 + 1;
      healingAmount = 0;
    } else if (type == consumable) {
      healingAmount = rand() % 5 + 1;
      weaponDmg = -healingAmount;
      element = normal;
      remainingUses = 1;
    }
  } // end of item constructor

  void Inspect() {
    cout << name << " has damage of " << weaponDmg << ", its element is "
         << elementToString(element) << ".\n";
    cout << "It can be used " << remainingUses << " more times, heals for "
         << healingAmount << ",\n";
    cout << "And is the item type " << typeToString(type) << ".\n\n";
  }

  string typeToString(itemType type) {
    // switch statment like if statment, but only has to test once. All possible
    // values mapped.
    switch (type) {
    case weapon:
      return "weapon";
      break;
    case tool:
      return "tool";
      break;
    case consumable:
      return "consumable";
      break;
    default:
      return "unknown";
      break;
    }
  }

  string elementToString(elementalType element) {
    switch (element) {
    case fire:
      return "fire";
      break;
    case water:
      return "water";
      break;
    case grass:
      return "grass";
      break;
    case normal:
      return "normal";
      break;
    default:
      return "unknown";
      break;
    }
  }

  string elementString() { return elementToString(element); }
};

class enemy {
private:
  // data members = (variables)
  string name;
  int EnStr;
  int enHp;
  // member functions = (functions)
public:
  void status() {
    cout << "[species: " << name << ", power: " << EnStr << ", HP: " << enHp
         << "]\n";
  }

  enemy(string givenName = "Enemy", int givenEnStr = 10, int givenEnHp = 10) {
    name = givenName;
    EnStr = givenEnStr;
    enHp = givenEnHp;
  }

  // setters
  void SetName(string givenName) {
    if (givenName.size() < 30) {
      name = givenName;
    } else {
      cout << "error, names must  be less than 30 characters\n";
    }
  }

  void SetEnStr(int givenEnStr) {
    if (givenEnStr > 0) {
      EnStr = givenEnStr;
    } else {
      EnStr = 10;
    }
  }

  void SetEnHP(int givenEnHp) {
    if (givenEnHp > 0) {
      enHp = givenEnHp;
    } else {
      enHp = 10;
    }
  }

  // getters
  string GetName() { return name; }
  int GetEnStr() { return EnStr; }
  int GetEnHp() { return enHp; }
};

int main() {
  srand(time(0));
  // player stats and level
  int pHP = 12;
  vector<string> weaponNames = {"Sword",     "Axe",    "Mace", "Hammer",
                                "Spear",     "Dagger", "Club", "Flail",
                                "Warhammer", "Halberd"};

  vector<string> orcNames = {"Grommash, The Orc", "Thrall, The Orc",
                             "Durotan, The Orc",  "Blackhand, The Orc",
                             "Gul'dan, The Orc",  "Garrosh, The Orc",
                             "Kargath, The Orc",  "Kilrogg, The Orc",
                             "Ner'zhul, The Orc", "Mannoroth, The Orc"};

  vector<item> weapons;
  vector<enemy> orcs;

  for (int i = 0; i < weaponNames.size(); i++) {
    weapons.push_back(item(weaponNames[i], weapon));
  }

  for (int i = 0; i < 10; i++) {
    string tempName = orcNames[rand() % orcNames.size()]; // random name
    int strght = (rand() % 4 + weapons[i].weaponDmg);
    int enhp = (rand() % 5 + 18);
    orcs.push_back(enemy(tempName, strght, enhp)); // add new enemy
  }

  Say("hello adventurer");
  if (AskYN("would you like to go adventuring?")) {
    for (int i = 0; i < orcs.size(); i++) {
      Say("you encounter an enemy");

      orcs[i].status();
      weapons[i].Inspect();

      cout << orcs[i].GetName() << " swings for " << orcs[i].GetEnStr()
           << " of " << weapons[i].elementString() << "\n";

      pHP = pHP - orcs[i].GetEnStr();

      cout << "You now have " << pHP << " HP!\n";

      if (AskYN("do you want to keep adventuring?")) {
        cout << "Cool! You got your butt handed to you!\n";
      } else {
        cout << "That was a close one!\n";
        break;
      }
    }
  }
}