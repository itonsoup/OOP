
import json

class LineSegment:

    def __init__(self, x1, x2):
        self.x1 = x1
        self.x2 = x2
        if not isinstance(x1, int) and not isinstance(x1, float):
            raise TypeError("Значение должно иметь тип данных int или float")
        if not isinstance(x2, int) and not isinstance(x2, float):
            raise TypeError("Значение должно иметь тип данных int или float")

    def __str__(self):
        return (f'Начальная точка {self.x1},' 
                f' Конечная точка {self.x2}'
                )

    def __add__(self, other):
        if not isinstance(other, LineSegment):
            raise TypeError
        return LineSegment(self.x1 + other.x1, self.x2 + other.x2)

    def __sub__(self, other):
        if not isinstance(other, LineSegment):
            raise TypeError
        return LineSegment(self.x1 - other.x1, self.x2 - other.x2)

    def __mul__(self, other):
        #if not isinstance(other, LineSegment):
            #raise TypeError
        products = [self.x1 * other.x1, self.x1 * other.x2, self.x2 * other.x1, self.x2 * other.x2]
        result_min = min(products)
        result_max = max(products)
        return LineSegment(result_min, result_max)

    def __rmul__(self, other):
        return self.__mul__(other)

    def __truediv__(self, other):
        if not isinstance(other, LineSegment):
            raise TypeError
        products = [self.x1 / other.x1, self.x1 / other.x2, self.x2 / other.x1, self.x2 / other.x2]
        result_min = min(products)
        result_max = max(products)
        return LineSegment(result_min, result_max)

    def from_string(self, value):
        self._str = str(value)
        numbers = self._str.split()
        for i in range(len(numbers)):
            numbers[i] = int(numbers[i])
        s = LineSegment(numbers[0], numbers[1])
        self = s
        return self

    def save(self, fname):
        if not (isinstance(fname, str)):
            raise TypeError("Название файла может быть только string")
        with open("{}.json".format(fname), "w", encoding="utf-8") as seg:
            seg.write(json.dumps(str(self), ensure_ascii=False, indent=4))

    def load(self, fname):
        if not (isinstance(fname, str)):
            raise TypeError("Название файла может быть только string")
        try:
            with open("{}.json".format(fname), encoding="utf-8") as vec:
                linesegment_str = json.loads(seg.read())
                return self.from_string(linesegment_str)
        except Exception as err:
            print("При загрузке файла возникла ошибка {}!".format(err))