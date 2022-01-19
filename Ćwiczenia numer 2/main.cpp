#include <iostream>
#include <string>
#include <vector>
#include <sstream>

auto average_of(std::vector<int> x) {
    double sum = 0;
    for(int i = 0; i<size(x); i++) {
        sum+=x[i];
    }
    double avg = sum / size(x);
    return avg;
}

auto is_palindrome(std::string word) {
    bool is_it = false;
    for(int i = 0; i<word.length(); i++)
    {
        if(word[i] == word[word.length()-1-i]) is_it = true;
        else {
            is_it = false;
            break;
        }
    }

    std::cout << std::boolalpha;
    return is_it;
};

auto filter_palindromes(std::vector<std::string> list) {
    std::vector<std::string> filtered_list = {};
    for(int i = 0; i<size(list); i++) {
        if(is_palindrome(list[i])) {
            filtered_list.push_back(list[i]);
        }
        else continue;
    }
    return filtered_list;
}

auto dot_product(std::vector<int> x, std::vector<int> y) {
    int sum = 0;
    if(std::size(x) == std::size(y)) {
        for(int i = 0; i<std::size(x); i++) {
            sum = sum + (x[i] * y[i]);
        }
        return sum;
    }
    else {
        std::cout << "Vectors are not equal in lenght!";
    }

    return sum;
}

class Student {
    public:
        static auto average_of(std::vector<double> grades) {
            double sum = 0;
            double avg;
            for(int i = 0; i<size(grades); i++)
            {
                sum += grades[i];
            }
            avg = sum/size(grades);
            return avg;
        };
        std::string name;
        std::string surname;
        std::vector<double> grades;
        Student(std::string n, std::string s, std::vector<double> g) {
            name = n;
            surname = s;
            grades = g;
        };
};

auto split(std::string text) {
    std::string temp = "";
    std::vector<std::string> words;
    for(int i = 0;i<text.length(); i++) {
        if(i == text.length()-1) {
            temp.push_back(text[i]);
        }
        if(std::isspace(text[i]) || i == text.length()-1) {
            words.push_back(temp);
            temp = "";
        }
        else temp.push_back(text[i]);
    }
    return words;
}

auto get_best_student(std::vector<Student> list) {
    double best = 0;
    int best_student;
    for(int i = 0; i<size(list); i++) {
        if(list[i].average_of(list[i].grades) >= best) {
            best = list[i].average_of(list[i].grades);
            best_student = i;
        }
    }
    return list[best_student];
}

struct Group {
    std::string nazwa;
    std::vector<Student> studenci;
};

auto add_student_to_group(Student s, Group g) {
    g.studenci.push_back(s);
    std::cout << "Imie nowego studenta w grupie: " << g.studenci[3].name << std::endl;
}

auto contains_all(std::vector<int> v, std::vector<int> v2) {
    std::vector<int>::iterator it;
    bool inf = false;
    if(size(v) < size(v2)) inf = false;
    else {
        for (int i = 0; i < size(v); i++) {
            for (int j = 0; j < size(v2); j++) {
                if (v[i] == v2[j]) {
                    it = v.begin() + i;
                    v.erase(it);
                }
            }
        }
        if (size(v) == 0) inf = true;
    }
    return inf;
}

void letter() {
    std::string line;
    std::vector<std::string> ranges;

    while(std::getline(std::cin, line)) {
        if (line == "stop") break;

        std::vector<std::string> chars = split(line);
        if(size(chars) > 2) {
            std::cout << "Nieprawidlowe parametry!" << std::endl;
            continue;
        }

        if(chars[0].length() != 1 || chars[1].length() !=1) {
            std::cout << "Argumentem musi byc jedna litera!" << std::endl;
            continue;
        }

        char c1 = chars[0][0];
        char c2 = chars[1][0];

        std::stringstream ss;
        if((int)c1 > (int)c2) {
            for(int i = (int)c1; i >= (int)c2; i--) {
                ss << char(i);
            }
        }
        else {
            for(int i = (int)c1; i <= (int)c2; i--) {
                ss << char(i);
            }
        }

        ranges.emplace_back(ss.str());
    }

    for(std::string current : ranges) std::cout << current << std::endl;
}

int main() {
//    ZADANIE 1
    std::cout << "Iloczyn skalarny: " << dot_product({1,2,3}, {1,3,5}) << std::endl;

//    ZADANIE 2
    std::cout << "Srednia arytmetyczna: " << average_of({1,2,3,4,5,6,8,14}) << std::endl;

//    ZADANIE 3
    std::vector<std::string> t = filter_palindromes({"kajak", "oko", "nawigacja", "teatr", "teset"});
    std::cout << "Palindromy: ";
    for(int i = 0; i < size(t); i++) {
        std::cout << t[i] << "; ";
    }
    std::cout << std::endl;

//    ZADANIE 4
    Student student = Student("Kacper", "Tokarzewski", {2,2,2});
    std::cout << "Srednia ocen studenta: " << Student::average_of(student.grades) << " \n";

//    ZADANIE 5
    std::vector<std::string> out_space = split("ala ma kota");
    std::cout << "Slowa bez spacji: ";
    for(int i = 0; i < size(out_space); i++) {
        std::cout << out_space[i] << "; ";
    }
    std::cout << std::endl;

//    ZADANIE 6
    Student s1 = Student("Jan", "Kowalski", {4,4,5,2});
    Student s2 = Student("Maciej", "Radomski", {3,5,3,5});
    Student s3 = Student("Anna", "Topaz", {2,5,5,5});
    std::vector<Student> students = {s1,s2,s3};

    std::cout << "Imie najlepszego studenta: " << get_best_student(students).name << std::endl;

//    ZADANIE 7
    auto const g1 = Group{"Grupa1",{s1,s2,s3}};
    add_student_to_group(s1, g1);

//    ZADANIE 9
    std::cout << "Wektor pierwszy zawiera elementy drugiego: " << contains_all({1,2,3}, {1,2,3}) << std::endl;

//    ZADANIE 10
    letter();

    return 0;
}