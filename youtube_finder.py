import pyautogui as pg
import time
import tkinter
from tkinter import *

def finder():
    text1 = find.get()
    text2 = size.get()
    #print(pg.position())

    pg.moveTo(66, 144, 0.5)
    pg.click(66, 144)
    pg.moveTo(342, 86, 0.5)
    pg.click(342, 86)
    pg.typewrite("youtube.com")
    pg.typewrite(["enter"])
    pg.moveTo(668, 203, 0.5)
    time.sleep(2.5)
    pg.click(669, 203)
    pg.typewrite(text1)
    pg.typewrite(["enter"])
    time.sleep(2.5)
    pg.moveTo(301, 451, 0.5)
    pg.click(301, 451)

    if text2 == "1":
        pg.moveTo(900, 703, 0.5)
        pg.click(900, 703)
    elif text2 == "2":
        pg.moveTo(1178, 853, 0.5)
        pg.click(1178, 853)



root = Tk()
root.title("Youtube founder")
hier = Label(root, text="Hi! I'm gonna find your request on youtube!\nWhat do u want to watch on youtube?")
hier.place(x = 20, y= 0)

find = StringVar()
request_text = Entry(root,textvariable=find, width = 15)
request_text.place(x = 10, y= 70)

screen = Label(root, text="Half screen or all? 1 - half 2 - all")
screen.place(x=20, y = 110)

size = StringVar()
screen_size = Entry(root,textvariable=size, width = 15)
screen_size.place(x = 10, y = 150)

btn = Button(root, text="Search!", command=finder)
btn.place(x = 200, y= 150)




root.geometry('400x250')
root.mainloop()


