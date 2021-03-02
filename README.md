# Big integer

За основу взят [пост на habr.com](https://habr.com/ru/post/172285/).

Класс для хранения и произведения операций с целыми числами, не вмещающимися в стандартные типы данных.

    class big_integer {
      static const int BASE = 1'000'000'000;
      std::vector<int> _digits;
      bool _is_negative;

Реализация основанна на контейнере из стандартной бибилиотеки *std::vector*. Есть поддержка отрицательных чисел. 

Реализованна перегрузка основных операторов:

    Арифметические операторы: +, -, *, /, %, +=, -=, *=, /=, %=
    Постфиксный и префиксный инкремент и декремент: ++, --
    Операторы сравнения: <, <=, >, >=, ==, !=
    Оператор вывода в поток: <<

Функции, проверяющие число на четность:

    bool odd() const;
    bool even() const;

Функция возведения в степень:

	  const big_integer pow(big_integer) const;

Функция перевода в двоичный вид:

    std::string toBinary() const;
