при запуске в терминале указать путь к папке с этой программой


чтобы скомпилировать код впишите в терминал эту команду:
g++ main.cpp tests.cpp input_eq.cpp solve_eq.cpp print_eq.cpp eq_grafic.cpp eq_menu.cpp user_training.cpp -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE

чтобы заупстить программу впишите в терминале:
./a.exe

при компиляции используются
-Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE



все файлы:

main.cpp - меню через argv

eq_menu (....h, ...cpp) - запуск всех сценариев

input_eq (....h, ...cpp) - в нем лежат: структура, функции ввода с клавы и из файла
print_eq (....h, ...cpp) - в нем лежат функции вывода результатов в терминал и записи ответов в файл

solve_eq (....h, ...cpp) - в нем лежит основная функция решения квадратного уравнения

tests (....h, ...cpp) - файл с функцией автоматического тестирования программы

user_training (....h, ...cpp) - файл с функцией, которая предлагает юзеру самому решить квадратное уравнение

eq_grafic (....h, ...cpp) - файл с функцией, которая рисует график пораболы в отдельном файле
