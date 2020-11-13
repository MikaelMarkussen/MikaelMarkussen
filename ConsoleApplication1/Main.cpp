#include "Comp3.h"



int main() {
    loginPage();
}

void loginPage() {
    int j = 0;
    int h = 0;
    int k = 0;
    bool rightPassword=false;
 
    std::ifstream password;
    password.open("password.txt");
    std::string Pass1;

    std::vector<std::string> passGrid{ "*","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P" };
    const std::vector<std::string> passGridRef{ "A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P" };
    std::vector<std::string> passwordInput{ "0","0","0","0","0","0","0","0","0","0" };
  
    do {
        for (int i = 0; i < passGrid.size(); i++) {
            if (i % 4 == 0) {
                std::cout << "\n\n";
            }
            std::cout << "|" << passGrid[i] << "|" << std::setw(5);
        }
        passGrid[j] = '*';
        switch (_getch()) {
        case 'a': case 'A':
            switch (j) {
            case 0:
                j = 3;
                h = 0;
                passGrid[h] = passGridRef[h];
                break;
            case 4:
                j = 7;
                h = 4;
                passGrid[h] = passGridRef[h];
                break;
            case 8:
                j = 11;
                h = 8;
                passGrid[h] = passGridRef[h];
                break;
            case 12:
                j = 15;
                h = 12;
                passGrid[h] = passGridRef[h];
                break;
            default:
                j--;
                h = j+1;
                passGrid[h] = passGridRef[h];
                break;
            }
            passGrid[j];

            break;
        case 'd': case 'D':
            switch (j) {
            case 3:
                j = 0;
                h = 3;
                passGrid[h] = passGridRef[h];
                break;
            case 7:
                j = 4;
                h = 7;
                passGrid[h] = passGridRef[h];
                break;
            case 11:
                j = 8;
                h = 11;
                passGrid[h] = passGridRef[h];
                break;
            case 15:
                j = 12;
                h = 15;
                passGrid[h] = passGridRef[h];
                break;
            default:
                j++;
                h = j-1;
                passGrid[h] = passGridRef[h];
                break;
            }
            break;
        case 'W': case 'w':
            switch (j) {
            case 0:
                j = 12;
                h = 0;
                passGrid[h] = passGridRef[h];
                break;
            case 1:
                j = 13;
                h = 1;
                passGrid[h] = passGridRef[h];
                break;
            case 2:
                j = 14;
                h = 2;
                passGrid[h] = passGridRef[h];
                break;
            case 3:
                j = 15;
                h = 3;
                passGrid[h] = passGridRef[h];
                break;
            default:
                j = j- 4;
                h = j + 4;
                passGrid[h] = passGridRef[h];
                break;
            }
            break;
        case 's': case 'S': 
            switch (j) {
            case 12:
                j = 0;
                h = 12;
                passGrid[h] = passGridRef[h];
                break;
            case 13:
                j = 1;
                h = 13;
                passGrid[h] = passGridRef[h];
                break;
            case 14:
                j = 2;
                h = 14;
                passGrid[h] = passGridRef[h];
                break;
            case 15:
                j = 3;
                h = 15;
                passGrid[h] = passGridRef[h];
            default:
                j +=4;
                h = j - 4;
                passGrid[h] = passGridRef[h];
                break;
            }
            break;
        case 13:
            passwordInput[k] = passGridRef[j];
            k++;
            break;
        }
        passGrid[j] = '*';
        system("cls");
        std::string passStr;
        passStr = passwordInput[0] + passwordInput[1] + passwordInput[2] + passwordInput[3] + passwordInput[4] + passwordInput[5]+ passwordInput[6]+ passwordInput[7]+ passwordInput[8]+ passwordInput[9];
        std::cout << passStr;
        std::getline(password, Pass1);
        if (passwordInput[9] != "0"&& Pass1 == passStr) {
            rightPassword = true;
            mainMenu();

        }else if(passwordInput[9] != "0" && Pass1 != passStr) {

            std::cout << std::endl << "[ERROR] Wrong password";
            passwordInput[0] = '0';
            passwordInput[1] = '0';
            passwordInput[2] = '0';
            passwordInput[3] = '0';
            passwordInput[4] = '0';
            passwordInput[5] = '0';
            passwordInput[6] = '0';
            passwordInput[7] = '0';
            passwordInput[8] = '0';
            passwordInput[9] = '0';

         }
    } while (rightPassword==false);
    password.close();
}
void mainMenu(){
    int answer;
    bool answered = false;
    system("cls");
    do{


        std::cout << "----Main Menu-----\n";
        std::cout << "1.Change the password\n";
        std::cout << "2.Play battleships\n";
        std::cout << "3.Quit\n";
        std::cout << "Select an option (1-3): \n";
        std::cin >> answer;
        switch (answer)
        {
        case 1:
            changePassword();
            break;
        case 2:
            
            break;
        case 3:
            quit();
            break;
        }
        if (answer <= 3) {
            answered == true;
        }
        else {
            std::cout << "\nIncorrect input\n";
        }
    } while (answered == false);
}
void changePassword() {
    std::string i;
    std::ofstream outPassword;
    outPassword.open("password.txt");
    std::cout << std::endl << "Enter a new password:(9 Characters between A-P In a string)\n";  //this will fail if someone put numbers or small letters inn. i couldnt think or find a soulution
    std::cin >> i;
    if (!outPassword) {
        std::cout << "[Error] file not opend";
    }

 else if (i.length() <= 9) {
        outPassword << i;

    }



}
void quit() {
    exit(3);
}



