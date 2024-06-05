#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct File {
    string name;
    time_t creationDate;
    int accessCount;
};

void printMenu()
{
    cout << "1. Добавить файл в каталог" << endl;
    cout << "2. Вывести каталог файлов" << endl;
    cout << "3. Удалить файлы по дате создания" << endl;
    cout << "4. Выбрать файл с наибольшим количеством обращений" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите действие: ";
}

void addFile(vector<File*>& catalog)
{
    File* newFile = new File;
    cout << "Введите имя файла: ";
    cin >> newFile->name;
    newFile->creationDate = time(nullptr); // Текущая дата и время
    newFile->accessCount = 0;
    catalog.push_back(newFile);
}

void printCatalog(const vector<File*>& catalog)
{
    cout << "Каталог файлов:" << endl;
    for (const auto& file : catalog) {
        cout << "Имя: " << file->name
             << ", Дата создания: " << ctime(&file->creationDate)
             << ", Количество обращений: " << file->accessCount << endl;
    }
}

void deleteFilesByDate(vector<File*>& catalog, time_t thresholdDate)
{
    auto it = catalog.begin();
    while (it != catalog.end()) {
        if ((*it)->creationDate < thresholdDate) {
            delete *it;
            it = catalog.erase(it);
        } else {
            ++it;
        }
    }
}

File* findMostAccessedFile(const vector<File*>& catalog)
{
    if (catalog.empty()) {
        return nullptr;
    }

    File* mostAccessedFile = catalog[0];
    for (const auto& file : catalog) {
        if (file->accessCount > mostAccessedFile->accessCount) {
            mostAccessedFile = file;
        }
    }
    return mostAccessedFile;
}

int main()
{
    vector<File*> catalog;
    int choice;

    do {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addFile(catalog);
            break;
        case 2:
            printCatalog(catalog);
            break;
        case 3: {
            time_t thresholdDate;
            cout << "Введите дату для удаления файлов (в секундах с "
                    "01.01.1970): ";
            cin >> thresholdDate;
            deleteFilesByDate(catalog, thresholdDate);
            break;
        }
        case 4: {
            File* mostAccessedFile = findMostAccessedFile(catalog);
            if (mostAccessedFile) {
                cout << "Файл с наибольшим количеством обращений: "
                     << mostAccessedFile->name << endl;
            } else {
                cout << "Каталог пуст" << endl;
            }
            break;
        }
        case 5:
            cout << "Выход из программы" << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте еще раз." << endl;
        }
    } while (choice != 5);

    // Очистка памяти
    for (auto file : catalog) {
        delete file;
    }
    catalog.clear();

    return 0;
}
