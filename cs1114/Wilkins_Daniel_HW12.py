'''
Danny Wilkins
CS 1114
ddw284

Reads subway CSV file and prints stops along user specified subway line
'''

def stops(filename, subway_line_input):
    last_stop = None
    subway_dict = {'1':'', '2':'', '3':'', '4':'', '5':'', '6':'', '7':'', 'A':'', 'B':'',\
                    'C':'', 'D':'', 'E':'', 'F':'', 'G':'', 'J':'', 'L':'', 'M':'', 'N':'',\
                    'Q':'', 'R':'', 'S':'', 'Z':''}

    with open(filename, 'r') as f:
        for line in f:
            break
        for line in f:
            l = line.split(',')
            subway_line = l[0][0]
            subway_stop = l[2]

            if(subway_stop != last_stop):
                subway_dict[subway_line] += (subway_stop + ' - ')

            last_stop = subway_stop

        try:
            if(subway_line_input != 'DONE'):
                print(subway_dict[subway_line_input])
        except KeyError:
            print('Stop does not exist, please try again.')

def main():
    subway_csv = 'train stop data-Mac.csv'
    global subway_line_input
    subway_line_input = input('Enter a subway line. Enter "done" when done: ').upper()
    stops(subway_csv, subway_line_input)

main()

while(subway_line_input != 'DONE'):
    main()