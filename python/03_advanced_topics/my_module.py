__all__ = ['my_sum', 'Point']

def my_sum(a,b):
    '''return the sum of two objects
    >>> my_sum(3,5)
    8
    >>> my_sum("a","b")
    'ab'
    >>> my_sum([1,2],[3,4])
    [1, 2, 3, 4]
    '''
    return a+b

class Point:
    '''simple 2D point'''
    def __init__(self,x,y):
        '''costruttore
        
        >>> p = Point(3,4)
        >>> p.x
        3
        >>> p.y
        4
        '''
        self.x = x
        self.y = y

    def __abs__(self):
        '''
        >>> p = Point(3,4)
        >>> abs(p)
        5.0
        '''
        import math
        return math.hypot(self.x,self.y)


import unittest
class Pippo(unittest.TestCase):
    def test_my_sum(self):
        self.assertEqual(my_sum(3,4), 7)

    def test_point_ctor(self):
        p = Point(3,4)
        self.assertEqual(p.x,3)
        self.assertEqual(p.y,4)

    def test_point_abs(self):
        p = Point(3,4)
        self.assertEqual(abs(p),5)

if __name__ == '__main__':
    import doctest
    doctest.testmod()
    unittest.main()
    
    
