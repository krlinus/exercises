def brac_matched(s):
    nb = 0
    for c in s:
        if c == '(':
            nb += 1
        elif c == ')':
            nb -= 1
        if nb < 0:
            return False
    return True if nb == 0 else False

if __name__=="__main__":
    assert(brac_matched("()"))
    assert(brac_matched("(())"))
    assert(brac_matched("()()"))
    assert(brac_matched("(()())"))
    assert(brac_matched("()abc()"))
    assert(brac_matched("(abc)"))
    assert(brac_matched("(") == False)
    assert(brac_matched(")") == False)
    assert(brac_matched(")(") == False)
    assert(brac_matched("(()") == False)
    assert(brac_matched("())") == False)
            
