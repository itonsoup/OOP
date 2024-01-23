# Программирование на языке высокого уровня (Python).
# Задание №4.3.6 Вариант 2
#
# Выполнил: Азовцев Л.И.
# Группа: ПИН-б-о-21-1
# E-mail: itonsoup15@gmail.com

from Карандаш import Карандаш
from Ручка import Ручка
from ГелеваяРучка import ГелеваяРучка
import sys

if __name__ == '__main__':

    while True:
        objectSelection = input(f"Выберите, чем хотите начать писать: Ручка - ручкой, Карандаш - карандашом, ГелеваяРучка - гелевой.\nЛибо закройте программу командой Выход \n")
        if objectSelection == 'Ручка':
            print("Вы выбрали писать ручкой")

            while True:
                writer = str(input(f"Напишите любой текст выбранной ручкой: \n"))
                pen = Ручка(writer)
                pen.write()
                yesOrNo = str(input("Вы хотите ввести новый текст или выбрать другое средство письма?\nТекст - ввести новый текст, Выбор - выбрать другое средство письма, Конец - завершить работу программы \n"))
                if yesOrNo == 'Текст': pass
                elif yesOrNo == 'Выбор': break
                elif yesOrNo == 'Конец': sys.exit()
                else:
                    raise TypeError("Вы ввели неккоректную программу")



        elif objectSelection == 'Карандаш':
            print("Вы выбрали писать карандашом")

            while True:
                writer = str(input(f"Напишите любой текст выбранным карандашом: \n"))
                pencil = Карандаш(writer)
                pencil.write()
                yesOrNo = str(input("Вы хотите ввести новый текст или выбрать другое средство письма?\nТекст - ввести новый текст, Выбор - выбрать другое средство письма, Конец - завершить работу программы \n"))
                if yesOrNo == 'Текст': pass
                elif yesOrNo == 'Выбор': break
                elif yesOrNo == 'Конец': sys.exit()
                else:
                    raise TypeError("Вы ввели неккоректную программу")


        elif objectSelection == 'ГелеваяРучка':
            print("Вы выбрали гелевую ручку")

            while True:
                writer = str(input(f"Напишите любой текст выбранной гелевой ручкой: \n"))
                GelPen = ГелеваяРучка(writer)
                GelPen.write()
                yesOrNo = str(input("Вы хотите ввести новый текст или выбрать другое средство письма?\nТекст - ввести новый текст, Выбор - выбрать другое средство письма, Конец - завершить работу программы \n"))
                if yesOrNo == 'Текст': pass
                elif yesOrNo == 'Выбор': break
                elif yesOrNo == 'Конец': sys.exit()
                else:
                    raise TypeError("Вы ввели неккоректную программу")

        elif objectSelection == 'Выход':
            sys.exit()



