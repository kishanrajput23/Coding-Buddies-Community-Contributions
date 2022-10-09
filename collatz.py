def collatz(n):
    if n%2==0:
        return n//2
    else:
        return 3*n+1

a=int(input("Enter a number: "))
x=collatz(a)
while x>0:
    print(x)
    x=collatz(x)
    if x==1:
        print(1)
        break
