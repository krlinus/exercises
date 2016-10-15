class C1:
    def __func_c1(self):
        print '__func_c1'

    def _func_c1(self):
        print '_func_c1'

class D1(C1):
    def func_d1(self):
        self._func_c1()
        #self.__func_c1()

d = D1()
d.func_d1()
d._func_c1()
c = C1()
#the below doesn't work
#Traceback (most recent call last):
#      File "class1.py", line 17, in <module>
#          c.__func_c1()
#          AttributeError: C1 instance has no attribute '__func_c1'

c.__func_c1()

