from ctypes import *

class S(Structure):
    _fields_ = [
        ('a', c_byte),
        ('b', c_int),
        ('c', c_float),
        ('d', c_double)
    ]

lib = CDLL('./test.so')

create_struct = lib.create_struct
create_struct.restype = POINTER(S)
create_struct.argtypes = []

s_ptr = create_struct()
s = s_ptr.contents

print s._fields_[0][0], s.a
print s._fields_[1][0], s.b
print s._fields_[2][0], s.c
print s._fields_[3][0], s.d
print s.__dict__