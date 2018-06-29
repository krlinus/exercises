import urllib2
import json
def embed_in(quote_char, field_data):
    if ' ' in field_data:
        if quote_char in field_data:
            field_data = field_data.replaceall(quote_char, '\\' + quote_char)
        return quote_char + field_data + quote_char
    else:
        return field_data

def get_and_print_english_monarchs_as_json_and_csv(quote_char=None):
    response = urllib2.urlopen('http://mysafeinfo.com/api/data?list=englishmonarchs&format=json')
    json_data = json.loads(response.read())
    with open('/tmp/converter_input.json', 'w') as json_output_fd:
        json_output_fd.write(json.dumps(json_data))

    reorg_data = dict()

    if quote_char == None:
        quote_char = '"'
    with open('/tmp/converter_output.csv', 'w') as csv_output_fd:
        headers_printed=False
        for rec in json_data:
            if not headers_printed:
                csv_output_fd.write(', '.join(rec.keys()))
                headers_printed = True
            csv_output_fd.write('\n')
            first_field=True
            for f in rec.values():
                f = embed_in(quote_char, f)
                if not first_field:
                    f = ',' + f
                first_field = False
                csv_output_fd.write(f);
            csv_output_fd.write('\n')
    print 'Please check output in file /tmp/converter_output.csv'

if __name__ == '__main__':
    get_and_print_english_monarchs_as_json_and_csv()
