#include <iostream>

using namespace std;

// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// getbanka - название функции не соответствует ее действию -> правильно getIntLength
// Нужна ли нам эта функция вообще
// Максимальное int число 2147483647 -> 10 символов, следовательно мы можем выделить 11 + 3 символов
// 10 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается
// Отсутствует CMake проект
// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);


int getbanka(int num) { // ужасное название функции мне не понятно что она делает
    int lenght = 1;
    if (num < 0) {
        lenght++;
        num = -num;
    }
    while (num >= 10) {
        lenght++;
        num = num / 10;
    }
    return lenght;
}

char *inttoDec(int num) {
    int maxbanka = getbanka(num);
    int num_1 = num;
    /// не корректное название динамичского массива
    char *Ddec = new char[maxbanka + 3];
    int i = maxbanka + 1;
    int abs_num = abs(num_1);
    while (abs_num > 0) {
        Ddec[i] = '0' + abs_num % 10;
        abs_num /= 10;
        i--;
    }
    if (num == 0) {
        Ddec[0] = '0';
        Ddec[1] = 'd';
        Ddec[2] = '0';
    }
    if (num > 0) {
        Ddec[0] = '0';
        Ddec[1] = 'd';
    }
    if (num < 0) {
        Ddec[0] = '-';
        Ddec[1] = '0';
        Ddec[2] = 'd';
    }
    Ddec[maxbanka + 2] = '\0';
    return Ddec;
}

int main() {
    cout << inttoDec(-0) << std::endl;
    return 0;
}
