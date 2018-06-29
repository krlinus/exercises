import urllib2
import json

def do_start():
    response = urllib2.urlopen('http://mysafeinfo.com/api/data?list=englishmonarchs&format=json')
    json_data = json.loads(response.read())
    reordered_data = defaultdict(
            c: { h: [n]} for {n, c, h, y} in json_data)
    print json.dumps(reordered_data)


if __name__ == '__main__':
    do_start()

