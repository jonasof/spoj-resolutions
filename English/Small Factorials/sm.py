



def main():
    testes = raw_input()
    x = 0
    while(x < int(testes)):
        numero_fatorial = raw_input()
        print fatorial(int(numero_fatorial))
        x = x+1

def fatorial(x):
    if (x > 0):
        return x* (fatorial(x-1))
    else:
        return 1


main()
