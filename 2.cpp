#include <iostream>
#include <string>
#include <map>
#include <random>
#include <ctime>

// Function prototypes
void playWordGuessingGame(const std::map<std::string, std::string>& wordClues);
std::pair<std::string, std::string> getRandomWordWithClue(const std::map<std::string, std::string>& wordClues);
std::string maskWord(const std::string& word, int ch1, int ch2);
bool askForClue();

int main() {
    std::map<std::string, std::string> wordClues = {
        {"about", "On the subject of"},
        {"above", "In a higher position"},
        {"abuse", "Use something to bad effect"},
        {"actor", "Person whose profession is acting"},
        {"acute", "Severe or sharp"},
// Continuing from the existing entries...
{"baker", "One who makes bread"},
{"brave", "Showing courage"},
{"cabin", "A small wooden house"},
{"charm", "The power of delighting"},
{"delta", "A landform at the mouth of a river"},
{"eager", "Wanting to do or have something very much"},
{"earth", "The planet we live on"},
{"fable", "A short story with a moral"},
{"faint", "Lacking brightness"},
{"giant", "A mythical being of human form but superhuman size"},
{"glide", "To move smoothly and continuously"},
{"habit", "A regular practice"},
{"haste", "Excessive speed or urgency"},
{"ideal", "Conception of something in its perfect form"},
{"image", "A representation of the external form of a person or thing"},
{"jolly", "Happy and cheerful"},
{"judge", "A public officer authorized to hear and decide cases in a court"},
{"knack", "A skill or an ability"},
{"kneel", "To fall or rest on the knees"},
{"labor", "Work, especially hard physical work"},
{"latch", "A metal bar with a catch and lever used for fastening a door"},
{"magic", "The power of apparently influencing events by using mysterious forces"},
{"march", "Walk in a military manner with a regular measured tread"},
{"noble", "Belonging to a hereditary class with high social or political status"},
{"novel", "A long written story"},
{"oasis", "A fertile spot in a desert where water is found"},
{"orbit", "The curved path of a celestial object"},
{"panic", "Sudden uncontrollable fear or anxiety"},
{"piano", "A large keyboard musical instrument"},
{"quail", "A small, short-tailed bird"},
{"quart", "A unit of liquid capacity"},
{"radii", "Plural of radius"},
{"ranch", "A large farm for raising horses, beef cattle, or sheep"},
{"saint", "A person acknowledged as holy or virtuous"},
{"scale", "A system or series of marks used for measuring or registering"},
{"train", "A series of connected railway cars or vehicles"},
{"trait", "A distinguishing quality or characteristic"},
{"ultra", "Beyond in degree or quality"},
{"umbra", "The fully shaded inner region of a shadow"},
{"vague", "Of uncertain, indefinite, or unclear character or meaning"},
{"valor", "Great courage in the face of danger"},
{"water", "A transparent, odorless, tasteless liquid"},
{"waxen", "Having a smooth, pale, translucent surface or appearance like that of wax"},
{"xenon", "A chemical element with the symbol Xe"},
{"xylem", "The vascular tissue in plants that conducts water and dissolved nutrients"},
{"yearn", "Have an intense feeling of longing for something"},
{"youth", "The period between childhood and adult age"},
{"zebra", "An African wild horse with black-and-white stripes"},
{"zesty", "Having a strong, pleasant, and somewhat spicy flavor or smell"}

    };

    std::cout << "\n            WORD GUESSING GAME              \n";
    std::cout << "You can quit anytime by entering: quit \n\n";
    
    playWordGuessingGame(wordClues);
    
    return 0;
}

void playWordGuessingGame(const std::map<std::string, std::string>& wordClues) {
    std::mt19937 rng(std::time(nullptr));
    int count = 0;
    std::string guess;

    do {
        auto [word, clue] = getRandomWordWithClue(wordClues);
        std::uniform_int_distribution<> dis(0, word.length() - 1);
        int ch1 = dis(rng);
        int ch2;
        do {
            ch2 = dis(rng);
        } while (ch2 == ch1);

        std::string maskedWord = maskWord(word, ch1, ch2);
        bool guessedCorrectly = false;

        while (!guessedCorrectly) {
            std::cout << "Word:  " << maskedWord << std::endl;
            std::cout << "Enter your word guess: ";
            std::cin >> guess;

            if (guess == "quit") {
                std::cout << "\nYour total correct guesses: " << count << std::endl;
                return;
            }

            if (guess == word) {
                std::cout << "\nYour Guess is correct.\n";
                count++;
                guessedCorrectly = true;
            } else {
                std::cout << "\nYour Guess is Incorrect.\n";
                if (askForClue()) {
                    std::cout << "Clue: " << clue << std::endl;
                }
            }
        }
    } while (true);
}

std::pair<std::string, std::string> getRandomWordWithClue(const std::map<std::string, std::string>& wordClues) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<> dis(0, wordClues.size() - 1);
    auto it = wordClues.begin();
    std::advance(it, dis(rng));
    return {*it};
}

std::string maskWord(const std::string& word, int ch1, int ch2) {
    std::string masked = word;
    masked[ch1] = '*';
    masked[ch2] = '*';
    return masked;
}

bool askForClue() {
    std::string response;
    std::cout << "Would you like to see a clue? (yes/no): ";
    std::cin >> response;
    return response == "yes" || response == "y";
}
