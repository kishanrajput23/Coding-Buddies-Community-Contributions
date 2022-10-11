#python program for RSA asymmetric cryptographic
#algorithm. For demonstration values are
#relatively small compared to practical application

from math import *
from sympy import *

message = int(input("Enter the message to be encrypted: ")) 


p = 11
q = 13
e = 7
k=6

n = p*q
phi = (p-1)*(q-1)

# Checks whether e is valid or not(gcd of e and phi must be 1)
def exp(e):
    while (1 < e) and (e < phi):
        if (gcd(e,phi))==1:
            print(e,"can be used as the exponent")
            break
        else:
            e+=1
    return e

# Checks whether k(constant) is valid or not
def dec(k):
    while (phi*k+1)%e!=0:
            k+=1
    if (phi*k+1)%e==0:
        print(k,"can be used as the constant")
        dn=(phi*k+1)//e
    return dn

ty=int(input("Enter value for k: "))
dn=dec(ty)

expo=int(input("Enter value for e: "))
e=exp(expo)

# encryption c(ciphertxt) = msg^e mod n
def encrypt(me):
    en = Pow(me,e)
    c = en % n
    print("Encrypted Message is: ", c)
    return c

# decryption c^d mod n
def decrypt(dt):
    dec = Pow(dt,dn)
    d = dec % n
    print("Decrypted Message is: ", d)

print("Original Message is: ", message)
c = encrypt(message)
decrypt(c)
