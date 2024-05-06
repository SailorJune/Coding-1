#include <ctime>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Using Bool, Void, and Int to make code easier later pleases my brain
// I am sorry if this is not optimal
void Say(string givenText) { cout << givenText << endl; }

int AddTwoNumbers(int firstNum, int secondNum) {
  int sum = firstNum + secondNum;

  return sum;
}

int SubtractTwoNumbers(int firstNum, int secondNum) {
  int sum = firstNum - secondNum;

  return sum;
}

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


/*
 *✲*´*。.❄¯*✲。❄。*¨`*✲´*。❄¨`*✲。❄。*`*
 *╔════════════ ༺❀༻❤༺❀༻ ════════════╗*
 *♥*❄¯*✲❄♫♪♩░M░A░I░N░ ░C░O░D░E░ ♫♫♪❄¯*✲❄
 *╚════════════ ༺❀༻❤༺❀༻ ════════════╝*
 *✲*´*。.❄¯*✲。❄。*¨`*✲´*。❄¨`*✲。❄。*`*
 */

int main() {
  // important variables
  srand(time(0));
  int player_hp = 15;
  int gold = 0;
  int ending_death = Diceroll(3);

  Say("hello adventurer");
  if (AskYN("would you like to go adventuring?")) {
    do {
      Say("You find an orc!\nIt's showtime!");
      Say("'You think you can beat me?!' Says the orc.");

      int orcpwr = Diceroll(6);

      cout << "He swings with " << orcpwr << " power!\n";

      int playerpwr = Diceroll(6);

      cout << "You block with " << playerpwr << " power!\n";

      if (playerpwr >= orcpwr) {
        int goldwin = Diceroll(10);
        cout << "You gave it your best shot and escaped with " << goldwin
             << " gold.\n";
        gold = gold + goldwin;
        cout << "You now have " << gold << " gold!\n";
        player_hp = player_hp - 1;
        Say("However, you did get hurt a little and took 1 dammage.");
      } else if (orcpwr > playerpwr) {
        Say("Ouch that hurt! Run away!");
        player_hp = player_hp - orcpwr;
        cout << "YEOUCH!! You took " << orcpwr << " dammage.\n";
      }
      if (player_hp <= 0) {
              if (ending_death == 1) {
                Say("You died");
              }
              if (ending_death == 2) {
              Say("Your bones are scraped clean by the desolate wind. Your Vault will "
                  "now surely die, as you have.");
            }
              if (ending_death == 3) {
              Say("All your base are belong to us!");
            }
        break;
      }
      cout << "You have " << player_hp << " Hp!\n";
      if (AskYN("do you want to keep adventuring?")) {
        cout << "Cool!\n";
      } else {
        cout << "That was a close one!\n";
        break;
      }
    } while (true);
  }
  // after do-while loop
  if (player_hp >= 5 && player_hp < 15) {
    Say("You Made "
        "it!"
        "\n░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░\n░░███████░░░░░░░░░░███▒▒"
        "▒▒▒▒▒▒███░░░░░░░\n░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███░░░░\n░░░█▒▒▒▒"
        "▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░░\n░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒"
        "▒▒███░\n░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██\n░░░█████████████▒▒"
        "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\n░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██\n░█"
        "█▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██\n██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒"
        "▒▒▒██▒▒▒▒▒██\n█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██\n██▒▒▒▒▒▒▒▒▒▒"
        "▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░\n░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██░"
        "░░\n░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█░░░░░\n░░████████████░░░█████"
        "████████████░░░░░░\n");
    cout << "You escape with " << player_hp << " Hp and " << gold << " Gold.\n";
    Say("At least you won't have to go to the doctors! All that money is "
        "yours!");
  } else if (player_hp < 5 && player_hp > 0) {
    Say("You look down at your hands covered in blood.");
    Say("Is it yours or the orc's?");
    Say("Does it really matter any more?");
    Say("You're just as much of a monster as they are...");
    cout << "You escape with " << player_hp << " Hp and " << gold << " Gold.\n";
    Say("Was all that bloodshed worth it...?");
    Say("Maybe you can pay your medical bills but you never be able to repay "
        "what you've done");
  } else if (player_hp == 15) {
    Say("You weren't able to pay rent because you were too lazy!");
  } 
}