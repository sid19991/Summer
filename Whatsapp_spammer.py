from selenium import webdriver 
from selenium.webdriver.support.ui import WebDriverWait 
from selenium.webdriver.support import expected_conditions as EC 
from selenium.webdriver.common.keys import Keys 
from selenium.webdriver.common.by import By 
import time, datetime
import random

# Replace below path with the absolute path to chromedriver in your computer 
driver = webdriver.Chrome('/mnt/c/Users/Abhishek/Downloads/chromedriver.exe') 

driver.get("https://web.whatsapp.com/") 
wait = WebDriverWait(driver, 10) 
time.sleep(60)
  
target = '"DA Ujjval Patel"'
x_arg = '//span[contains(@title,' + target + ')]'
group_title = wait.until(EC.presence_of_element_located((By.XPATH, x_arg))) 
group_title.click()
print(target + ' identified')
time.sleep(10)

curr_time = datetime.datetime.now()
print('curr_time:', curr_time)
msg_time = datetime.datetime(2020, 7, 27, 11, 45) #spam till this time
print('msg_time:', msg_time)
difference = msg_time - curr_time
diff = difference.seconds
print('Seconds to wait:', diff)

f = 10
lstrings = ['Hola', 'Bonjour', 'Zdravstvuyte', 'Nin hao', 'Konnichiwa', 'Ola', 'Asalaam alaikum',
            'Shikamoo', 'Yassas', 'Selamat siang', 'Namaste', 'Merhaba', 'Shalom',
            'Is Ujjval annoyed already!?', 'Mission annoy Ujjval to glory..', 'Figured out what this is??',
            'I am enjoying this too much', 'This isnt done yet^_^', 'touche!:)', 'Messi or Ronaldo?:(', 'Messi is better',
            'Just kidding...', 'Or am i?', 'This is so FUN!', 'Maja aaya?', 'I am sorry:(']


for i in range(diff/f):
    string = lstrings[random.randint(0,len(lstrings)-1)]
    input_box = driver.find_element_by_class_name('_2UL8j')
    input_box.send_keys(string)
    button = driver.find_element_by_class_name('_1U1xa')
    button.click()
    time.sleep(f)
