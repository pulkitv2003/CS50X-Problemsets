import cs50
while True:
    cash = (input("Change owed : "))
    try:
        cash = float(cash)
        if cash > 0:
            coin = round(cash*100)
            coins = 0
            quarters = 0
            dimes = 0
            nickels = 0
            pennies = 0

            quarters = int(coin / 25)
            dimes = int((coin % 25) / 10)
            nickels = int(((coin % 25) % 10) / 5)
            pennies = int((((coin % 25) % 10) % 5) / 1)

            coins += quarters + dimes + nickels + pennies

            print(coins)
            break
    except:
        continue

