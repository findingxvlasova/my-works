from tkinter import *
import tkinter as tk
import math

t = Tk()

def create_window():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Призма')
    window.geometry('500x500')
#стороны
    Label(window, text="Количество сторон призмы").place(x=10, y=20)
    sides_num = Entry(window, bg='white', font=30)
    sides_num.place(x=10, y=40)
#длинна стороны
    Label(window, text="Длинна сторон призмы").place(x=10, y=120)
    sides_length = Entry(window, bg='white', font=30)
    sides_length.place(x=10, y=140)
#высота
    Label(window, text="Высота призмы").place(x=10, y=220)
    high = Entry(window, bg='white', font=30)
    high.place(x=10, y=240)
#поля для ответов
    Label(window, text="Площадь боковой поверхности").place(x=10, y=380)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=400)
    Label(window, text="Объём").place(x=10, y=430)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=450)

    def proizv():
        num = sides_num.get()
        num = int(num)

        len = sides_length.get()
        len = int(len)

        high1 = high.get()
        high1 = int(high1)

        side_area = str(num * len * high1)
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str((num * (len*len)) / (4 * math.tan(math.pi/num)) * high1)
        vol.delete(0, END)
        vol.insert(0, volume)


    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=320)

def create_window_parallelepiped():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Параллелепипед')
    window.geometry('500x500')

    Label(window, text="Первая сторона основания").place(x=10, y=20)
    first_base_side = Entry(window, bg='white', font=30)
    first_base_side.place(x=10, y=40)

    Label(window, text="Вторая сторона основания").place(x=10, y=120)
    second_base_side = Entry(window, bg='white', font=30)
    second_base_side.place(x=10, y=140)

    Label(window, text="Высота параллелепипеда").place(x=10, y=220)
    high = Entry(window, bg='white', font=30)
    high.place(x=10, y=240)

    Label(window, text="Площадь боковой поверхности").place(x=10, y=380)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=400)
    Label(window, text="Объём").place(x=10, y=430)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=450)

    def proizv():
        first = first_base_side.get()
        first = int(first)

        second = second_base_side.get()
        second = int(second)

        high1 = high.get()
        high1 = int(high1)

        side_area = str((2 * (first + second))* high1)
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str(first * second * high1)
        vol.delete(0, END)
        vol.insert(0, volume)

    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=320)

def create_window_pyramid():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Призма')
    window.geometry('500x500')

    Label(window, text="Количество сторон пирамиды").place(x=10, y=20)
    sides_num = Entry(window, bg='white', font=30)
    sides_num.place(x=10, y=40)

    Label(window, text="Длинна сторон ппирамиды").place(x=10, y=120)
    sides_length = Entry(window, bg='white', font=30)
    sides_length.place(x=10, y=140)

    Label(window, text="Высота пирамиды").place(x=10, y=220)
    high = Entry(window, bg='white', font=30)
    high.place(x=10, y=240)

    Label(window, text="Площадь боковой поверхности").place(x=10, y=380)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=400)

    Label(window, text="Объём").place(x=10, y=430)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=450)

    def proizv():
        num = sides_num.get()
        num = int(num)

        len = sides_length.get()
        len = int(len)

        high1 = high.get()
        high1 = int(high1)

        side_area = str((1/2) * (len * num) * high1)
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str((1/3) * (num * (len * len)) / (4 * math.tan(math.pi / num)) * high1)
        vol.delete(0, END)
        vol.insert(0, volume)

    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=320)

