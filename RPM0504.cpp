#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <memory>

using namespace std;

class IGame {
public:
    virtual ~IGame() = default;
    virtual void play() = 0;
};

class GameFactory {
public:
    static unique_ptr<IGame> createGame(int choice);
};

class GameMenu {
private:
    static GameMenu* instance;
    GameMenu() = default;

public:
    static GameMenu* getInstance() {
        if (!instance) {
            instance = new GameMenu();
        }
        return instance;
    }

    void showMenu() {
        while (true) {
            system("cls");
            cout << "=== ГЛАВНОЕ МЕНЮ ===" << endl;
            cout << "1. Кости" << endl;
            cout << "2. Камень-Ножницы-Бумага" << endl;
            cout << "3. Дартс" << endl;
            cout << "4. Выход" << endl;
            cout << "Выберите игру: ";

            string choice;
            cin >> choice;

            if (choice == "4") break;

            auto game = GameFactory::createGame(stoi(choice));
            if (game) {
                game->play();
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
                system("pause");
            }
        }
    }
};

GameMenu* GameMenu::instance = nullptr;

class DiceGame : public IGame {
public:
    void play() override {
        while (true) {
            system("cls");
            cout << "=== ИГРА В КОСТИ ===" << endl;
            cout << "1. Бросить кости" << endl;
            cout << "2. Вернуться в главное меню" << endl;
            cout << "Выберите действие: ";

            string choice;
            cin >> choice;

            if (choice == "2") break;

            if (choice == "1") {
                int playerRoll = rollDice();
                int computerRoll = rollDice();

                cout << "\nВы выбросили: " << playerRoll << endl;
                cout << "Компьютер выбросил: " << computerRoll << endl;

                showResult(playerRoll, computerRoll);
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }

            cout << "\nНажмите любую клавишу для продолжения...";
            system("pause");
        }
    }

private:
    int rollDice() const {
        return (rand() % 6 + 1) + (rand() % 6 + 1);
    }

    void showResult(int player, int computer) const {
        if (player > computer)
            cout << "Вы победили!" << endl;
        else if (player < computer)
            cout << "Компьютер победил!" << endl;
        else
            cout << "Ничья!" << endl;
    }
};

class RockPaperScissors : public IGame {
public:
    void play() override {
        while (true) {
            system("cls");
            cout << "=== КАМЕНЬ-НОЖНИЦЫ-БУМАГА ===" << endl;
            cout << "1. Камень" << endl;
            cout << "2. Ножницы" << endl;
            cout << "3. Бумага" << endl;
            cout << "4. Вернуться в главное меню" << endl;
            cout << "Выберите действие: ";

            string choice;
            cin >> choice;

            if (choice == "4") break;

            if (choice == "1" || choice == "2" || choice == "3") {
                int playerChoice = stoi(choice) - 1;
                int computerChoice = rand() % 3;

                showChoices(playerChoice, computerChoice);
                showResult(playerChoice, computerChoice);
            }
            else {
                cout << "Неверный выбор. Попробуйте снова." << endl;
            }

            cout << "\nНажмите любую клавишу для продолжения...";
            system("pause");
        }
    }

private:
    const vector<string> choices = { "камень", "ножницы", "бумага" };

    void showChoices(int player, int computer) const {
        cout << "\nВы выбрали: " << choices[player] << endl;
        cout << "Компьютер выбрал: " << choices[computer] << endl;
    }

    void showResult(int player, int computer) const {
        if (player == computer) {
            cout << "Ничья!" << endl;
        }
        else if ((player == 0 && computer == 1) ||
            (player == 1 && computer == 2) ||
            (player == 2 && computer == 0)) {
            cout << "Вы победили!" << endl;
        }
        else {
            cout << "Компьютер победил!" << endl;
        }
    }
};

class DartsGame : public IGame {
public:
    void play() override {
        const int THROWS = 5;

        while (true) {
            system("cls");
            cout << "=== ИГРА В ДАРТС ===" << endl;
            cout << "1. Начать игру (5 бросков)" << endl;
            cout << "2. Вернуться в главное меню" << endl;
            cout << "Выберите действие: ";

            string choice;
            cin >> choice;

            if (choice == "2") break;

            if (choice == "1") {
                playRound(THROWS);
            }
            else {
                cout << "Неверный выбор. Попробуйте снова.";
                cin.ignore();
                cin.get();
            }
        }
    }

private:
    void playRound(int throws) {
        int playerTotal = 0;
        int computerTotal = 0;

        for (int i = 0; i < throws; i++) {
            system("cls");
            cout << "Бросок " << i + 1 << " из " << throws << endl;

        
            cout << "\nВаш бросок (нажмите Enter)...";
            cin.ignore();
            cin.get();

            int playerThrow = makeThrow();
            playerTotal += playerThrow;

         
            int computerThrow = makeThrow();
            computerTotal += computerThrow;

            showThrowResults(playerThrow, playerTotal, computerThrow, computerTotal);

            if (i < throws - 1) {
                cout << "\n\nНажмите Enter для следующего броска...";
                cin.get();
            }
        }

        showFinalResults(playerTotal, computerTotal);
    }

    int makeThrow() const {
        return rand() % 60 + 1;
    }

    void showThrowResults(int playerThrow, int playerTotal,
        int computerThrow, int computerTotal) const {
        cout << "\nВы выбросили: " << playerThrow << " (Всего: " << playerTotal << ")";
        cout << "\nКомпьютер выбросил: " << computerThrow << " (Всего: " << computerTotal << ")";
    }

    void showFinalResults(int playerTotal, int computerTotal) const {
        cout << "\n\n=== ИТОГ ===";
        cout << "\nВаш суммарный счёт: " << playerTotal;
        cout << "\nСчёт компьютера: " << computerTotal;

        if (playerTotal > computerTotal)
            cout << "\nВы победили!";
        else if (playerTotal < computerTotal)
            cout << "\nКомпьютер победил!";
        else
            cout << "\nНичья!";

        cout << "\n\nНажмите Enter чтобы продолжить...";
        cin.ignore();
        cin.get();
    }
};

unique_ptr<IGame> GameFactory::createGame(int choice) {
    switch (choice) {
    case 1: return make_unique<DiceGame>();
    case 2: return make_unique<RockPaperScissors>();
    case 3: return make_unique<DartsGame>();
    default: return nullptr;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));

    auto menu = GameMenu::getInstance();
    menu->showMenu();

    return 0;
}
