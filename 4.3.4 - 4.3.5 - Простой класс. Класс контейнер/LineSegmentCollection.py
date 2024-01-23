from LineSegment import LineSegment
import json
from functools import reduce

class LineSegmentCollection:

    def __init__(self, *lineSegments):
        self.lineSegments = []

        for linesegment in lineSegments:
            self.add(linesegment)

    def __str__(self):
        return reduce(lambda res, x: res + "\n{}".format(x),
                      self.lineSegments,
                      "Список интервалов ({}):".format(len(self.lineSegments)))

    #def __getitem__(self, index):
        #if not (isinstance(index, int)):
            #raise TypeError("index может быть только типа int!")
        #return self.lineSegments[index]



    def add(self, value):
        if not (isinstance(value, LineSegment)):
            raise TypeError("Хранимые экземпляры могут быть только класса LineSegment!")

        self.lineSegments.append(value)

    def remove(self, index):
        if not (isinstance(index, int)):
            raise TypeError("index может быть только типа int!")
        if not (0 <= index <= len(self.lineSegments)):
            raise ValueError("index не входит в диапазон lineSegments")
        del self.lineSegments[index]

    def save(self, fname):
        if not (isinstance(fname, str)):
            raise TypeError("Название файла может быть только string")
        with open("{}.json".format(fname), "w", encoding="utf-8") as seg:
            data = []
            for linesegment in self.lineSegments:
                data.append(str(f"{linesegment.x1} {linesegment.x2}"))
            seg.write(json.dumps(data, ensure_ascii=False, indent=4))

        def load(self, fname):
            if not (isinstance(fname, str)):
                raise TypeError("Название файла может быть только string")

            with open("{}.json".format(fname), encoding="utf-8") as seg:
                list = json.loads(seg.read())
                _vectors = []
                for item in list:
                    print(item)
                    _vectors.append(Vector.from_string(item))

                self.lineSegments = lineSegments
