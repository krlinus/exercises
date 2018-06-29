

        
def sort_and_print(name_dict):
    by_ln_len={}
    for first_name, last_name in name_dict.items():
        if len(last_name) in by_ln_len:
            by_ln_len[len(last_name)].append(first_name)
            # ^^ it should look like ^^
            #    {2: ['Mary'], 5: ['James', 'Elizabeth'], 6: ['William', 'Thomas']}
        else:
            by_ln_len[len(last_name)] = [first_name]

    for l in sorted(by_ln_len): #go lengthwise, then dictionary-order by firstname for every length
        for fn in sorted(by_ln_len[l]):
            print "%s %s" % (fn, name_dict[fn])

if __name__=="__main__":
    name_dict={"Mary": "Li", "James": "O'Day",  "Thomas": "Miller",
            "William": "Garcia",  "Elizabeth":  "Davis"}
    sort_and_print(name_dict)
