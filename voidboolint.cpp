#include <iostream> 
#include <string> 
#include <vector>
#include <ctime>
using namespace std; 

void SayHello() {
    cout << "Hello" << endl;
}

void Say(string givenText){
    cout << givenText << endl;
}

int AddTwoNumbers(int firstNum, int secondNum){
    int sum = firstNum + secondNum;

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
    }while (true);
}

//int Diceroll(){
//    return rand() % 6 + 1;
//}

int Diceroll(int sides = 6){
    if (sides < 1){
        sides = 2;
    }
    if (sides > 100){
        sides = 100;
    }
    
    return rand() % sides + 1;
    
}

//create CastDmg() function that retuens an int.
//accepts two input parameters min and max
//creates a int damage that is random in a range from min to max.
//rolls a d6 for crit chance (if d6 = 6, double damage).
//then returns damage
//use default values
//in main(), call this function 10 times using a for loop.

int CastDmg(int min, int max){
    int damage = rand() % (max-min) + min;
     if (Diceroll() == 6){
         damage += damage; 
     }

    return damage;
    
}

int main() {
    srand(time(0));
    cout << "your roll is " << Diceroll() << ".\n";
    cout << "Your d20 roll is " <<Diceroll(20) << ".\n";
    cout << "Your D-14 roll is " <<Diceroll(-14) << ".\n";

    int PlayerHP = 100;
    cout << "here we go adventuring!\n";
    cout << "Oh no! we stubbed our toes... all 9 of them...\n";
    do {
            
        int TakenDmg = CastDmg(6, 7);
        PlayerHP -= TakenDmg;
        cout << "Oh no! We took " << TakenDmg << " points of dmg!";

        if(PlayerHP <= 0) break;
                
        cout << "We now have " << PlayerHP << " health.\n";

        if(AskYN("do you want to keep adventuring?")){
            cout << "Cool!\n";
        } else {
            cout << "We're so joe-ver\n";
            break;
        }
    } while(true);

    
    SayHello();
    SayHello();
    Say("How are you today?");
    Say("My name is Bobalobadoba.");

    cout << "4 + 5 = " << AddTwoNumbers(4,5) << "\n";

    AskYN("F it we ball?");
    cout << "You do: " << CastDmg(1, 20) << " damage!\n";

    for(int i = 0; i < 10; i ++){
        int TakenDmg = CastDmg(12,24);
        cout << "Enemy does " << TakenDmg << " Damage!!\n";
        PlayerHP -= TakenDmg;
        cout << "You have " << PlayerHP << " HP\n";
    }
}