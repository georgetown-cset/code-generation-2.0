import random

def getMonthlySales():
    return random.randint(0, 100000)

def main():
    quarterly_sales = [0, 0, 0, 0]
    for month in range(1, 13):
        sales = getMonthlySales()
        if month <= 3:
            quarterly_sales[0] += sales
        elif month <= 6:
            quarterly_sales[1] += sales
        elif month <= 9:
            quarterly_sales[2] += sales
        else:
            quarterly_sales[3] += sales

    for i in range(4):
        print(f"The total sales for Quarter {i+1} is {quarterly_sales[i]}.")

if __name__ == "__main__":
    main()