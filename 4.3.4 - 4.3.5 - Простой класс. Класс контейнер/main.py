# Программирование на языке высокого уровня (Python).
# Задание №4.3.4 - 4.3.5. Вариант 1
#
# Выполнил: Азовцев Л.И.
# Группа: ПИН-б-о-21-1
# E-mail: itonsoup15@gmail.com

from LineSegment import LineSegment
from LineSegmentCollection import LineSegmentCollection

if __name__ == '__main__':

    ls1 = LineSegment(3, 10)
    ls2 = LineSegment(5, 7)
    linesegments = LineSegmentCollection(ls1, ls2)

    print("", linesegments)

    print(f'{ls1} + {ls2} = {ls1 + ls2}')
    print(f'{ls1} - {ls2} = {ls1 - ls2}')
    print(f'{ls1} * {ls2} = {ls1 * ls2}')
    print(f'{ls1} / {ls2} = {ls1 / ls2}')

    a = "20 40"
    ls3 = LineSegment(0, 0).from_string(a)
    print(f'\nСоставленный из строки интервал: "{a}" - {ls3}\n')

    linesegments.add(ls3)

    print("", linesegments)

    fname = ("Интервалы")
    ls1.save(fname)
    linesegments.save(fname)

    #print("\n", LineSegmentCollection.__getitem__(linesegments, 0))
    #print("\n", LineSegmentCollection.__getitem__(linesegments, 1))
    #print("\n", LineSegmentCollection.__getitem__(linesegments, 2))




