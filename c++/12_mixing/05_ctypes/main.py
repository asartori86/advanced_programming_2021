# /usr/bin/env python3

from ctypes import *

dso = CDLL("./libhello.so")  # import shared object on POSIX compatible OS

## functions w/o args
dso.hello()


## strings
dso.repeat.argtypes = [c_char_p]
dso.repeat.restype = c_int
res = dso.repeat(b"ctypes are great")  # use b to pass read-only variable

# use create_string_buffer for a "mutable string"
buf = create_string_buffer(b"this could be modified")
dso.repeat(buf)


## arrays
size = 10
d_array = (c_double * size)()  # better do the allocation on the python side

for i in range(size):
    d_array[i] = i

array_sum = dso.array_sum

array_sum.argtypes = [POINTER(c_double), c_size_t]  # note the use of POINTER
array_sum.restype = c_double

print("the sum of d_array is", array_sum(d_array, size))


## structs
class data(Structure):
    _fields_ = [
        ("i", c_int),
        ("name", c_char_p),
        ("energy", c_double),
    ]  # order is crucial otherwise seg-fault


param = data(name=b"Alberto", energy=99.9, i=42)

# dso.use_by_value.argtypes = [data]
dso.use_by_value(param)  # default is by value

param.i = 77
param.name = b"ciao ciao"

# dso.use_by_reference.argtypes = [POINTER(data)]
# dso.use_by_reference(param)
dso.use_by_reference(byref(param))

dso.set_energy.argtypes = [POINTER(data), c_double]

dso.set_energy(param, 32.45)

dso.use_by_value(param)
