# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 2
#
# Выполнил: Азовцев Л.И.
# Группа: ПИН-б-о-21-1
# E-mail: itonsoup15@gmail.com

from ПищущаяПринадлежность import ПищущаяПринадлежность

class Карандаш(ПищущаяПринадлежность):
    def __init__(self, name):
        self.name = name

    def write(self):
        print(f"{super().write()} карандашом, ваш текст: {self.name}")