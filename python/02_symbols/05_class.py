'''
class
=================

* self
'''

class Point:  # if python 2 ---> class Point(object):
    def __init__(self, x, y):  # not a real ctor. why?
        self.x = x
        self.y = y

    def method_with_no_arg(self):  # if you remove self --> error
        print("no args!")

    def update(self, x, y):  # do I really need this?
        self.x = x
        self.y = y

    def print(self):  # is this pythonic?
        print("Point", self.x, self.y)

    def equal(self, other):  # is this pythonic?
        return (self.x, self.y) == (other.x, other.y)




























class Point2D:
    """Documention 
    of class Point"""

    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"{self.__class__.__name__}({self.x!r}, {self.y!r})"

    def __eq__(self, other):
        # return self.x == other.x and self.y == other.y
        return (self.x, self.y) == (other.x, other.y)

    def __abs__(self):
        """return absolute value"""
        import math

        return math.hypot(self.x, self.y)
