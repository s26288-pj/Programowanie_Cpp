#include <iostream>
#include <String>
#include <vector>
#include <random>

class Card {
public:
    std::string value;
    std::string color;
    bool hidden;
    Card(std::string value, std::string color) {
        this->value = value;
        this->color = color;
        this->hidden = false;
    }
    void toString() {
        if(this->hidden == true) {
            for (int i = 0; i < (value.length() + color.length() + 5); i++) std::cout << "*";
            std::cout << std::endl;
            std::cout << "* ";
            for (int i = 2; i < (value.length() + color.length() + 3); i++) std::cout << "x";
            std::cout << " *\n";
        }
        else {
            for (int i = 0; i < (value.length() + color.length() + 5); i++) std::cout << "*";
            std::cout << "\n* " << value << " " << color << " *\n";
        }
    }
};

auto new_deck() {
    std::vector<std::string> deck;
    std::string colors[] = {"hearts","diamonds","clubs","spades"};
    int deck_place = 0;

    for(int j = 0; j<=3; j++)
    {
        for(int i=2; i<=14;i++)
        {
            std::string x;
            x = std::to_string(i);
            switch(i) {
                case 11 : x = "J";
                    break;
                case 12 : x = "Q";
                    break;
                case 13 : x = "K";
                    break;
                case 14 : x = "A";
                    break;
            }
            std::string color_name = colors[j];
            Card *newCard = new Card(x, color_name);
            newCard->toString();
            deck.push_back(newCard->value + newCard->color);
            deck_place++;
        }
    }
    return deck;
}

void shuffle(std::vector<std::string> & deck) {
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(deck), std::end(deck), rng);
}

int main() {
    std::vector<std::string> deck = new_deck();
    shuffle(deck);
    std::cout << deck[4];
    return 0;
}