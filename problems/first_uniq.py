def first_unique_char(s):
    char_list = list(s)
    positions_dict = {}
    current_position = 0
    l = len(s)
    for c in char_list:
        if c in positions_dict:
            char_list[current_position] = 0
            char_list[positions_dict[c]] = 0
        else:
            positions_dict[c] = current_position
        current_position = current_position + 1
    for c in char_list:
        if c != 0:
            return c
    return None

if __name__=="__main__":
    assert(first_unique_char('abcdea') == 'b')
    assert(first_unique_char('abcde') == 'a')
    assert(first_unique_char('abcbdea') == 'c')
    assert(first_unique_char('dabbecdea') == 'c')
    assert(first_unique_char('quickbrownfoxjumpedoverthelazygreenquills') == 'c')
    assert(first_unique_char('abcdeabcde') == None)
    assert(first_unique_char('') == None)
    assert(first_unique_char('aabbbc') == 'c')
