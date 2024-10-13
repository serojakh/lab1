#include <iostream>
#include <fstream>

using namespace std;


class Base
{
    private:
    string fio;

    public:
    virtual void input() = 0;
    virtual void output(ostream& out) = 0;

    Base ()
    {
        fio = "";
        cout << "Конструктор по умолчанию класса Base вызван" << endl;
    }

    Base (string fio)
    {
        this->fio = fio;
        cout << "Конструктор с параметром класса Base вызван" << endl;
    }

    Base (Base& other)
    {
        fio = other.fio;
        cout << "Конструктор копирования класса Base вызван" << endl;
    }

    string get_fio()
    {
        return fio;
    }

    void set_fio(string fio)
    {
        this->fio = fio;
    }

    virtual ~Base ()
    {

        cout << "Виртуальный деструктор класса Base вызван" << endl;
    }

};


class Poet : public Base
{
    private:
    int date_of_birth;
    int date_of_death;

    public:
    Poet ()
    {
        date_of_birth = 0;
        date_of_death = 0;
        cout << "Конструктор по умолчанию класса Poet вызван" << endl;
    }

    Poet (int date_of_birth, int date_of_death) 
    {
        this->date_of_birth = date_of_birth; 
        this->date_of_death = date_of_death; 
        cout << "Конструткор с параметрами класса Poet вызван" << endl; 
    }

    Poet (Poet& other) 
    {
        date_of_birth = other.date_of_birth;
        date_of_death = other.date_of_death;
        cout << "Конструткор копирования класса Poet вызван" << endl; 
    }
    

    ~Poet () 
    {
        cout << "Деструктор класса Poet вызван" << endl;
    };


    void input()
    {
        string fio;
        cout << "Введите ФИО поэта: ";
        cin.ignore();  
        getline(cin, fio); 
        set_fio(fio); 

        cout << "Введите год рождения: ";
        cin >> date_of_birth;

        cout << "Введите год смерти (или 0, если поэт жив): ";
        cin >> date_of_death;

        if (date_of_death < date_of_birth)
        {
            cout << "Ошибка ввода. Попробуйте еще раз." << endl;
            cout << "Введите год смерти (или 0, если поэт жив): ";
            cin >> date_of_death;
            while (date_of_death < date_of_birth)
            {
                cout << "Ошибка ввода. Попробуйте еще раз." << endl;
                cout << "Введите год смерти (или 0, если поэт жив): ";
                cin >> date_of_death;
            }
        }
    }


    void output(ostream& out)
    {
        out << "Фамилия, имя и отчество поэта: " << get_fio() << endl;
        if (date_of_death == 0)
        {
            out << "Годы жизни поэта: " << date_of_birth << " - " << "настоящее время" << endl;
        }
        else
        {
            out << "Годы жизни поэта: " << date_of_birth << " - " << date_of_death << endl;
        }
    }

};

class Romanist : public Base
{
    private:
    int date_of_birth;
    int date_of_death;
    string biography;

    public:
    Romanist ()
    {
        date_of_birth = 0;
        date_of_death = 0;
        biography = "";
        cout << "Конструктор по умолчанию класса Romanist вызван" << endl;
    }

    Romanist (int date_of_birth, int date_of_death, string biography) 
    {
        this->date_of_birth = date_of_birth; 
        this->date_of_death = date_of_death; 
        this->biography = biography;
        cout << "Конструткор с параметрами класса Romanist вызван" << endl; 
    }

    Romanist (Romanist& other) 
    {
        date_of_birth = other.date_of_birth;
        date_of_death = other.date_of_death;
        biography = other.biography;
        cout << "Конструткор копирования класса Romanist вызван" << endl; 
    }
    

    ~Romanist () 
    {
        cout << "Деструктор класса Romanist вызван" << endl;
    };


    void input()
    {
        string fio;
        cout << "Введите ФИО романиста: ";
        cin.ignore();  
        getline(cin, fio); 
        set_fio(fio); 

        cout << "Введите год рождения: ";
        cin >> date_of_birth;

        cout << "Введите год смерти (или 0, если поэт жив): ";
        cin >> date_of_death;

        if (date_of_death < date_of_birth)
        {
            cout << "Ошибка ввода. Попробуйте еще раз." << endl;
            cout << "Введите год смерти (или 0, если поэт жив): ";
            cin >> date_of_death;
            while (date_of_death < date_of_birth)
            {
                cout << "Ошибка ввода. Попробуйте еще раз." << endl;
                cout << "Введите год смерти (или 0, если поэт жив): ";
                cin >> date_of_death;
            }
        }

        cout << "Введите краткую биографию романиста: ";
        cin.ignore();
        getline(cin, biography);
    }


