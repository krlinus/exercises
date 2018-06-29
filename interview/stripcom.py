def stripcomm(s):
    in_q=False
    last_c=None
    r=''
    l = len(s)
    i = 0
    while i < l:
        if s[i] == '"':
            in_q = not in_q
        if in_q:
            r += s[i]
        elif last_c == '/':
            if s[i] == '/':
                while i < l and s[i] != '\n':
                    i += 1
                if i < l:
                    r += '\n'
            else:
                r += last_c
        else:
            if s[i] != '/':
                r += s[i]
        last_c = s[i]
        i += 1

    return r

if __name__=="__main__":
    c_prog1 = '''// this is a comment
{ // another comment
   true, "foo", // 3rd comment
   "http://www.ariba.com" // comment after URL
}
'''
    print stripcomm(c_prog1)
