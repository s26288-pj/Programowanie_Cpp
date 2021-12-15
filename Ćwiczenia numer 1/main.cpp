#include <iostream>
#include <string>

auto is_divisible(int num, int div)
{
    if(num%div == 0) return 1;
    else return 0;
};

auto is_even(int x)
{
    bool number = false;
    if(is_divisible(x, 2) == 1)
    {
        number = true;
    }
    std::cout << std::boolalpha;
    return number;
};

auto count_chars(std::string word, char letter)
{
    int number_of_chars = 0;
    for(int i = 0; i<=word.length(); i++)
        if(word[i] == char(letter)) number_of_chars++;
    return number_of_chars;
};

auto write_letters(std::string word, int jump)
{
    for(int i = 0; i < word.length(); i++)
        if(i%jump == jump-1) std::cout << word[i] << " ";
    return 0;
};

auto is_palindrome(std::string word)
{
    bool is_it = false;
    if(word.length()%2 == 0)
    {
        for(int i = 0; i<(word.length()/2)-1; i++)
        {
            if(word[i] == word[word.length()-1-i]) is_it = true;
            else is_it = false;
        }
    }
    else
    {
        for(int i = 0; i<word.length()/2; i++)
        {
            if(word[i] == word[word.length()-1-i]) is_it = true;
            else is_it = false;
        }
    }

    std::cout << std::boolalpha;
    std::cout << is_it;
};

auto box_print(std::string word1, std::string word2, std::string word3, std::string word4, std::string word5)
{
    std::string longest = "";
    if(word1.length() > longest.length()) longest = word1;
    if(word2.length() > longest.length()) longest = word2;
    if(word3.length() > longest.length()) longest = word3;
    if(word4.length() > longest.length()) longest = word4;
    if(word5.length() > longest.length()) longest = word5;
    int longest_n = longest.length() +4;

    for(int i=1; i<=longest_n; i++) std::cout << "*";
    std::cout << std::endl << "* " << word1;
    for(int i=(2+word1.length()); i<(longest_n -2); i++) std::cout << ' ';
    std::cout << " *" << std::endl << "* " << word2;
    for(int i=(2+word2.length()); i<(longest_n -2); i++) std::cout << ' ';
    std::cout << " *" << std::endl << "* " << word3;
    for(int i=(2+word3.length()); i<(longest_n -2); i++) std::cout << ' ';
    std::cout << " *" << std::endl << "* " << word4;
    for(int i=(2+word4.length()); i<(longest_n -2); i++) std::cout << ' ';
    std::cout << " *" << std::endl << "* " << word5;
    for(int i=(2+word5.length()); i<(longest_n -2); i++) std::cout << ' ';
    std::cout << " *" << std::endl;
    for(int i=1; i<=longest_n; i++) std::cout << "*";
};

int main() {

//    ZADANIE 1
//    std::cout << "2 3 5 7 11 13 17 19" << std::endl;
//    /std::cout << 2 << ' ' << 3 << ' ' << 5 << ' ' << 7 << ' ' << 11 << ' ' << 13 << ' ' << 17 << ' ' << 19 << std::endl;

//    ZADANIE 2
//    std::string name = "Kacper";
//    double weight = 83.5;
//    int height = 180;
//    std::cout << "Imie: " << name << std::endl << std::endl;
//    std::cout << "Waga: " << weight << " kg \n" << std::endl;
//    std::cout << "Wzrost: " << height << " cm" << std::endl;

//    ZADANIE 3
//    std::string name1 = "";
//    std::string name2 = "";
//
//    std::cout << "Wprowadz pierwsze imie:";
//    std::cin >> name1;
//    std::cout << "Wprowadz drugie imie:";
//    std::cin >> name2;
//
//    if(name1.length() > name2.length())
//    {
//        std::cout << name1 << " jest dluzsze!";
//    }
//    else if(name1.length() == name2.length())
//    {
//        std::cout << name1 << " i " << name2 << " sa tej samej dlugosci.";
//    }
//    else
//    {
//        std::cout << name2 << " jest dluzsze...";
//    }

//    ZADANIE 4
//    int meskie = 0;
//    int zenskie = 0;
//    std::string name1, name2, name3, name4, name5 = "";
//    std::cout << "Write first name:";
//    std::cin >> name1;
//    std::cout << "Write second name:";
//    std::cin >> name2;
//    std::cout << "Write third name:";
//    std::cin >> name3;
//    std::cout << "Write fourth name:";
//    std::cin >> name4;
//    std::cout << "Write fifth name:";
//    std::cin >> name5;
//
//    if(name1[name1.length()-1] == 'a') {zenskie++;}
//    else meskie++;
//    if(name2[name2.length()-1] == 'a') {zenskie++;}
//    else meskie++;
//    if(name3[name3.length()-1] == 'a') {zenskie++;}
//    else meskie++;
//    if(name4[name4.length()-1] == 'a') {zenskie++;}
//    else meskie++;
//    if(name5[name5.length()-1] == 'a') {zenskie++;}
//    else meskie++;
//
//    std::cout << "Number of men names: " << meskie << std::endl;
//    std::cout << "Number of woman names: " << zenskie << std::endl;

//    ZADANIE 5
//
//    std::cout << is_even(7);

//    ZADANIE 6
//
//    std::cout << is_even(8);

//    ZADANIE 7
//
//    std::cout << count_chars("test", 'e');

//    ZADANIE 8
//
//    write_letters("typoweslowobardzodlugie", 3);

//    ZADANIE 9
//
//    is_palindrome("pallap");

//    ZADANIE 10
//
//    box_print("To", "jestests", "test", "funkcji", "box");

    return 0;
}
