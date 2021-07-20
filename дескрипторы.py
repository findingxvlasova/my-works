lass ImportantValue:
    def __init__(self, amount):
        self.amount = amount
    
    def __get__(self, obj, obj_type):
        return self.amount
    
    def __set__(self, obj, val):
        with open('log.txt','w') as f:
            f.write(str(val))
            
        self.amount = val
    
    
class Account:
    amount = ImportantValue(100)
    
katias_account = Account()
katias_account.amount = 150   
    
