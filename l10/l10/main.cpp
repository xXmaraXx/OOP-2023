#include <iostream>
#include <map>
#include <functional>
#include <vector>
#include <sstream>
#include <stdexcept>
#include <fstream>

/// <summary>
/// am adaugat un joc de "higher or lower" si "rock paper scissors" :))
/// </summary>
/// 
/// 
/// 
int rule(char p, char c) {
    if (p == c) {
        return 0;
    }

    if (p == 'r' && c == 'p') {
        return -1;
    } else if (p == 's' && c == 'p') {
        return 1;
    } else if (p == 'p' && c == 'r') {
        return 1;
    } else if (p == 's' && c == 'r') {
        return -1;
    } else if (p == 'r' && c == 's') {
        return 1;
    } else if (p == 'p' && c == 's') {
        return -1;
    }
}
///
///
/// 


class FileException : public std::exception {
  private:
    std::string filename;
    std::string message;

  public:
    FileException(const std::string& filename, const std::string& message) : filename(filename), message(message) {}
    
    const char* what() const noexcept override {
        std::ostringstream oss;
        oss << "FileException: " << message << " (" << filename << ")";
        return oss.str().c_str();
    }
};

class CommandManager {
  private:
    std::map<std::string, std::function<void(std::vector<std::string>)>> commands;

  public:
    void add(const std::string& name, std::function<void(std::vector<std::string>)> fn) {
        commands[name] = fn;
    }

    void run() {
        std::string line;
        while (std::getline(std::cin, line)) {
            std::istringstream iss(line);
            std::vector<std::string> args{ 
                std::istream_iterator<std::string>{ iss },
                std::istream_iterator<std::string>{} 
            };

            if (args.empty()) {
                continue;
            }

            const std::string& commandName = args[0];
            if (commandName == "stop") {
                return;
            }

            auto it = commands.find(commandName);
            if (it != commands.end()) {
                try {
                    std::vector<std::string> commandArgs(args.begin() + 1, args.end());
                    it->second(commandArgs);
                } catch (const std::exception& e) {
                    std::cerr << "Exception caught: " << e.what() << std::endl;
                }
            } else {
                std::cerr << "Unknown command: " << commandName << std::endl;
            }
        }
    }
};

int main() {
    CommandManager manager;

    auto ping = [](std::vector<std::string> args) { 
        std::cout << "pong!\n"; 
    };
    manager.add("ping", ping);

    auto count = [](std::vector<std::string> args) { 
        std::cout << "Counted " << args.size() << " args.\n"; 
    };
    manager.add("count", count);

    auto times = [count = 0](std::vector<std::string> args) mutable {
        std::cout << "Times called: " << ++count << "\n";
    };
    manager.add("times", times);

    auto copy = [](std::vector<std::string> args) {
        if (args.size() != 2) {
            std::cerr << "Invalid number of arguments for copy command.\n";
            return;
        }
        const std::string& source = args[0];
        const std::string& destination = args[1];

        try {
            std::ifstream inputFile(source, std::ios::binary);
            if (!inputFile) {
                throw FileException(source, "Failed to open source file.");
            }
            std::ofstream outputFile(destination, std::ios::binary);
            if (!outputFile) {
                throw FileException(destination, "Failed to open destination file.");
            }
            outputFile << inputFile.rdbuf();
            std::cout << "File copied: " << source << " -> " << destination << std::endl;
        } catch (const std::exception& e) {
            throw FileException(source, e.what());
        }
    };
    manager.add("copy", copy);

    auto allocateMemory = [](std::vector<std::string> args) {
        if (args.size() != 1) {
            std::cerr << "Invalid number of arguments for memory command.\n";
            return;
        }
        int size = std::stoi(args[0]);

        try {
            if (size < 0) {
                int* memory = new int[size];
                delete[] memory;
            } else {
                int* memory = new int[size];
                delete[] memory;
            }
            std::cout << "Memory allocated: " << size << " bytes.\n";
        } catch (const std::bad_alloc& e) {
            std::cerr << "Failed to allocate memory: " << e.what() << std::endl;
        }
    };
    manager.add("memory", allocateMemory);

    auto higher_or_lower_game = [](std::vector<std::string> args) { 
        int num, guess, tries = 0;
        srand(time(0));
        num = rand() % 100 + 1;
        std::cout << "Guess the Number Game\n\n";
        do {
            std::cout << "Enter a number between 1 and 100: ";
            std::cin >> guess;
            tries++;

            if (guess > num) {
                std::cout << "Lower!\n\n";
            } else if (guess < num) {
                std::cout << "Higher!\n\n";
            } else {
                std::cout << "Correct! The number was: "<<num
                          << " \nYou got it in " << tries << " guesses !\n ";
            }

        } while (guess != num);

    };
    manager.add("number", higher_or_lower_game);

    auto rock_paper_scissors = [](std::vector<std::string>) {
        char computer;
        char player;
        char playmore;
        std::cout << "\t\t\t\t";
        for (int i = 0; i < 50; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        std::cout << "\t\t\t\t";
        std::cout << "\t Welcome to Rock, Paper and Scissors Game" << std::endl;
        std::cout << "\t\t\t\t";
        for (int i = 0; i < 50; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        std::cout << "\t\t\t\t";
        std::cout << "\t Note: " << std::endl;
        std::cout << "\t\t\t\t";
        std::cout << "\t\t r : Rock" << std::endl
             << "\t\t\t\t"
             << "\t\t p : Paper" << std::endl
             << "\t\t\t\t"
             << "\t\t s : Scissor" << std::endl
             << "\t\t\t\t" << std::endl
             << std::endl;
        std::cout << "\t\t\t\t";
        for (int i = 0; i < 50; i++) {
            std::cout << "-";
        }
        std::cout << std::endl;
        do {
            int number = 0;
            srand(time(0));        
            number = rand() % 100; 
            if (number < 33) {
                computer = 'r';
            } else if (number > 66) {
                computer = 's';
            } else {
                computer = 'p';
            }
            std::cout << "\t\t\t\t";
            std::cout << "Enter your choice: ";
            std::cin >> player;
            int result = rule(player, computer);
            if (result == 1) {
                std::cout << "\t\t\t\t";
                std::cout <<computer<< " You won! Hurray" << std::endl;
            } else if (result == -1) {
                std::cout << "\t\t\t\t";
                std::cout <<computer<<" You lose! Bad Luck" << std::endl;
            } else {
                std::cout << "\t\t\t\t";
                std::cout <<computer<< " Woah! That's Tie!" << std::endl;
            }
            std::cout << "\t\t\t\t";
            std::cout << "Do you want to Play Again?(y/n) " << std::endl;
            std::cout<< "\t\t\t\t";
            std::cout << "Note: Press 'n' to exit! Press 'y' to continue: ";
            std::cin >> playmore;
            std::cout << "\t\t\t\t";
            for (int i = 0; i < 50; i++) {
                std::cout << "-";
            }
            std::cout << std::endl;
        } while (playmore != 'n');
    };
    manager.add("rock", rock_paper_scissors);

    manager.run();

    std::cout << "goodbye." << std::endl;

    return 0;

}