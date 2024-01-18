import sys

def main():
    # read the value from the command line
    if len(sys.argv)!=2:
        print ("Provide a number as command line argument")
        return 0
    try:
        value = int(sys.argv[1])
    except ValueError:
        print ("Invalid number provided")
        return 0
    
    # add 1000 to the value
    value += 1000
    
    # print the value
    print("The result is:", value)
    
    return 0

if __name__ == "__main__":
   main()