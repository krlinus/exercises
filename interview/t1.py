import datetime
#from operator import itemgetter
import operator
import itertools

def group_and_sum_dataset(dataset, group_by_key, sum_value_keys):
    keyfunc = operator.itemgetter(group_by_key)
    dataset.sort(key=keyfunc)
    new_dataset = []
    for key, index in itertools.groupby(dataset, keyfunc):
        d = {group_by_key: key}
        d.update({k:sum([item[k] for item in index]) for k in sum_value_keys})
        new_dataset.append(d)
    return new_dataset


my_dataset = [  
    {
        'date': datetime.date(2013, 1, 1),
        'id': 99,
        'value1': 10,
        'value2': 20
    },
    {
        'date': datetime.date(2013, 1, 1),
        'id': 98,
        'value1': 30,
        'value2': 40
    },
    {
        'date': datetime.date(2013, 1, 2),
        'id': 99,
        'value1': 50,
        'value2': 60
    }
]

print group_and_sum_dataset(my_dataset, 'date', ['value1', 'value2'])

