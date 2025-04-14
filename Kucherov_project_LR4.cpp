#include <iostream>
#include <map>
#include <string>
#include <functional>

using namespace std;

//глобальные переменные - стороны прямоугольника
int side1, side2;

//проверка корректности вводимых данных
bool UserInput(string input) {
    //если строка пустая - ввод некорректен
    if (input.empty()) return false;
    //попытаться
    try {
        //преобразование введенного значения в тип int
        int number = stol(input);
        if (number < 0) return false;
    }
    catch (...) //если возникла ошибка в блоке try
    { return false; }
    return true;
    
}

//функция ввода данных
void enterNumber(int& varLink, string label) {
    string str_input;
    cout << label << " = ";
    //ввод значения в текстовом виде
    getline(cin, str_input);
    //пока ввод некорректен
    while (!UserInput(str_input)) {
        cout << label << " = ";
        //ввод значения в текстовом виде
        getline(cin, str_input);
    }
    //присвоение переменной varLink преобразованного в тип int
        //правильно введенного текстового значения
        varLink = stoi(str_input);
    }

    
    void enterSide1()
    {
        enterNumber(side1, "Введите значение A: ");
        cout << "Значение A успешно сохранено: " << side1 << endl;
    }
    
    void enterSide2()
    {
        enterNumber(side2, "Введите значение B: ");
        cout << "Значение B успешно сохранено: " << side2 << endl;    
    }
    
    void calcArea()
    {
        int g1 = side1*side2;
        cout<<"Проиведение А на В равно "<<g1;
    }
    
    void calcPerim()
    {
        cout<<"Деление А на В равно "<<side1 / side2;
    }
    
    //структура меню
    struct MenuItem {
        string title;
        function<void()> action;
    };
    
    int main() {
        map<int, MenuItem> menu = {
            {1, {"Ввод 1-й стороны прямоугольника", enterSide1}},
            {2, {"Ввод 2-й стороны прямоугольника", enterSide2}},
            {3, {"Calculate of Area", calcArea}},
            {4, {"Calculate of Perimetr", calcPerim}},
        };

        int choice = 0;

while (true) {
    cout << "Меню:" << endl;
    for (const auto& item : menu) {
        cout << "Task " << item.first << ". " << item.second.title << endl;
    }
    cout << "0. Выход" << std::endl;
    enterNumber(choice, "Input number of menu: ");
    if (choice == 0) {
        cout << "0 2025 FirstName LastName" << endl;
        break;
    }
    cout << endl;
    if (menu.find(choice) != menu.end()) {
        menu[choice].action();
    } else {
        cout << "Некорректный ввод.";
    }
    cout << endl;
}
return 0;
    }
