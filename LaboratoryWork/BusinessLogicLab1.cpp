#include "DataLab1.h"
#include "BusinessLogicLab1.h"
#include <fstream>
#include <string>
#include <iostream>

using std::endl;
using std::cout;
using std::string;
using std::fstream;
using std::cin;
using std::getline;
using std::ios;
using std::vector;
using std::swap;
using std::streamsize;
using std::numeric_limits;

void ReadDataFromFile(vector<Virus>& viruses, fstream& file)
{
    viruses.clear();

    string Name;
    double PropagationRate;
    int Type, TargetPlatform, Day, Month, Year;

    while (file >> Name >> Type >> TargetPlatform
        >> PropagationRate >> Day >> Month >> Year)
    {
        Virus virus(Name, static_cast<VirusType>(Type), static_cast<Platform>(TargetPlatform), PropagationRate, Day, Month, Year);

        viruses.push_back(virus);
    }

    if (!file.eof() && file.fail())
    {
        cout << "Read error!" << endl;
        file.clear();
    }
}

void WriteDataInFile(const vector<Virus>& viruses, fstream& file)
{
    for (const Virus virus : viruses)
    {
        file << virus.GetName() << " " << static_cast<int>(virus.GetType()) << " "
            << static_cast<int>(virus.GetTargetPlatform()) << " "
            << virus.GetPropagationRate() << " "
            << virus.GetDayDiscovery() << " "
            << virus.GetMonthDiscovery() << " "
            << virus.GetYearDiscovery() << endl;
    }
}

void PrintVirus(const Virus& virus)
{
    cout << "Name: " << virus.GetName() << endl;
    cout << "Type: " << virus.GetTypeString() << endl;
    cout << "Target platform: " << virus.GetPlatformString() << endl;
    cout << "Propagation rate: " << virus.GetPropagationRate() << endl;
    cout << "Date detection: " << virus.GetDateDiscovery() << endl;
    cout << "----------------------------------------" << endl;
}

void PrintAllViruses(const vector<Virus>& viruses)
{
    if (viruses.empty()) 
    {
        cout << "List of viruses is empty." << endl;
        return;
    };
    int end = viruses.size();
    for (int i = 0; i < end; i++) 
    {
        cout << "Вирус #" << (i + 1) << ":" << endl;
        PrintVirus(viruses[i]);
    }
}

void ClearViruses(vector<Virus>& viruses)
{
    viruses.clear();
    cout << "List of viruses is clear." << endl;
}

int PartitionByYear(vector<Virus>& arr, int low, int high) 
{
    int pivotYear = arr[high].GetYearDiscovery(); // Опорный элемент — год последнего вируса
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++) 
    {
        // Если год текущего вируса >= опорного (сортируем по убыванию!)
        if (arr[j].GetYearDiscovery() >= pivotYear) 
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSortByYear(vector<Virus>& arr, int low, int high) 
{
    if (low < high) 
    {
        int pi = PartitionByYear(arr, low, high);
        QuickSortByYear(arr, low, pi - 1);  // Левая часть
        QuickSortByYear(arr, pi + 1, high); // Правая часть
    }
}

int PartitionByName(vector<Virus>& arr, int low, int high)
{
    string pivotYear = arr[high].GetName(); // Опорный элемент
    int i = low - 1; // Индекс меньшего элемента

    for (int j = low; j <= high - 1; j++)
    {
        // Если имя текущего вируса <= опорного (сортируем по возрастанию!)
        if (arr[j].GetName() <= pivotYear)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSortByName(vector<Virus>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = PartitionByName(arr, low, high);
        QuickSortByName(arr, low, pi - 1);  // Левая часть
        QuickSortByName(arr, pi + 1, high); // Правая часть
    }
}

vector<Virus> SortViruses(const std::vector<Virus>& viruses, int property)
{
    if (viruses.empty() || viruses.size() <= 1)
    {
        cout << "Nothing to sort." << endl;
        return viruses;
    }
    else
    {
        vector<Virus> sorted = viruses;

        switch (property)
        {
        case 1:
        {
            QuickSortByYear(sorted, 0, viruses.size() - 1);
            break;
        }
        case 2:
        {
            QuickSortByName(sorted, 0, viruses.size() - 1);
            break;
        }
        default:
        {
            cout << "Invalid case, try again";
            break;
        }
        }

        return sorted;
    }
}



void StartLab1()
{
    vector<Virus> viruses;
    int choice;
    do
    {
        cout << "\n=== Menu ===\n";
        cout << "1. Read viruses from file\n";
        cout << "2. Write viruses in file\n";
        cout << "3. Sort list\n";
        cout << "4. Clear list\n";
        cout << "5. Print list\n";
        cout << "6. Exit\n";
        cout << "Choose action (1–6): ";

        if (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input number!" << endl;
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
            case 1: 
            {
                string filename;
                cout << "Input filename: ";
                getline(cin, filename);
                fstream file(filename, ios::in);
                if (file.is_open())
                {
                    ReadDataFromFile(viruses, file);
                    file.close();
                    cout << "Data is downloaded from a file " << filename << endl;
                }
                else
                {
                    cout << "Opening error!" << endl;
                }
                break;
            }
            case 2:
            {
                string filename;
                cout << "Input filename: ";
                getline(cin, filename);
                fstream file(filename, ios::out);
                if (file.is_open())
                {
                    WriteDataInFile(viruses, file);
                    file.close();
                    cout << "Data is recorded to file " << filename << endl;
                }
                else
                {
                    cout << "Opening error!" << endl;
                }
                break;
            }
            case 3: 
            {
                cout << "Properties for sort: " << endl;
                cout << "1. Year detection" << endl;
                cout << "2. Name" << endl;
                cout << "Choose property for sort: ";
                int property;
                cin >> property;

                if (property == 1 || property == 2) 
                {
                    viruses = SortViruses(viruses, property);
                    if(!viruses.empty())
                        cout << "Sort is done." << endl;
                }
                else 
                {
                    cout << "Incorrect choice." << endl;
                }

                PrintAllViruses(viruses);

                break;
            }
            case 4: 
            {
                ClearViruses(viruses);
                break;
            }
            case 5: 
            {
                PrintAllViruses(viruses);
                break;
            }
            case 6: 
            {
                cout << "Goodbuy!" << endl;
                break;
            }
            default: 
            {
                cout << "Incorrect choose, try again." << endl;
                break;
            }
        }
    } while (choice != 6);
}