from hypothesis import given, assume, strategies as st
from math import hypot
def sdistance(p,q):
    return (p[0]-q[0])**2.0 + (p[1]-q[1])**2.0

@given(
    p=st.tuples(st.floats(),st.floats()),
    q=st.tuples(st.floats(),st.floats()),
)
def test_sdistance(p,q):
    assume(hypot(*p)<1e4)
    assume(hypot(*q) < 1e4)
    sdistance(p,q)

def is_palindrome(string, /):
    """
    returns True if string is palindrome, False otherwise
    """
    # string = string.lower()

    # return string == ''.join(reversed(string))


    return string == string[::-1]

@given(txt=st.text())
def test_palindrome(txt):
    is_palindrome(txt)

def get_most_frequent(sequence, /):
    """
    returns a tuple with the most frequent object in the sequence with the 
    corresponing number
    """
    from collections import Counter
    return tuple() if not sequence else Counter(sequence).most_common(1)[0]

@given(s=st.text())
def test_most_frequent(s):
    get_most_frequent(s)
