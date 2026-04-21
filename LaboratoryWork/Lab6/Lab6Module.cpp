#include "Lab6Module.h"
#include "Ex1/getPassword.h"
#include "Ex2/Weapon.h"
#include "Ex2/MainHero.h"


void Lab6Module::StartEx1()
{
    while (true) 
    {
        try 
        {
            std::string password = get_password();
            std::cout << "Пароль принят: " << password << std::endl;
            break;
        }
        catch (const LengthError& e) 
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const RegisterError& e) 
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const DigitError& e) 
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const ForbiddenLetterError& e) 
        {
            std::cerr << "Ошибка: " << e.what() << std::endl;
        }
        catch (const std::exception& e) 
        {
            std::cerr << "Непредвиденная ошибка: " << e.what() << std::endl;
        }
    }
}

void Lab6Module::StartEx2()
{
    // Создаём оружие
    Weapon sword("Меч", 25, 2.0);
    Weapon bow("Лук", 15, 10.0);
    Weapon dagger("Кинжал", 10, 1.5);

    // Создаём персонажей
    MainHero hero(0, 0, "Артур", 100);
    BaseEnemy enemy1(5, 5, &sword, 80);
    BaseEnemy enemy2(15, 15, &bow, 60);
    BaseEnemy enemy3(3, 8, &dagger, 40);

    std::cout << "=== НАЧАЛО БИТВЫ ===\n";
    std::cout << hero << "\n";
    std::cout << enemy1 << "\n";
    std::cout << enemy2 << "\n";
    std::cout << enemy3 << "\n\n";

    // Герой подбирает оружие
    hero.add_weapon(&sword);
    hero.add_weapon(&bow);
    hero.add_weapon(&dagger);

    // Битва с меню взаимодействия
    std::cout << "\n=== БИТВА С МЕНЮ ВЗАИМОДЕЙСТВИЯ ===\n";
    int choice;

    while (hero.is_alive() && (enemy1.is_alive() || enemy2.is_alive() || enemy3.is_alive())) 
    {
        std::cout << "\n--- Меню действий ---\n";
        std::cout << "1. Атаковать врага 1\n";
        std::cout << "2. Атаковать врага 2\n";
        std::cout << "3. Атаковать врага 3\n";
        std::cout << "4. Переместиться\n";
        std::cout << "5. Сменить оружие\n";
        std::cout << "6. Полечиться\n";
        std::cout << "7. Показать состояние\n";
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) 
        {
        case 1:
            if (enemy1.is_alive()) 
            {
                std::cout << "\nАтака врага 1:\n";
                hero.hit(enemy1);
                if (enemy1.is_alive()) 
                {
                    std::cout << "Ответная атака врага 1:\n";
                    enemy1.hit(hero);
                }
                else
                {
                    std::cout << "Враг 1 повержен!\n";
                }
            }
            else 
            {
                std::cout << "Враг 1 уже повержен!\n";
            }
            break;

        case 2:
            if (enemy2.is_alive()) 
            {
                std::cout << "\nАтака врага 2:\n";
                hero.hit(enemy2);
                if (enemy2.is_alive()) 
                {
                    std::cout << "Ответная атака врага 2:\n";
                    enemy2.hit(hero);
                }
                else 
                {
                    std::cout << "Враг 2 повержен!\n";
                }
            }
            else 
            {
                std::cout << "Враг 2 уже повержен!\n";
            }
            break;

        case 3:
            if (enemy3.is_alive()) 
            {
                std::cout << "\nАтака врага 3:\n";
                hero.hit(enemy3);
                if (enemy3.is_alive()) 
                {
                    std::cout << "Ответная атака врага 3:\n";
                    enemy3.hit(hero);
                }
                else 
                {
                    std::cout << "Враг 3 повержен!\n";
                }
            }
            else 
            {
                std::cout << "Враг 3 уже повержен!\n";
            }
            break;

        case 4: 
        {
            double dx, dy;
            std::cout << "Введите смещение по X и Y: ";
            std::cin >> dx >> dy;
            hero.move(dx, dy);
            std::cout << "Герой переместился в позицию ("
                << hero.get_x() << ", " << hero.get_y() << ")\n";
            break;
        }

        case 5:
            hero.next_weapon();
            break;

        case 6: 
        {
            int heal_amount;
            std::cout << "Введите количество здоровья для лечения: ";
            std::cin >> heal_amount;
            hero.heal(heal_amount);
            break;
        }

        case 7:
            std::cout << "\n--- Состояние персонажей ---\n";
            std::cout << hero << ", здоровье: " << (hero.is_alive() ? hero.get_hp() : 0) << "\n";
            std::cout << enemy1 << ", здоровье: " << (enemy1.is_alive() ? std::to_string(enemy1.get_hp()) : "0 (повержен)") << "\n";
            std::cout << enemy2 << ", здоровье: " << (enemy2.is_alive() ? std::to_string(enemy2.get_hp()) : "0 (повержен)") << "\n";
            std::cout << enemy3 << ", здоровье: " << (enemy3.is_alive() ? std::to_string(enemy3.get_hp()) : "0 (повержен)") << "\n";
            break;

        case 0:
            std::cout << "Выход из игры.\n";
            return;

        default:
            std::cout << "Неверный выбор. Попробуйте снова.\n";
            break;
        }
    }

    // Проверка результата битвы
    std::cout << "\n=== РЕЗУЛЬТАТ БИТВЫ ===\n";
    if (hero.is_alive()) 
    {
        std::cout << "Герой победил всех врагов!\n";
    }
    else 
    {
        std::cout << "Герой повержен...\n";
    }
}

void Lab6Module::StartLab()
{
    std::cout << "Start ex 1" << std::endl;
    StartEx1();
    std::cout << "End ex 1" << std::endl;

    std::cout << "Start ex 2" << std::endl;
    StartEx2();
    std::cout << "End ex 2" << std::endl;
}