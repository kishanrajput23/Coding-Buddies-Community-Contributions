from random_password_creator import Password
import argparse

args = argparse.ArgumentParser("Usage: python password_generator.py -c CHARSET -l LENGTH")
args.add_argument('charset')
args.add_argument('-l','--length',default=8)
options = args.parse_args()
print(options.charset)
print(options.length)

password = Password(options.charset,int(options.length))
password.set_the_charset()
password.generate_password()
print("The random password is:",password.get_password())