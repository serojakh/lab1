#include <iostream>
#include <fstream>

using namespace std;


class Base
{
    public:
    virtual void input() = 0;
    virtual void output() = 0; 
    virtual void save (string& filename) = 0; 
    virtual void load ( string& filename) = 0; 

    ~Base ()
    {

        cout << "Вызвался виртуальный деструктор" << endl;
    }

};


class Poet : public Base
{
    private:
    string fio;
    int date_of_birth;
    int date_of_death;

    public:
    Poet ()
    {
        fio = "";
        date_of_birth = 0;
        date_of_death = 0;
        cout << "Конструктор по умолчанию класса Poet вызван" << endl;
    }

    Poet (string fio, int date_of_birth, int date_of_death) 
    {
        this->fio = fio; 
        this->date_of_birth = date_of_birth; 
        this->date_of_death = date_of_death; 
        cout << "Конструткор с параметрами класса Поет вызван" << endl; 
    }

    Poet (Poet& other) 
    {
        fio = other.fio;
        date_of_birth = other.date_of_birth;
        date_of_death = other.date_of_death;
        cout << "Конструткор копирования класса Поет вызван" << endl; 
    }
    

    virtual ~Poet () 
    {
        cout << "Деструктор класса Поет вызван" << endl;
    };


    void input() //override
    {
        cout << "Введите ФИО поэта: ";
        cin >> fio;

        cout << "Введите год рождения: ";
        cin >> date_of_birth;

        cout << "Введите год смерти (или 0, если поэт жив): ";
        cin >> date_of_death;

        while (date_of_death > date_of_birth) 
        {
            cout << "Дата смерти больше даты рождения! Введите корректную дату: ";
            cin >> date_of_death;
        }
    }

    void output() //override 
    {
        cout << "Фамилия, имя и отчество поэта: " << fio << endl;
        if (date_of_death == 0)
        {
            cout << "Годы жизни поэта: " << date_of_birth << " - " << "настоящее время" << endl;
        }
        else 
        {
            cout << "Годы жизни поэта: " << date_of_birth << " - " << date_of_death << endl;
        }
    }

};



int main ()
{

    return 0;
}