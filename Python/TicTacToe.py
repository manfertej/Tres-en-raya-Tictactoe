
from os import system
system('cls')

ia = 'X'
jugador = 'O'
mInf = -2
MInf = 2

class Tablero:
    
    def __init__(self):
        self.tablero = [ [' ',' ',' '], 
                         [' ',' ',' '], 
                         [' ',' ',' ']  ]
        self.ganador = None
        self.libres = 9
        

    def imprimir(self):
        system("cls")
        print(self.tablero[0][0], "|",self.tablero[0][1], "|",self.tablero[0][2])
        print("---------")
        print(self.tablero[1][0], "|",self.tablero[1][1], "|",self.tablero[1][2])
        print("---------")
        print(self.tablero[2][0], "|",self.tablero[2][1], "|",self.tablero[2][2])


    def actualizar(self):
        
        for i in range(3):
            if ((self.tablero[i][0]==self.tablero[i][1]==self.tablero[i][2] != ' ') or (self.tablero[0][i]==self.tablero[1][i]==self.tablero[2][i] != ' ' )):
                self.ganador = self.tablero[i][i]
                return
            
        if(self.tablero[0][0] == self.tablero[1][1] == self.tablero[2][2] != ' ' or self.tablero[0][2] == self.tablero[1][1] == self.tablero[2][0] != ' '):
            self.ganador = self.tablero[1][1]
            return

        if self.libres == 0:
            self.ganador = ' '
            return


    def valido(self, pos):
        if(self.tablero[pos//3][pos%3] == ' '):
            return True
        else:
            return False


    def marcar(self, pos, ficha):

        if(self.tablero[pos//3][pos%3] == ' '):
            self.tablero[pos//3][pos%3] = ficha
            
            self.libres -= 1

        self.actualizar()   


    def desmarcar(self, pos):
        self.tablero[pos//3][pos%3] = ' '
        self.ganador = None
        self.libres += 1



def iaMov(t:Tablero):
    mejor = mInf
    
    for i in range(3):
        for j in range(3):
            mov = i*3 +j
            if t.valido(mov):
                
                t.marcar(mov, ia)
                resultado = minimax(t,False)
                t.desmarcar(mov)
                
                if(resultado > mejor):
                    mejor = resultado
                    mejorMov = mov

    return mejorMov


def minimax(tab:Tablero, max):
    
    t.actualizar()
    if(t.ganador != None):
        if(t.ganador == jugador):   
            resultado = -1
        if(t.ganador == ia):        
            resultado = 1
        if(t.ganador == ' '):       
            resultado = 0
        
        return resultado


    if(max):
        mejor = mInf
        for i in range(3):
            for j in range(3):
                mov = i*3 +j
                if t.valido(mov):
                    
                    t.marcar(mov, ia)
                    resultado = minimax(t, not max)
                    t.desmarcar(mov)
                    
                    if(resultado > mejor):
                        mejor = resultado

        return mejor
    
    else:
        mejor = MInf
        for i in range(3):
            for j in range(3):
                mov = i*3 +j
                if t.valido(mov):
                    
                    t.marcar(mov, jugador)
                    resultado = minimax(t,not max)
                    t.desmarcar(mov)
                    
                    if(resultado < mejor):
                        mejor = resultado
        return mejor




if __name__ == "__main__":
    
    t = Tablero()

    
    while (t.ganador == None):
        t.imprimir()

        while True:
            mov = int(input("Introduzca un numero del 1 al 9: "))
            
            if t.valido(mov-1):
                break
        t.marcar(mov-1, jugador)

        if(t.ganador != None):
            break

        t.imprimir()
        t.marcar(iaMov(t), ia)
    
    t.imprimir()
    if t.ganador != ' ':
        print("El ganador es: ", t.ganador)
    else:
        print("Empate")

        