    void output(ostream& out)
    {
        out << "Фамилия, имя и отчество романиста: " << get_fio() << endl;
        if (date_of_death == 0)
        {
            out << "Годы жизни романиста: " << date_of_birth << " - " << "настоящее время" << endl;
        }
        else
        {
            out << "Годы жизни романиста: " << date_of_birth << " - " << date_of_death << endl;
        }

        out << "Краткая биография: " << biography << endl;
    }

};

class Fantast : public Base
{
    public:
    Fantast ()
    {
        cout << "Конструктор по умолчанию класса Fantast вызван" << endl;
    }

    ~Fantast () 
    {
        cout << "Деструктор класса Fantast вызван" << endl;
    };


    void input()
    {
        string fio;
        cout << "Введите ФИО фантаста: ";
        cin.ignore();  
        getline(cin, fio); 
        set_fio(fio); 

    }


    void output(ostream& out)
    {
        out << "Фамилия, имя и отчество фантаста: " << get_fio() << endl;
    }

};

class Keeper
{
    private:
    Base** items;
    int count;

    public:
    Keeper ()
    {
        items = nullptr;
        count = 0;
        cout << "Конструктор по умолчанию класса Keeper вызван" << endl;
    }

    ~Keeper ()
    {
        for (int i = 0; i < count; i++)
        {
            delete items[i];
        }

        delete [] items;
        cout << "Деструктор класса Keeper вызван" << endl;
    }

    void add (Base* item)
    {
        Base** temp = new Base*[count + 1];
        for (int i = 0; i < count; i++)
        {
            temp[i] = items[i];
        }
        temp[count] = item;
        delete[] items;
        items = temp;
        count ++;
    }

    void remove(int index)
{
    if (index < 0 || index >= count)
    {
        cout << "Введенный индекс некорректен!" << endl;
        return;
    }

    // Создаем новый массив меньшего размера
    Base** temp = new Base*[count - 1];
    
    // Копируем все элементы, кроме удаляемого
    for (int i = 0, j = 0; i < count; i++)
    {
        if (i != index)
        {
            temp[j++] = items[i];
        }
        else
        {
            delete items[i]; // Удаляем элемент
        }
    }
    
    // Освобождаем старый массив и уменьшаем количество элементов
    delete[] items;
    items = temp;
    count--;
}


    void display() 
    {
        if (count == 0)
        {
            cout << "Список пуст" << endl;
        }
        else 
        {
            for (int i = 0; i < count; i++) 
            {
                cout << "Объект " << i + 1 << ":" << endl;
                items[i]->output(cout);
            }
        }
    }

    void saveToFile(const string& filename)
    {
        ofstream file(filename);
    
        if (!file.is_open())
        {
            cout << "Не удалось открыть файл для записи." << endl;
            return;
        }
    
        file << count << endl;

        for (int i = 0; i < count; i++)
        {
            file << "Объект " << i + 1 << ":" << endl;
            items[i]->output(file);
        }

        file.close();
        cout << "Данные сохранены в файл: " << filename << endl;
}
    
};

int main ()
{
    Keeper keeper;
    int choice;

    while (1)
    {
        cout << "---Меню---" << endl;
        cout << "1. Добавить поэта" << endl;
        cout << "2. Добавить романиста" << endl;
        cout << "3. Добавить фантаста" << endl;
        cout << "4. Показать содержимое класса Keeper" << endl;
        cout << "5. Удалить объект из класса Keeper" << endl;
        cout << "6. Сохранить содержимое класса Keeper в файл" << endl;
        cout << "7. лоде" << endl;
        cout << "8. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        
        if (choice == 1)
        {
            Poet* poet = new Poet();
            poet->input();
            keeper.add(poet);
        }

        else if (choice == 2)
        {
            Romanist* romanist = new Romanist();
            romanist->input();
            keeper.add(romanist);
        }

        else if (choice == 3)
        {
            Fantast* fantast = new Fantast();
            fantast->input();
            keeper.add(fantast);
        }

        else if (choice == 4)
        {
            keeper.display();
        }

        else if (choice == 5)
        {
            int index;
            cout << "Введите индекс объекта для удаления: ";
            cin >> index;
            keeper.remove(index - 1);
        }

        else if (choice == 6)
        {
            string filename;
            cout << "Введите имя файла для сохранения: ";
            cin >> filename;
            keeper.saveToFile(filename);
        }

        else if (choice == 8)
        {
            break;
        }
    }

    return 0;
}