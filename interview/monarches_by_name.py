import urllib2
import json

def process():
    response = urllib2.urlopen('http://mysafeinfo.com/api/data?list=englishmonarchs&format=json')
    json_data = json.loads(response.read())
    reorg_data = dict()

    for rec in json_data:
        cty = rec['cty']
        hse = rec['hse']
        nm = rec['nm']
        if cty not in reorg_data.keys():
            reorg_data[cty] = { hse: [nm] }
        else:
            if hse in reorg_data[cty].keys():
                if nm not in reorg_data[cty][hse]:
                    reorg_data[cty][hse].append(nm)
            else:
                reorg_data[cty][hse] = [nm]
    print json.dumps(reorg_data)

if __name__ == '__main__':
    process()


     
