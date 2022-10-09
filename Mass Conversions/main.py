while(True):
    print("""
Mass Conversions     
    Enter 1 to convert Kilograms to Pounds
    Enter 2 to convert Pounds to Kilograms
    Enter 3 to convert Kilograms to Ounces
    Enter 4 to convert Ounces to Kilograms
    Enter 5 to convert Pounds to Ounces
    Enter 6 to convert Ounces to Pounds
    Enter 7 to quit""")

    a = int(input("Enter your choice of conversion: "))
    if a == 1:
        k = float(input("Enter the mass in Kilograms: "))
        p = k * 2.20462
        print("The mass in Pounds is: ", p)
    elif a == 2:
        p = float(input("Enter the mass in Pounds: "))
        k = p / 2.20462
        print("The mass in Kilograms is: ", k)
    elif a == 3:
        k = float(input("Enter the mass in Kilograms: "))
        o = k * 35.274
        print("The mass in Ounces is: ", o)
    elif a == 4:
        o = float(input("Enter the mass in Ounces: "))
        k = o / 35.274
        print("The mass in Kilograms is: ", k)
    elif a == 5:
        p = float(input("Enter the mass in Pounds: "))
        o = p * 16
        print("The mass in Ounces is: ", o)
    elif a == 6:
        o = float(input("Enter the mass in Ounces: "))
        p = o / 16
        print("The mass in Pounds is: ", p)
    elif a == 7:
        break
    else:
        print("Invalid choice")

    