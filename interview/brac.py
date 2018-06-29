

def bal(s):
    sta=[]
    b_match={'{':'}','[':']','(':')'}
    for c in s:
        if c in ['}',']',')']:
            if len(sta) == 0:
                return False
            if c != b_match[sta.pop()]:
                return False
        elif c in ['[','{','(']:
            sta.append(c)
            
    return True if len(sta) == 0 else False


if __name__=="__main__":
    assert(bal("()"))
    assert(bal("([])"))
    assert(bal("()[]"))
    assert(bal("{()}[]"))
    assert(bal("()[]{}"))
    assert(bal("(abc)"))
    assert(bal("({)}")==False)
    assert(bal("[")==False)
    assert(bal("][")==False)
    assert(bal("()]}")==False)
    assert(bal("{[[]}")==False)
