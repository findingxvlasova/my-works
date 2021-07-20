class User:
    def __init__(self, name, email):
        self.name = name
        self.email = email
        
    def getEmail(self):
        return {
            'name':self.name,
            'email':self.email
        }
    def __str__(self):
        return f"Hello, user {self.name}, your email is {self.email}"
    
    def __hash__(self):
        return hash(self.email)
    
    def __eq__(self, other):
        return self.email == other.email
        
        
        
katia = User("Katia Vlasova", "katiavlasova@example.com")
vasil = User("Vasil Vlasov", "vasil_vlasov@example.com")


print(katia)
print(vasil)

print(katia == vasil)
print(hash(katia))
print(hash(vasil))




class Singleton:
    instance = None
    
    def __new__(cls):
        if cls.instance is None:
            cls.instance = super().__new__(cls)
            
        return cls.instance
    
a = Singleton()
b = Singleton()

a is b





class Researcher:
    def __getattr__(self, name):
        return 'nothing found:()'

    def __getattribute__(self, name):
        print('Looking for {}'.format(name))
        return object.__getattribute__(self.name)


obj = Researcher()

print(obj.fam)







class Ignorant:
    def __setattr__(self, name, value):
        print("not gonna set {}".format(name))


obj = Ignorant()
obj.math = True






class Polite:
    def __delattr__(self, name):
        value = getattr(self,name)
        print('bye')

        object.__delattr__(self, name)


obj  = Polite()
obj.attr = 10
del obj.attr






import random

class NoiseInt:
    def __init__(self, val):
        self.val = val

    def __add__(self, other):
        noise = random.uniform(-1, 1)
        return self.val + other.val + noise

a = NoiseInt(10)
b = NoiseInt(100)

print(a+b)



