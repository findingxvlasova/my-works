class Human:
    def __init__(self, name, age=0):
        self._name = name
        self._age = age
        
    def _say(self, text):
        print(text)
    
    def sayName(self):
        self._say(f"Hello, I am {self._name}.")
        
    def sayHowOld(self):
        self._say(f"I am {self._age} y.o.")
        
        
class Planet:
    def __init__ (self,name, population = None):
        self.name = name
        self.population = population or []
        
    #def addHuman(self, human):
        #print(f"welcome  to {self.name}, {human.name}.")
        #self.population.append(human)
        
earth = Planet('Earth')
katia = Human('Katia')
#earth.addHuman(katia)

katia = Human('Katia', 19)
katia.sayName()
#Hello, I am Katia.



class Human1:
    def __init__(self, name, age=0):
        self.name = name
        self.age = age
        
    
    def getAge(self):
        return self.age
    
    @staticmethod
    def AgeIsValid(age):
        return 18<=age<150
        
katia = Human1("Katia", 19)
katia.AgeIsValid(katia.getAge())

#True





def extractDesc(userString):
    return userString

def extractDate(userString):
    return userString

class Event:
    
    def __init__(self, description, eventDate):
        self.description = description
        self.date = eventDate
        
    def __str__(self):
        return f"Event {self.description} at {self.date}"
    
    @classmethod
    def fromString(cls, userInput):
        desc = extractDesc(userInput)
        date = extractDate(userInput)
        return cls(desc, date)
      
      
from datetime import date

eventDesc = 'Pashas HB.'
eventDate = date.today()

event = Event(eventDesc, eventDate)
print(event)

#Event Pashas HB. at 2021-07-20

event = Event.fromString('домабить в мой календарь пашин день рождения 12 июля')
print(event)
#Event домабить в мой календарь пашин день рождения 12 июля at домабить в мой календарь пашин день рождения 12 июля




class Robot:
    
    def __init__(self, power):
        self.power = power
        
    def sertPower(self, power):
        if power < 0:
            self.power = 0
        else:
            self.power = power
        
        
wall_e = Robot(100)
wall_e.power = -200
print(wall_e.power)
#-200

class Robot:
     def __init__(self, power):
        self._power = power
        
    power = property()
    
    @power.setter
    def power(self, val):
        if val < 0:
            self._power = 0
        else:
            self._powerr = val
    
    @power.getter
    def power(self):
        return self._power
    
    @power.deleter
    def power(self):
        print('male robot useless')
        del self._power
        
        
wall_e = Robot(100)
wall_e.power = -200
print(wall_e.power)

#0
