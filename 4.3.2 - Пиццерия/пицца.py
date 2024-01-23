# Программирование на языке высокого уровня (Python).
# Задание №______. Вариант !!!
#
# Выполнил: Фамилия И.О.
# Группа: !!!
# E-mail: !!!


class Пицца:
    """Класс Пицца содержит общие атрибуты для пиццы.

    Дочерние классы будут их конкретизировать.
    """

    def __init__(self):
        """Конструктор класса.

        Инициализирует атрибуты пиццы (значения по умолчанию).
        """
        self.название = "Заготовка"
        self.тесто = "тонкое"  # тонкое или пышное
        self.соус = "томатный"  # или другой
        self.начинка = []  # список начинок (по умолчанию - нет)
        self.цена = 0

    def __str__(self):
        """Вернуть информацию о пицце: название, тесто, соус, начинка.

        Формат вывода:

        Пицца: Пепперони | Цена: 350.00 р.
        Тесто: тонкое Соус: томатный
        Начинка: пепперони, сыр моцарелла
        """
        info = (f"Пицца: {self.название} | Цена: {self.цена} р.\nТесто: {self.тесто} Соус: {self.соус} \nНачинка: " + self.начинка)
        return info

    def подготовить(self, пицца):
        """Сообщить о процессе подготовки.

        Формат вывода:

        Начинаю готовить пиццу Пепперони
          - замешиваю тонкое тесто...
          - добавляю соус: томатный...
          - и, конечно: пепперони, сыр моцарелла...
        """

        print(f"Начинаю готовить пиццу {пицца.название}"
              f"\n  - замешиваю {пицца.тесто} тесто..."
              f"\n  - добавляю соус: {пицца.соус}..."
              f"\n  - и, конечно: {пицца.начинка}...")
        self.испечь()
        # Уберите raise и добавьте необходимый код

    def испечь(self):
        """Сообщить о процессе запекания пиццы.

        Формат вывода: произвольное сообщение.
        """
        print("Выпекаю пиццу... Готово!")
        self.нарезать()
        # Уберите raise и добавьте необходимый код

    def нарезать(self):
        """Сообщить о процессе нарезки.

        Формат вывода: произвольное сообщение.
        """
        print("Нарезаю на аппетитные кусочки...")
        self.упаковать()
        # Уберите raise и добавьте необходимый код

    def упаковать(self):
        """Сообщить о процессе упаковки.

        Формат вывода: произвольное сообщение.
        """
        print("Упаковываю в фирменную упаковку и готово!\n")

        # Уберите raise и добавьте необходимый код


class ПиццаПепперони(Пицца):
    """Класс ПиццаПепперони дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = "Пепперони"
        self.цена = 350
        self.соус = "томатный"
        self.тесто = "тонкое"
        self.начинка = "пепперони, сыр моцарелла"


class ПиццаБарбекю(Пицца):
    """Класс ПиццаБарбекю дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = "Барбекю"
        self.цена = 450
        self.соус = "барбекю"
        self.тесто = "тонкое"
        self.начинка = "бекон, ветчина, зелень, сыр моцарелла"


class ПиццаДарыМоря(Пицца):
    """Класс ПиццаДарыМоря дополняет класс Пицца."""

    def __init__(self):
        super().__init__()

        self.название = "Дары моря"
        self.цена = 550
        self.соус = "тар-тар"
        self.тесто = "пышное"
        self.начинка = "кальмары, креветки, мидии, сыр моцарелла"
