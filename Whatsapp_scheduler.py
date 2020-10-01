from selenium import webdriver 
from selenium.webdriver.support.ui import WebDriverWait 
from selenium.webdriver.support import expected_conditions as EC 
from selenium.webdriver.common.keys import Keys 
from selenium.webdriver.common.by import By 
import time, datetime

# Replace below path with the absolute path to chromedriver in your computer 
driver = webdriver.Chrome('/mnt/c/Users/Abhishek/Downloads/H4k3RS/chromedriver.exe') 

driver.get("https://web.whatsapp.com/") 
wait = WebDriverWait(driver, 60) 
time.sleep(60)
  
target = '"Saved Messages"'
x_arg = '//span[contains(@title,' + target + ')]'
group_title = wait.until(EC.presence_of_element_located((By.XPATH, x_arg))) 
group_title.click()
print(target + ' identified')
time.sleep(10)

curr_time = datetime.datetime.now()
print('curr_time:', curr_time)
msg_time = datetime.datetime(2020, 7, 27, 4, 30)
print('msg_time:', msg_time)
difference = msg_time - curr_time
diff = difference.seconds
print('Seconds to wait:', diff)
# time.sleep(diff)

f = 600

for i in range(diff/f):
    string = "Still working!"
    input_box = driver.find_element_by_class_name('_2UL8j')
    input_box.send_keys(string)
    button = driver.find_element_by_class_name('_1U1xa')
    button.click()
    time.sleep(f)

time.sleep(diff%f)

target = '"Hunters"'
x_arg = '//span[contains(@title,' + target + ')]'
group_title = wait.until(EC.presence_of_element_located((By.XPATH, x_arg))) 
group_title.click()
print(target + ' identified')
time.sleep(10)

string = "something"
input_box = driver.find_element_by_class_name('_2UL8j')
input_box.send_keys(string)
button = driver.find_element_by_class_name('_1U1xa')
button.click()
time.sleep(300)

string = "!?"
input_box = driver.find_element_by_class_name('_2UL8j')
input_box.send_keys(string)
button = driver.find_element_by_class_name('_1U1xa')
button.click()
time.sleep(10)

string = ":-("
input_box = driver.find_element_by_class_name('_2UL8j')
input_box.send_keys(string)
button = driver.find_element_by_class_name('_1U1xa')
button.click()

# driver.close()
