from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

def func(arg):
  '''
  The caller's copy of arg does not change because
  arg is a native datatype and a copy is made of it
  instead of a reference
  '''
  arg = arg + 2


v = 4
func(v)
print(v)

