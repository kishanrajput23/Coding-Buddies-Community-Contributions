#Insert Operation on Array 


number_array = [4, 5, 2, 7, 9, 13]; 

print("=========== Initial Array =========")

for idex, item in enumerate(number_array):
    print(" Array [", idex , "] ", item)

print("=========== Initial Array =========")


m = 4; # insertion for the 4th position 
new_number = 25; #new number to insert to the initial array
n = len(number_array);# assign the array length 
j = n # define a variable in the size of array length
number_array.append(0) # define new array with inserting a dummy value
n = n + 1; # array length will be increased by one index  

while (j >= m): 
    number_array[j] = number_array[j-1]   #adjust array values with new positions and indexes
    j = j - 1; 

number_array[m] = new_number; # assign the new value to the new array possition

print("========= Updated Array ============")
for i in range(n):
      print(" Array [", i , "] ", number_array[i])
print("========== Updated Array ===========")

# Initial array before insertion:   [4, 5, 2, 7, 9, 13];
# result array after insertion:     [4, 5, 2, 7, 25, 9, 13];
