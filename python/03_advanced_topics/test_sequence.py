from sequence import Sequence

def test_ctor():
    s = Sequence(range(3))
    assert s.l == [0,1,2]

    s = Sequence([4,1,2])
    assert s.l == [4,1,2]

    s = Sequence((1,2,3))
    assert s.l == [1,2,3]

def test_equality():
    s = Sequence(range(3))
    o = Sequence([0,1,2])
    assert s == o
    assert not s != o


def test_repr():
    assert str(Sequence(range(4))) == 'Sequence([0, 1, 2, 3])'


import pytest

@pytest.fixture
def default_sequence():
    return Sequence(range(3))

def test_len(default_sequence):
    assert len(default_sequence) == 3

def test_get(default_sequence):
    assert default_sequence[-1] == 2

def test_set(default_sequence):
    default_sequence[0] = 0.1
    assert default_sequence[0] == pytest.approx(0.09999999999)
    assert default_sequence[0] == pytest.approx(0.09999999999,1e-3)

def test_del(default_sequence):
    assert len(default_sequence) == 3
    del default_sequence[0]
    assert len(default_sequence) == 2
    assert str(default_sequence) == 'Sequence([1, 2])'

def test_insert(default_sequence):
    assert default_sequence.l == [0,1,2]

    default_sequence.insert(0,9)
    assert default_sequence.l == [9,0,1,2]

    default_sequence.insert(1,10)
    assert default_sequence.l == [9,10,0,1,2]

def append(default_sequence):
    assert default_sequence[-1] != 10
    default_sequence.append(10)
    assert default_sequence[-1] == 10
    

def test_iter(default_sequence):
    i = iter(default_sequence)
    assert next(i) == 0
    assert next(i) == 1
    assert next(i) == 2

    ## now we expect an exception
    with pytest.raises(StopIteration):
        next(i)

