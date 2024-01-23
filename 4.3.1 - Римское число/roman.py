# Программирование на языке высокого уровня (Python).
# Задание №______. Вариант !!!
#
# Выполнил: Фамилия И.О.
# Группа: !!!
# E-mail: !!!


class Roman:
    """Класс Roman реализует работу с римскими числами.

    Алгоритм: http://math.hws.edu/eck/cs124/javanotes7/c8/ex3-ans.html.

    Внутри класс работает с обычными арабскими числами (int),
    которые преобразуются в римские при необходимости (например, при выводе).

    Ключевой атрибут: self._arabic (арабское число).

    Ограничения: число должно быть в пределах [1; 3999].
    """

    # Константы класса
    ARABIC_MIN = 1
    ARABIC_MAX = 3999
    ROMAN_MIN = "I"
    ROMAN_MAX = "MMMCMXCIX"

    LETTERS = ["M", "CM", "D", "CD", "C", "XC", "L",
               "XL", "X", "IX", "V", "IV", "I"]
    NUMBERS = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

    def __init__(self, value):
        """Инициализация класса.

        Параметры:
            value (str): римское число, например, X.
                или
            value (int): арабское число, например, 5.
                или
            value (другой тип):  возбудить исключение TypeError.
        """


        if isinstance(value, int):
            self.__check_arabic(value)
            self._arabic = value
        elif isinstance(value, str):
            self._arabic = self.to_arabic(value)

        if not isinstance(value, (int, str)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(value)))

    def __add__(self, other):

        """Создать новый объект как сумму 'self' и 'other'.

        Параметры:
            other (Roman): ...
                или
            other (int): арабское число, добавить к self.
                или
            other (другой тип):  возбудить исключение TypeError.
        """
        add = 0


        if isinstance(other, int):
            add = self._arabic + other
        elif isinstance(other, Roman):
            add = self._arabic + other._arabic
        return Roman.to_roman(add)

        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))

    def __sub__(self, other):
        """Создать новый объект как разность self и other.

        Параметры:
            other (Roman): ...
                или
            other (int): арабское число, добавить к self.
                или
            other (другой тип):  возбудить исключение TypeError.
        """
        sub = 0

        if isinstance(other, int):
            sub = self._arabic - other
        elif isinstance(other, Roman):
            sub = self._arabic - other._arabic
        return Roman.to_roman(sub)

        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))

    def __mul__(self, other):
        """Создать новый объект как произведение self и other.

        Параметры:
            other (Roman): ...
                или
            other (int): арабское число, добавить к self.
                или
            other (другой тип):  возбудить исключение TypeError.
        """
        mul = 0


        if isinstance(other, int):
            mul = self._arabic *+ other
        elif isinstance(other, Roman):
            mul = self._arabic * other._arabic
        return Roman.to_roman(mul)

        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))

    def __floordiv__(self, other):
        """Создать новый объект как частное self и other.

        Параметры:
            other (Roman): ...
                или
            other (int): арабское число, добавить к self.
                или
            other (другой тип):  возбудить исключение TypeError.
        """
        div = 0


        if isinstance(other, int):
            div = self._arabic // other
        elif isinstance(other, Roman):
            div = self._arabic // other._arabic
        return Roman.to_roman(div)

        if not isinstance(other, (Roman, int)):
            raise TypeError("Не могу создать римское число из {0}".
                            format(type(other)))

    def __truediv__(self, other):
        """Создать новый объект как частное self и other.

        Параметры:
            other (Roman): ...
                или
            other (int): арабское число, добавить к self.
                или
            other (другой тип):  возбудить исключение TypeError.
        """
        # Любое деление для римского числа считается делением нацело,
        # поэтому необходимо передать "работу" реализованному методу
        # целочисленного деления
        return self.__floordiv__(other)

    def __str__(self):
        """Вернуть строковое представление класса."""
        return Roman.to_roman(self._arabic)

    @staticmethod
    def __check_arabic(value):
        """Возбудить исключение ValueError, если 'value' не принадлежит
        [ARABIC_MIN; ARABIC_MAX]."""
        if value > Roman.ARABIC_MAX or value < Roman.ARABIC_MIN:
            raise ValueError("Число выходит за пределы диапазона {0}".format(value))

    @staticmethod
    def __check_roman(value):
        """Возбудить исключение ValueError, если 'value' содержит
        недопустимые символы (не входящие в LETTERS)."""
        for letters in value:
            if letters not in Roman.LETTERS:
                raise ValueError("Используется недопустимый символ {0}".format(value))

    @property
    def arabic(self):
        """Вернуть арабское представление числа."""
        return self._arabic


    @staticmethod
    def to_arabic(roman):
        """Преобразовать римское число 'roman' в арабское.

        Параметры:
            roman (str): римское число, например, "X".

        Возвращает:
            int: арабское число.
        """

        def letter_to_number(letter):
            """Вернуть арабское значение римской цифры 'letter'.

            Регистр не учитывается."""

            index = Roman.LETTERS.index(letter)
            return Roman.NUMBERS[index]

        Roman.__check_roman(roman)

        i = 0  # Позиция в строке roman
        value = 0  # Преобразованное число

        while i < len(roman):

            number = letter_to_number(roman[i])

            i += 1

            if i == len(roman):
                # В строке roman больше не осталось символов, добавляем number
                value += number
            else:
                # Если символы остались, необходимо посмотреть на следующий.
                # Если следующий символ "больше", считаем их за одну цифру.
                # Это необходимо, например, для того,
                # чтобы IV преобразовать в 4, а не 15.
                next_number = letter_to_number(roman[i])
                if next_number > number:
                    # Комбинируем цифры и перемещаем i к следующей
                    value += next_number - number
                    i += 1
                else:
                    # Просто добавляем следующую цифру
                    value += number

        Roman.__check_arabic(value)
        return value

    @staticmethod
    def to_roman(arabic):
        """Преобразовать арабское число 'arabic' в римское.

        Параметры:
            arabic (int): арабское число, например, 5.

        Возвращает:
            str: римское число.
        """
        Roman.__check_arabic(arabic)

        roman = ""
        # n - часть arabic, которую осталось преобразовать
        n = arabic

        for i, number in enumerate(Roman.NUMBERS):
            while n >= number:
                roman += Roman.LETTERS[i]
                n -= Roman.NUMBERS[i]

        return roman
