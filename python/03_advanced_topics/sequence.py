
class Sequence():
    
    def __init__(self, an_iterable): 
        self.l = list(an_iterable)
        
    def __repr__(self):
        return f'{self.__class__.__name__}({self.l!r})'
     
    def __len__(self):
        return len(self.l)
     
    def __eq__(self,other):
        return self.l == other.l
    
    def __getitem__(self,key):
        return self.l[key]
    
    def __setitem__(self,key,item):
        self.l[key] = item
        
    def __delitem__(self,key):
        del self.l[key]
    
    def __iter__(self):
        return iter(self.l)
    
    def insert(self,position,value):
        return self.l.insert(position,value)

    def append(self,value):
        return self.l.append(value)