def create_window_cylinder():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Призма')
    window.geometry('500x500')

    Label(window, text="Введите радиус основания").place(x=10, y=20)
    radius = Entry(window, bg='white', font=30)
    radius.place(x=10, y=40)

    Label(window, text="Введите высоту цилиндра").place(x=10, y=120)
    high = Entry(window, bg='white', font=30)
    high.place(x=10, y=140)

    Label(window, text="Площадь боковой поверхности").place(x=10, y=280)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=300)

    Label(window, text="Объём").place(x=10, y=330)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=350)

    def proizv():

        rad = radius.get()
        rad = int(rad)

        high1 = high.get()
        high1 = int(high1)

        side_area = str(2 * math.pi * rad * high1)
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str(math.pi * (rad**2) * high1)
        vol.delete(0, END)
        vol.insert(0, volume)

    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=220)


def create_window_cone():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Призма')
    window.geometry('500x500')

    Label(window, text="Введите радиус основания").place(x=10, y=20)
    radius = Entry(window, bg='white', font=30)
    radius.place(x=10, y=40)

    Label(window, text="Введите образующую").place(x=10, y=120)
    generatrix = Entry(window, bg='white', font=30)
    generatrix.place(x=10, y=140)

    Label(window, text="Высота конуса").place(x=10, y=220)
    high = Entry(window, bg='white', font=30)
    high.place(x=10, y=240)

    Label(window, text="Площадь боковой поверхности").place(x=10, y=380)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=400)

    Label(window, text="Объём").place(x=10, y=430)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=450)

    def proizv():
        rad = radius.get()
        rad = int(rad)

        gen = generatrix.get()
        gen = int(gen)

        high1 = high.get()
        high1 = int(high1)

        side_area = str(math.pi * rad * gen)
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str((1/3) * math.pi * high1 * (rad**2))
        vol.delete(0, END)
        vol.insert(0, volume)

    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=320)

def create_window_ball():
    window = tk.Toplevel(t)
    window['bg'] = "#d7e8ff"
    window.title('Призма')
    window.geometry('500x500')

    Label(window, text="Введите радиус шара").place(x=10, y=20)
    radius = Entry(window, bg='white', font=30)
    radius.place(x=10, y=40)


    Label(window, text="Площадь боковой поверхности").place(x=10, y=180)
    area = Entry(window, width=16, font='Arial 14')
    area.place(x=10, y=200)

    Label(window, text="Объём").place(x=10, y=230)
    vol = Entry(window, width=16, font='Arial 14')
    vol.place(x=10, y=250)

    def proizv():
        rad = radius.get()
        rad = int(rad)

        side_area = str(4 * math.pi * (rad**2))
        area.delete(0, END)
        area.insert(0, side_area)
        volume = str((4/3) * math.pi * (rad**3))
        vol.delete(0, END)
        vol.insert(0, volume)

    but = Button(window, text='Вычислить', command=proizv)
    but.place(x=10, y=120)


t['bg'] = "#d7e8ff"
t.title('Калькулятор')

t.geometry('500x500')

label1 = Label(text="Выбери фигуру", width=15, height=3, fg="black", bg="#ffdbda", font='arial 14')
label1.pack()

btn = Button(t, text='Призма', width=15, height=3, bg='#ffd7db', fg='black', font ='arial 14', command=create_window)
btn.place(x=10, y=120)
btn1 = Button(t, text='Параллелепипед', width=15, height=3, bg='#ffd7db', fg='black', font='arial 14', command=create_window_parallelepiped)
btn1.place(x=10, y=220)
btn2 = Button(t, text='Пирамида', width=15, height=3, bg='#ffd7db', fg='black', font='arial 14', command= create_window_pyramid)
btn2.place(x=10, y=320)
btn3 = Button(t, text='Цилиндр',width=15, height=3, bg='#ffd7db', fg='black', font='arial 14', command=create_window_cylinder)
btn3.place(x=310, y=120)
btn4 = Button(t, text='Конус', width=15, height=3, bg='#ffd7db', fg='black', font='arial 14', command=create_window_cone)
btn4.place(x=310, y=220)
btn5 = Button(t, text='Шар', width=15, height=3, bg='#ffd7db', fg='black', font='arial 14', command=create_window_ball)
btn5.place(x=310, y=320)

t.mainloop()